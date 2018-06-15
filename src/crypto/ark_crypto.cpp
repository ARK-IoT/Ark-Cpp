#include "crypto/ark_crypto.h"

#include "constants/constants.h"
#include "crypto/rfc6979.h"
#include "crypto/util.h"
#include "utilities/platform.h"
#include "constants/networks.h"
#include "models/transaction.h"

#include "Base58Check.hpp"
#include "Uint256.hpp"
#include "Sha256.hpp"
#include "Sha256Hash.hpp"
#include "Ripemd160.hpp"
#include "Ecdsa.hpp"
#include "uECC.h"


#include <vector>
#include <string>
#include <cassert>

namespace ARK {
namespace Crypto {

std::string to_wif(uint8_t version, const uint8_t key[PRIVATE_KEY_SIZE], bool compressed /* = true */) {
	std::string s(53, '\0');
	Base58Check::privateKeyToBase58Check(Uint256(HexStr(key, key + PRIVATE_KEY_SIZE).c_str()), version, compressed, &s[0]);
	return s;
}

void from_wif(const std::string& wif, uint8_t& version, uint8_t priv_key[PRIVATE_KEY_SIZE], bool& compressed) {
	Uint256 bi;
	auto ret = Base58Check::privateKeyFromBase58Check(wif.c_str(), bi, &version, compressed);
	assert(ret);
	bi.getBigEndianBytes(priv_key);
}

std::vector<uint8_t>& convert_to_der_buffer(std::vector<uint8_t>& buffer) {
	// if the sign bit is set, pad with a 0x00 byte
	if (buffer.size() > 1 && (buffer[0] & 0x80) != 0) {
		buffer.insert(buffer.begin(), 0x00);
	}
	return buffer;
}

void toDER(uint8_t packed_signature[PRIVATE_KEY_SIZE * 2], std::vector<uint8_t>& signature) {
	std::vector<uint8_t> r(PRIVATE_KEY_SIZE);
	std::vector<uint8_t> s(PRIVATE_KEY_SIZE);

	std::memcpy(&r[0], packed_signature, PRIVATE_KEY_SIZE);
	std::memcpy(&s[0], packed_signature + PRIVATE_KEY_SIZE, PRIVATE_KEY_SIZE);
	toDER(convert_to_der_buffer(r), convert_to_der_buffer(s), signature);
}

void toDER(const std::vector<uint8_t>& r, const std::vector<uint8_t>& s, std::vector<uint8_t>& signature) {
	// Adapted from https://github.com/bitcoinjs/bip66/blob/master/index.js
	auto lenR = r.size();
	auto lenS = s.size();
	assert(lenR != 0); // must be non zero
	assert(lenS != 0);
	assert(lenR <= 33); // must be less than 34 bytes
	assert(lenS <= 33);
	assert((r[0] & 0x80) == 0); // must not be negative
	assert((s[0] & 0x80) == 0);
	assert(lenR == 1 || r[0] != 0x00 || (r[1] & 0x80) != 0); //must have zero pad for negative number
	assert(lenR == 1 || s[0] != 0x00 || (s[1] & 0x80) != 0);
	
	auto it = r.begin();
	while (lenR > 1 && *it == 0 && *(it + 1) < 0x80) { --lenR; ++it; }
	it = s.begin();
    while (lenS > 1 && *it == 0 && *(it + 1) < 0x80) { --lenS; ++it; }

	signature.clear();
	signature.reserve(6 + lenR + lenS);

	// 0x30 [total-length] 0x02 [R-length] [R] 0x02 [S-length] [S]
	signature.push_back(0x30); // [0]
	signature.push_back(static_cast<uint8_t>(6 + lenR + lenS - 2)); // [1]
	signature.push_back(0x02); // [2]
	signature.push_back(static_cast<uint8_t>(lenR)); // [3]
	signature.insert(signature.end(), r.begin(), r.end());  //[4]
	signature.push_back(0x02); // [4 + lenR]
	signature.push_back(static_cast<uint8_t>(lenS)); // [5 + lenR]
	signature.insert(signature.end(), s.begin(), s.end());  //[6 + lenR]
}

void sign(const Sha256Hash& hash, const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& signature) {
	Uint256 r;
	Uint256 s;	
	uint8_t nonce32[32] = {};
	nonce_function_rfc6979(nonce32, hash.value, priv_key, nullptr, nullptr, 0);
	auto ret = Ecdsa::sign(Uint256(priv_key), hash, Uint256(nonce32), r, s);
	assert(ret);
	std::vector<uint8_t> r_der(PRIVATE_KEY_SIZE);
	r.getBigEndianBytes(&r_der[0]);
	std::vector<uint8_t> s_der(PRIVATE_KEY_SIZE);
	s.getBigEndianBytes(&s_der[0]);
	toDER(convert_to_der_buffer(r_der), convert_to_der_buffer(s_der), signature);
}

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key) {
	std::vector<uint8_t> seed(Ripemd160::HASH_LEN);
	Ripemd160::getHash(&public_key[0], public_key.size(), &seed[0]);
	std::string s(35, '\0');
	Base58Check::pubkeyHashToBase58Check(&seed[0], network, &s[0]);
	return s;
}

bool validate_address(const char* const address, uint8_t network) {
	std::uint8_t pub_key_hash[Ripemd160::HASH_LEN + 1] = {};
	uint8_t version = 0;;
	Base58Check::pubkeyHashFromBase58Check(address, pub_key_hash, &version);
	return version == network;
}

void get_keys(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed /* = true */) {
	get_private_key(passphrase, priv_key);
	get_public_key(priv_key, pub_key, compressed);
}

void get_private_key(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE]) {
	auto hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(passphrase), std::strlen(passphrase));
	std::memcpy(&priv_key[0], hash.value, PRIVATE_KEY_SIZE);
}

void get_public_key(const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed /* = true */) {
	const struct uECC_Curve_t * curve = uECC_secp256k1();
	uint8_t pub[64] = {};
	// TODO: using the current uECC implementation, a private key value of "1" will return a false negative.  
	// It appears to be not supported given the following issue: https://github.com/kmackay/micro-ecc/issues/128
	auto ret = uECC_compute_public_key(&priv_key[0], pub, curve);  // Don't check the return inline with the assert.  MSVC optimizer does bad things.
	assert(ret != 0);
	if (compressed) {
		assert(pub_key.size() == COMPRESSED_PUBLIC_KEY_SIZE);
		uECC_compress(pub, &pub_key[0], curve);
	}
	else {
		assert(pub_key.size() == PUBLIC_KEY_SIZE);
		// Add the 0x04 prefix since the framework doesn't do it for us
		// see: https://github.com/kmackay/micro-ecc#point-representation
		pub_key[0] = 0x04;
		std::memcpy(&pub_key[1], pub, PUBLIC_KEY_SIZE - 1);
	}
}

Account create_account(uint8_t network, const char* const passphrase) {
	uint8_t priv_key[PRIVATE_KEY_SIZE] = {};
	std::vector<uint8_t> pub_key(COMPRESSED_PUBLIC_KEY_SIZE);
	get_keys(passphrase, priv_key, pub_key);
	const auto address = get_address(network, pub_key);

	return Account(HexStr(pub_key).c_str(), address.c_str());
}

ARK::Transaction create_transaction(
	uint8_t network, 
	const char* const address, 
	double amount, 
	const std::string& vendor_field, 
	uint8_t secret[PRIVATE_KEY_SIZE], 
	uint8_t second_secret[PRIVATE_KEY_SIZE] /* = nullptr*/, 
	uint32_t version /* = 1 */, 
	uint64_t fee_override /* = ARK::send_fee */
) {
	assert(validate_address(address, network));
	assert(amount != 0.0);
	assert(secret != nullptr);
	assert(vendor_field.size() <= 64);

	ARK::Transaction transaction;

	transaction.sign(secret);

	if (second_secret != nullptr) {
		transaction.second_sign(second_secret);
	}

	transaction.generate_id();
	return transaction;

	/*
	https://github.com/ArkEcosystem/ark-js/blob/master/lib/transactions/transaction.js
	if (!recipientId || !amount || !secret) return false;

  if(!crypto.validateAddress(recipientId, version)){
    throw new Error("Wrong recipientId");
	}

	var keys = secret;

	if (!crypto.isECPair(secret)) {
		keys = crypto.getKeys(secret);
	}

  if (!keys.publicKey) {
    throw new Error("Invalid public key");
	}

	if (feeOverride && !Number.isInteger(feeOverride)) {
		throw new Error('Not a valid fee')
	}

	var transaction = {
		type: 0,
		amount: amount,
		fee: feeOverride || constants.fees.send,
		recipientId: recipientId,
		timestamp: slots.getTime(),
		asset: {}
	};

  if(vendorField){
    transaction.vendorField=vendorField;
    if(transaction.vendorField.length > 64){
			return null;
		}
  }

	transaction.senderPublicKey = keys.publicKey;

	crypto.sign(transaction, keys);

	if (secondSecret) {
		var secondKeys = secondSecret;
		if (!crypto.isECPair(secondSecret)) {
			secondKeys = crypto.getKeys(secondSecret);
		}
		crypto.secondSign(transaction, secondKeys);
	}

	transaction.id = crypto.getId(transaction);
	return transaction;
	*/
}

}
}
