#include "gtest/gtest.h"

#include "crypto/crypto.h"
#include "crypto/sha256.h"
#include "bitcoin/uint256.h"
#include "constants/networks.h"


TEST(crypto, create_account) {
	ARK::Crypto::create_account(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, "bullet parade snow bacon mutual deposit brass floor staff list concert ask");


	const auto account = ARK::Crypto::create_account(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, "tower sponsor engine cram define bone agree mountain sad find place rug");
	
	ASSERT_STREQ("D8WEzKygD4BYDngjXyWC84om6GBvBMkVFY", account.address().getValue());
	ASSERT_STREQ("0361eba308995231b03f005323fa71fc8dcda34564800fde41d166222d6811ebf6", account.public_key().getValue());
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
	ARK::Crypto::SHA256Engine sha256;
	
	sha256.update("bullet parade snow bacon mutual deposit brass floor staff list concert ask");
	const auto hash = sha256.digest();
	const auto wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::devnet.wif, hash);
	ASSERT_STREQ(
		"SEZuJZouNK8GLXNApjciH4QnSKiNr971exVcL2Y6XfrDF5o977zB",
		wif.c_str()
	);
}
