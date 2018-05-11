#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "models/account.h"

#include <string>
#include <vector>

namespace ARK {
namespace Crypto {

void get_keys(const char* const passphrase, std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed = true);
void get_public_key(const std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed = true);
std::string get_wif(uint8_t wif, const std::vector<uint8_t>& priv_key, bool compressed = true);

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);
std::string get_address(uint8_t network, const std::string& public_key);

Account create_account(uint8_t network, const char* const passphrase);

}
}

#endif
