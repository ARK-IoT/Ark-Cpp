#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "constants/constants.h"
#include "models/account.h"
#include "models/transaction.h"
#include "Uint256.hpp"
#include "Sha256Hash.hpp"

#include <string>
#include <vector>

namespace ARK {
namespace Crypto {

const auto PUBLIC_KEY_SIZE = 65u;
const auto COMPRESSED_PUBLIC_KEY_SIZE = 33u;
const auto PRIVATE_KEY_SIZE = 32u;

void get_keys(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed = true);
void get_private_key(const char* const passphrase, uint8_t priv_key[PRIVATE_KEY_SIZE]);
void get_public_key(const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& pub_key, bool compressed = true);
std::string to_wif(uint8_t version, const uint8_t key[PRIVATE_KEY_SIZE], bool compressed = true);
void from_wif(const std::string& wif, uint8_t& version, uint8_t priv_key[PRIVATE_KEY_SIZE], bool& compressed);
void toDER(uint8_t packed_signature[PRIVATE_KEY_SIZE * 2], std::vector<uint8_t>& signature);
void toDER(const std::vector<uint8_t>& r, const std::vector<uint8_t>& s, std::vector<uint8_t>& signature);
std::vector<uint8_t>& convert_to_der_buffer(std::vector<uint8_t>& buffer);
void sign(const Sha256Hash& hash, const uint8_t priv_key[PRIVATE_KEY_SIZE], std::vector<uint8_t>& signature);
std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);
bool validate_address(const char* const address, uint8_t network);
Account create_account(uint8_t network, const char* const passphrase);

ARK::Transaction create_transaction(const char* const address, double amount, const std::string& vendor_field, uint8_t secret[PRIVATE_KEY_SIZE], uint8_t second_secret[PRIVATE_KEY_SIZE] = nullptr, uint32_t version = 1, uint64_t fee_override = ARK::Fees::send);
void get_transaction_bytes(const Ark::Transaction& transaction, uint8_t buffer[512]);

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
