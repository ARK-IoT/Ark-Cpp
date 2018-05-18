#include "crypto/ark_crypto.h"
#include "utilities/platform.h"
#include "constants/networks.h"

#include "bitcoin/base58.h"
#include "bitcoin/uint256.h"
#include "bitcoin/crypto/sha256.h"
#include "bitcoin/crypto/ripemd160.h"
#include "bitcoin/utilstrencodings.h"

#include "uECC.h"

#include <vector>
#include <string>
#include <cassert>

namespace ARK {
namespace Crypto {

std::string to_wif(uint8_t version, const std::vector<uint8_t>& key, bool compressed /* = true */) {
	assert(key.size() == PRIVATE_KEY_SIZE); // "private key must be 32 bytes"
	std::vector<uint8_t> buf(compressed ? 34 : 33);
	buf[0] = version;
	for (auto i = 1u; i < 33; ++i) {
		buf[i] = key[i - 1];
	}
	if (compressed) { 
		buf[33] = 0x01;
	}

	return EncodeBase58Check(buf);
}

void from_wif(const std::string& wif, uint8_t& version, std::vector<uint8_t>& priv_key, bool& compressed) {
	std::vector<uint8_t> buf;
	DecodeBase58Check(wif, buf);
	// Uncompressed
	if (buf.size() == 33) {
		version = buf[0];
		priv_key.clear();
		std::copy(buf.cbegin() + 1, buf.cend(), std::back_inserter(priv_key));
		compressed = false;
		return;
	}
	
	// Compressed
	assert(buf.size() == 34);
	assert(buf[33] == 0x01);
	
	version = buf[0];
	priv_key.clear();
	std::copy(buf.cbegin() + 1, buf.cend() - 1, std::back_inserter(priv_key));
	compressed = true;
}

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key) {
	CRIPEMD160 ripemd160;
	ripemd160.Write(&public_key[0], public_key.size());
	std::vector<uint8_t> seed(21);
	seed[0] = network;
	ripemd160.Finalize(&seed[1]);
	return EncodeBase58Check(seed);
}

void get_keys(const char* const passphrase, std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed /* = true */) {
	get_private_key(passphrase, priv_key);
	get_public_key(priv_key, pub_key, compressed);
}

void get_private_key(const char* const passphrase, std::vector<uint8_t>& priv_key) {
	CSHA256 sha256;
	sha256.Write(reinterpret_cast<const unsigned char*>(passphrase), std::strlen(passphrase));
	uint8_t hash[CSHA256::OUTPUT_SIZE] = {};
	sha256.Finalize(hash);
	std::memcpy(&priv_key[0], hash, priv_key.size());
}

void get_public_key(const std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed /* = true */) {
	const struct uECC_Curve_t * curve = uECC_secp256k1();
	uint8_t pub[64] = {};
	// TODO: using the current uECC implementation, a private key value of "1" will return a false negative.  
	// It appears to be not supported given the following issue: https://github.com/kmackay/micro-ecc/issues/128
	assert(uECC_compute_public_key(&priv_key[0], pub, curve) != 0);
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
	std::vector<uint8_t> priv_key(PRIVATE_KEY_SIZE);
	std::vector<uint8_t> pub_key(COMPRESSED_PUBLIC_KEY_SIZE);
	get_keys(passphrase, priv_key, pub_key);
	const auto address = get_address(network, pub_key);

	return Account(HexStr(pub_key).c_str(), address.c_str());
}

}
}
