#include "bip39/bip39.h"

#include "bip39/en.h"

#include <random>
#include <cassert>

namespace ARK {
namespace Crypto {
namespace BIP39 {

namespace {

PGM_P* get_string_table(language lang) {
	switch (lang) {
	case language::en: return en_table;

	default:
		assert("error unsupported language");
		return nullptr;
	};
}

}


std::string generate_mnemonic(language lang /* = language::en */, uint8_t num_words /* = 12 */) {
	if (num_words != 12 && num_words != 24) {
		// error??
	}
	std::random_device rd;
	std::uniform_int_distribution<size_t> dist(0, NUM_BIP39_WORDS - 1);
	std::string passphrase;
	const auto words = get_string_table(lang);
	for (auto i = 0; i < num_words; ) {
		const auto word = words[dist(rd)];
		if (passphrase.find(word) == std::string::npos) {
			passphrase += word;
			if (i != num_words - 1) {
				passphrase += ' ';
			}
			++i;
		}
	}
	return passphrase;
}

}
}
}
