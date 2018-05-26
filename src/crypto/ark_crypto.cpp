#include "crypto/ark_crypto.h"
#include "utilities/platform.h"
#include "constants/networks.h"

#include "Base58Check.hpp"
#include "Uint256.hpp"
#include "Sha256.hpp"
#include "Sha256hash.hpp"
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
	Base58Check::privateKeyToBase58Check(version, compressed, Uint256(HexStr(key, key + PRIVATE_KEY_SIZE).c_str()), &s[0]);
	return s;
}

void from_wif(const std::string& wif, uint8_t& version, uint8_t priv_key[PRIVATE_KEY_SIZE], bool& compressed) {
	Uint256 bi;
	auto ret = Base58Check::privateKeyFromBase58Check(wif.c_str(), bi, version, compressed);
	assert(ret);
	bi.getBigEndianBytes(priv_key);
}

void toDER(const Uint256& r, const Uint256& s, uint8_t signature[70]) {
//https://github.com/bitcoinjs/bip66/blob/master/index.js

  // 0x30 [total-length] 0x02 [R-length] [R] 0x02 [S-length] [S]
  signature[0] = 0x30;
  signature[1] = 70 - 2;
  signature[2] = 0x02;
  signature[3] = 32;
  r.getBigEndianBytes(&signature[4]);
  //r.copy(signature, 4)
  signature[4 + 32] = 0x02;
  //signature[4 + lenR] = 0x02
  signature[5 + 32] = 32;
  //signature[5 + lenR] = s.length
  s.getBigEndianBytes(&signature[6 + 32]);
  //s.copy(signature, 6 + lenR)
}

void sign(const Sha256Hash& hash, const uint8_t priv_key[PRIVATE_KEY_SIZE], uint8_t signature[70]) {
	Uint256 r;
	Uint256 s;	
	auto ret = Ecdsa::signWithHmacNonce(Uint256(priv_key), hash, r, s);
	assert(ret);
	toDER(r, s, signature);
}

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key) {
	std::vector<uint8_t> seed(Ripemd160::HASH_LEN);
	Ripemd160::getHash(&public_key[0], public_key.size(), &seed[0]);
	std::string s(35, '\0');
	Base58Check::pubkeyHashToBase58Check(network, &seed[0], &s[0]);
	return s;
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

}
}


const signed char p_util_hexdigit[256] =
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
0,1,2,3,4,5,6,7,8,9,-1,-1,-1,-1,-1,-1,
-1,0xa,0xb,0xc,0xd,0xe,0xf,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,0xa,0xb,0xc,0xd,0xe,0xf,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, };

signed char HexDigit(char c)
{
	return p_util_hexdigit[(unsigned char)c];
}

std::vector<unsigned char> ParseHex(const char* psz)
{
	// convert hex dump to vector
	std::vector<unsigned char> vch;
	while (true)
	{
		while (isspace(*psz))
			psz++;
		signed char c = HexDigit(*psz++);
		if (c == (signed char)-1)
			break;
		unsigned char n = (c << 4);
		c = HexDigit(*psz++);
		if (c == (signed char)-1)
			break;
		n |= c;
		vch.push_back(n);
	}
	return vch;
}

std::vector<unsigned char> ParseHex(const std::string& str)
{
	return ParseHex(str.c_str());
}