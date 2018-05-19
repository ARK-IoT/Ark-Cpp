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
std::string to_wif(uint8_t version, const std::vector<uint8_t>& priv_key, bool compressed = true);
void from_wif(const std::string& wif, uint8_t& version, std::vector<uint8_t>& priv_key, bool& compressed);

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);

Account create_account(uint8_t network, const char* const passphrase);

}
}

#endif
