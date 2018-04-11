#include "types/passphrase.h"
#include "crypto/sha256.h"

#include "Poco/PBKDF2Engine.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/Crypto/DigestEngine.h"

namespace {

class SHA512Engine : public Poco::Crypto::DigestEngine
{
public:
    enum
    {
        BLOCK_SIZE = 64,
        DIGEST_SIZE = 32
    };

    SHA512Engine()
            : DigestEngine("SHA512")
    {
    }

};


}

Passphrase::Passphrase(
	bool generate_second_passphrase /* = false */, 
	uint8_t strength /* = 128 */
) : 
	_words(),
	_phrase(),
	_use_second_passphrase(generate_second_passphrase),
	_private_key()
{
	// TODO: generate random words
	
	calculate_private_key();
}

Passphrase::Passphrase(const char* const word_list) : _words(), _phrase(), _use_second_passphrase(false), _private_key() {
	std::strncpy(_words, word_list, sizeof(_words));
	auto count = 0u;
	// count words
	for (auto i = 0u; _words[i] != '\0'; ++i) {
		if (_words[i] == ' ') { 
			++count; 
		} else {
			std::strncat(_phrase, &_words[i], 1);
		}
	}

	// add one for the last word
	++count;

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
) : _words(), _phrase(), _use_second_passphrase(false), _private_key() {
	copy_words<12>(words);
	calculate_private_key();
}

Passphrase::Passphrase(
	const words_24_type& words
) : _words(), _phrase(), _use_second_passphrase(true), _private_key() {
	copy_words(words);
	calculate_private_key();
}

void Passphrase::calculate_private_key() {
	static const auto passphrase_prefix = "mnemonic";
	static const auto password = "";
	const auto salt = std::string(passphrase_prefix) + password;
	Poco::PBKDF2Engine<Poco::HMACEngine<SHA512Engine> > pbkdf2(salt, 2048, 64);
	pbkdf2.update(_phrase);
	auto d = pbkdf2.digest();
	std::memcpy(_private_key, &d[0], 64);
	//return pkcs5_pbkdf2_hmac_sha512(to_chunk(sentence), to_chunk(salt), hmac_iterations);


}
