#include "gtest/gtest.h"

#include "crypto/bip39.h"

TEST(crypto, create_account) {
	const auto account = ARK::Crypto::BIP39::create_account(ARK::Crypto::BIP39::generate_mnemonic().c_str());
	
	//Passphrase passphrase("bullet parade snow bacon mutual deposit brass floor staff list concert ask");

	//ASSERT_TRUE(std::strncmp("950981ce17df662dbc1d25305f8597a71309fb8f7232203a0944477e2534b021", passphrase.private_key(), 64) == 0);

}
