#ifndef BIP39_WORDS_H
#define BIP39_WORDS_H

namespace ARK {
namespace Constants {

const auto MAX_BIP39_WORD_LENGTH = 8 + 1;
const auto NUM_BIP39_WORDS = 2048;

extern const char BIP39_WORDS[NUM_BIP39_WORDS][MAX_BIP39_WORD_LENGTH];

}
}

#endif
