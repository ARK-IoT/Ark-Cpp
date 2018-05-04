#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "models/account.h"

#include <string>
#include <vector>

namespace ARK {
namespace Crypto {

const auto MAX_BIP39_WORD_LENGTH = 8 + 1;
const auto NUM_BIP39_WORDS = 2048;

extern const char BIP39_WORDS[NUM_BIP39_WORDS][MAX_BIP39_WORD_LENGTH];

std::string generate_mnemonic(uint8_t num_words = 12);
void get_keys(const char* const passphrase, std::vector<uint8_t>& priv_key, std::vector<uint8_t>& pub_key, bool compressed = true);
std::string get_wif(uint8_t wif, const std::vector<uint8_t>& priv_key, bool compressed = true);

std::string get_address(uint8_t network, const std::vector<uint8_t>& public_key);
std::string get_address(uint8_t network, const std::string& public_key);

Account create_account(uint8_t network, const char* const passphrase);

}
}

#endif
