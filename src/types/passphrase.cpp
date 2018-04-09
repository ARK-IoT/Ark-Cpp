#include "types/passphrase.h"
#include "crypto/sha256.h"

Passphrase::Passphrase(
	bool generate_second_passphrase /* = false */, 
	uint8_t strength /* = 128 */
) : 
	_words(), 
	_use_second_passphrase(generate_second_passphrase),
	_private_key()
{
	// TODO: generate random words
	
	calculate_private_key();
}

Passphrase::Passphrase(const char* const word_list) : _words(), _use_second_passphrase(false), _private_key() {
	// split word_list on spaces and copy to words.  
	// validate only 12 or 24
	// set flag if 24
}
	
Passphrase::Passphrase(
	const std::array<std::array<char, SINGLE_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words
) : _words(), _use_second_passphrase(false), _private_key() {
	copy_words(words);
	calculate_private_key();
}

Passphrase::Passphrase(
	const std::array<std::array<char, SECOND_PASSPHRASE_NUM_WORDS>, ARK::Constants::MAX_BIP39_WORD_LENGTH>& words
) : _words(), _use_second_passphrase(true), _private_key() {
	copy_words(words);
	calculate_private_key();
}

void Passphrase::calculate_private_key() {
	const ARK::Crypto::SHA256 sha256;

	sha256.processToBuffer(_private_key, _words.data()->data());
}
