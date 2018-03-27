#ifndef PASSPHRASE_H
#define PASSPHRASE_H

#include "constants/bip39_words.h"

#include <array>

class Passphrase {
private:
	static const auto SINGLE_PASSPHRASE_NUM_WORDS = 12u;
	static const auto SECOND_PASSPHRASE_NUM_WORDS = 24u;

	std::array<std::array<char, SECOND_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH> _words;
	bool _use_second_passphrase;

public:
	Passphrase(bool generate_second_passphrase = false, uint8_t strength = 128);
	
	Passphrase(const std::array<std::array<char, SINGLE_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words);

	Passphrase(const std::array<std::array<char, SECOND_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words);

	Passphrase(const Passphrase&) = default;
	Passphrase& operator=(const Passphrase&) = default;

	Passphrase(Passphrase&&) = delete;
	Passphrase& operator=(Passphrase&&) = delete;

	uint8_t num_words() const noexcept { return _use_second_passphrase ? 24u : 12u; }

	const char* operator[](size_t index) const { return _words[index].data(); }

private:
	template <size_t N> 
	void copy_words(const std::array<std::array<char, N>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words) {
		for (auto i = 0u; i < N; ++i) {
			std::copy(words[i].cbegin(), words[i].cend(), _words[i].begin());
		}
	}
};

#endif
