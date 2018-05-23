#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "models/account.h"

#include <string>
#include <vector>

namespace ARK {
namespace Crypto {

const auto PUBLIC_KEY_SIZE = 65u;
const auto COMPRESSED_PUBLIC_KEY_SIZE = 33u;
const auto PRIVATE_KEY_SIZE = 32u;

void get_keys(const char* const passphrase, std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed = true);
void get_private_key(const char* const passphrase, std::vector<uint8_t>& priv_key);
void get_public_key(const std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed = true);
std::string to_wif(uint8_t version, const uint8_t key[PRIVATE_KEY_SIZE], bool compressed = true);
void from_wif(const std::string& wif, uint8_t& version, uint8_t priv_key[PRIVATE_KEY_SIZE], bool& compressed);

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);

Account create_account(uint8_t network, const char* const passphrase);

}
}

template<typename T>
std::string HexStr(const T itbegin, const T itend, bool fSpaces = false)
{
	std::string rv;
	static const char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	rv.reserve((itend - itbegin) * 3);
	for (T it = itbegin; it < itend; ++it)
	{
		unsigned char val = (unsigned char)(*it);
		if (fSpaces && it != itbegin)
			rv.push_back(' ');
		rv.push_back(hexmap[val >> 4]);
		rv.push_back(hexmap[val & 15]);
	}

	return rv;
}

template<typename T>
inline std::string HexStr(const T& vch, bool fSpaces = false)
{
	return HexStr(vch.begin(), vch.end(), fSpaces);
}

std::vector<unsigned char> ParseHex(const char* psz);
std::vector<unsigned char> ParseHex(const std::string& str);
#endif
