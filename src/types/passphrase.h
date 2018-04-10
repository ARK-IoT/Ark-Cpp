#ifndef PASSPHRASE_H
#define PASSPHRASE_H

#include "constants/bip39_words.h"

#include <array>

class Passphrase {
public:
	static const auto SINGLE_PASSPHRASE_NUM_WORDS = 12u;
	static const auto SECOND_PASSPHRASE_NUM_WORDS = 24u;

	typedef std::array<std::array<char, ARK::Constants::MAX_BIP39_WORD_LENGTH>, SECOND_PASSPHRASE_NUM_WORDS> words_24_type;
	typedef std::array<std::array<char, ARK::Constants::MAX_BIP39_WORD_LENGTH>, SINGLE_PASSPHRASE_NUM_WORDS> words_12_type;

private:
	char _words[SECOND_PASSPHRASE_NUM_WORDS * (MAX_BIP39_WORD_LENGTH + 1)];
	bool _use_second_passphrase;
	char _private_key[256];

public:
	Passphrase(bool generate_second_passphrase = false, uint8_t strength = 128);

	Passphrase(const char* const word_list);
	
	Passphrase(const words_12_type& words);

	Passphrase(const words_24_type& words);

	Passphrase(const Passphrase&) = default;
	Passphrase& operator=(const Passphrase&) = default;

	Passphrase(Passphrase&&) = delete;
	Passphrase& operator=(Passphrase&&) = delete;

	uint8_t num_words() const noexcept { return _use_second_passphrase ? 24u : 12u; }

	//const char* operator[](size_t index) const { return _words[index].data(); }

	const char* private_key() const { return _private_key; }

private:
	template <size_t N> 
	void copy_words(const std::array<std::array<char, ARK::Constants::MAX_BIP39_WORD_LENGTH>, N>& words) {
		// TODO: validate words
		for (auto i = 0u; i < N; ++i) {
			std::copy(words[i].cbegin(), words[i].cend(), _words[i].begin());
		}
	}

	void calculate_private_key();
};

#endif
