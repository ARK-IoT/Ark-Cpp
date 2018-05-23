#include "gtest/gtest.h"

#include "bip39/bip39.h"

#include <string>
#include <set>
//#include <sstream>
/*
TEST(crypto_bip39, generate_mnemonic) {
	auto passphrase = ARK::Crypto::BIP39::generate_mnemonic(ARK::Crypto::BIP39::language::en, 24);
	std::istringstream stream(passphrase);
	std::set<std::string> words;
	for (std::string word; stream; ) {
		stream >> word;
		if (word.empty()) { continue; }
		ASSERT_TRUE(words.insert(std::move(word)).second);
	}
	ASSERT_EQ(24, words.size());

	passphrase = ARK::Crypto::BIP39::generate_mnemonic(ARK::Crypto::BIP39::language::en, 12);
	words.clear();
	stream.str(passphrase);
	stream.clear();
	for (std::string word; stream; ) {
		stream >> word;
		if (word.empty()) { continue; }
		ASSERT_TRUE(words.insert(std::move(word)).second);
	}
	ASSERT_EQ(12, words.size());
}
*/