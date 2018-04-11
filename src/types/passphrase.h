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
	char _words[SECOND_PASSPHRASE_NUM_WORDS * (ARK::Constants::MAX_BIP39_WORD_LENGTH + 1)];
	char _phrase[SECOND_PASSPHRASE_NUM_WORDS * ARK::Constants::MAX_BIP39_WORD_LENGTH];
	bool _use_second_passphrase;
	uint8_t _private_key[64];

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

	//const char* operator[](size_t index) const { return _words[index]; }

	const uint8_t* private_key() const { return _private_key; }

private:
	template <size_t N> 
	void copy_words(const std::array<std::array<char, ARK::Constants::MAX_BIP39_WORD_LENGTH>, N>& words) {
		// TODO: validate words
		for(const auto& word : words) {
			std::strcat(_words, word.data());
			std::strcat(_words, " ");
			std::strcat(_phrase, word.data());
		}
		// remove trailing space
		_words[std::strlen(_words) - 1] = '\0';
	}

	void calculate_private_key();
};

#endif
