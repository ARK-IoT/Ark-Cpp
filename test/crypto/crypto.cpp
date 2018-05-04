#include "gtest/gtest.h"

#include "crypto/ark_crypto.h"
#include "constants/networks.h"

#include <string>
#include <set>
#include <sstream>

namespace {

const auto passphrase = "bullet parade snow bacon mutual deposit brass floor staff list concert ask";

}

TEST(crypto, generate_mnemonic) {
	auto passphrase = ARK::Crypto::generate_mnemonic(24);
	std::istringstream stream(passphrase);
	std::set<std::string> words;
	for (std::string word; stream; ) {
		stream >> word;
		if (word.empty()) { continue; }
		ASSERT_TRUE(words.insert(std::move(word)).second);
	}
	ASSERT_EQ(24, words.size());

	passphrase = ARK::Crypto::generate_mnemonic(12);
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

TEST(crypto, create_account) {
	const auto account = ARK::Crypto::create_account(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, passphrase);
	
	ASSERT_STREQ("DStZXkgpEjxbG355nQ26vnkp95p24U9tsV", account.address().getValue());
	ASSERT_STREQ("029fdf41a7d69d8efc7b236c21b9509a23d862ea4ed8b13a56e31eee58dbfd97b4", account.public_key().getValue());
}

TEST(crypto, generate_address) {
	// dev net
	ASSERT_STREQ(
		"D8WEzKygD4BYDngjXyWC84om6GBvBMkVFY", 
		ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, "0361eba308995231b03f005323fa71fc8dcda34564800fde41d166222d6811ebf6").c_str()
	);

	// main net
	ASSERT_STREQ(
		"AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH",
		ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::main.pubKeyHash, "02579b22787db8a7cb838729ad21bb0471e472027904df3d674ef074006a9a22c0").c_str()
	);

	// test net
	//ASSERT_STREQ(
	//	"",
	//	ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::testnet.pubKeyHash, "").c_str()
	//);
}

TEST(crypto, generate_wif) {
	//const auto keys = ARK::Crypto::get_keys(passphrase);
	//const auto wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::devnet.wif, keys.GetPrivKey());
	//ASSERT_STREQ(
	//	"SEZuJZouNK8GLXNApjciH4QnSKiNr971exVcL2Y6XfrDF5o977zB",
	//	wif.c_str()
	//);
}
