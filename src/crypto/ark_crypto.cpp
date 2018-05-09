#include "crypto/ark_crypto.h"
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

std::string get_wif(uint8_t wif, const std::vector<uint8_t>& key, bool compressed /* = true */) {
	assert(key.size() == 32); // "private key must be 32 bytes"
	std::vector<uint8_t> buf(compressed ? 34 : 33);
	buf[0] = wif;
	for (auto i = 1u; i < 33; ++i) {
		buf[i] = key[i - 1];
	}
	if (compressed) { 
		buf[33] = 0x01;
	}

	return EncodeBase58Check(buf);
}

std::string get_address(uint8_t network, const std::string& public_key) {
	return get_address(network, ParseHex(public_key));
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
	CSHA256 sha256;
	sha256.Write(reinterpret_cast<const unsigned char*>(passphrase), std::strlen(passphrase));
	uint8_t hash[CSHA256::OUTPUT_SIZE] = {};
	sha256.Finalize(hash);

	const struct uECC_Curve_t * curve = uECC_secp256k1();
	uint8_t pub[64] = {};
	uECC_compute_public_key(hash, pub, curve);
	uECC_compress(pub, &pub_key[0], curve);
}

Account create_account(uint8_t network, const char* const passphrase) {
	std::vector<uint8_t> priv_key(32);
	std::vector<uint8_t> pub_key(33);
	get_keys(passphrase, priv_key, pub_key);
	const auto address = get_address(network, pub_key);

	return Account(HexStr(pub_key).c_str(), address.c_str());
}

}
}
