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
	static const auto MAX_WORD_LIST_LENGTH = SECOND_PASSPHRASE_NUM_WORDS * (ARK::Constants::MAX_BIP39_WORD_LENGTH + 1); // +1 for spaces
	auto count = 0u;
	char words[MAX_WORD_LIST_LENGTH] = {};
	std::strncpy(words, word_list, MAX_WORD_LIST_LENGTH);
	auto s = std::strtok(const_cast<char*>(words), " ");
	while (s != nullptr && count < 24) {
		std::strncpy(_words[count++].data(), s, ARK::Constants::MAX_BIP39_WORD_LENGTH);
		s = std::strtok(nullptr, " ");
	}
	// validate only 12 or 24
	if (count != 12u && count != 24u) {
		// TODO: error
	}
	// set flag if 24
	if (count == 24u) {
		_use_second_passphrase = true;
	}
	calculate_private_key();
}
	
Passphrase::Passphrase(
	const words_12_type& words
) : _words(), _use_second_passphrase(false), _private_key() {
	copy_words<12>(words);
	calculate_private_key();
}

Passphrase::Passphrase(
	const words_24_type& words
) : _words(), _use_second_passphrase(true), _private_key() {
	copy_words(words);
	calculate_private_key();
}

void Passphrase::calculate_private_key() {
	const ARK::Crypto::SHA256 sha256;

	sha256.processToBuffer(_private_key, _words.data()->data());
}
