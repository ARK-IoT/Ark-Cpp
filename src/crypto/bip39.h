#ifndef BIP39_WORDS_H
#define BIP39_WORDS_H

#include "models/account.h"

#include <string>

namespace ARK {
namespace Crypto {
namespace BIP39 {

const auto MAX_BIP39_WORD_LENGTH = 8 + 1;
const auto NUM_BIP39_WORDS = 2048;

extern const char BIP39_WORDS[NUM_BIP39_WORDS][MAX_BIP39_WORD_LENGTH];

std::string generate_mnemonic();

Account create_account(const char* const passphrase);

}
}
}

#endif
