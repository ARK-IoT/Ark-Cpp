#include "types/passphrase.h"

Passphrase::Passphrase(
	bool generate_second_passphrase /* = false */, 
	uint8_t strength /* = 128 */
) : 
	_words(), 
	_use_second_passphrase(generate_second_passphrase) 
{
	
	
}
	
Passphrase::Passphrase(const std::array<std::array<char, SINGLE_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words) : _words() {
	copy_words(words);
}

Passphrase::Passphrase(const std::array<std::array<char, SECOND_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words) : _words() {
	copy_words(words);
}
