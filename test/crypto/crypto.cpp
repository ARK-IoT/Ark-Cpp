#include "gtest/gtest.h"

#include "crypto/ark_crypto.h"
#include "constants/networks.h"
#include "bitcoin/utilstrencodings.h"
#include "bitcoin/uint256.h"

#include <string>
#include <vector>

namespace {

const auto passphrase = "bullet parade snow bacon mutual deposit brass floor staff list concert ask";

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

	// test net ??
	//ASSERT_STREQ(
	//	"",
	//	ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::testnet.pubKeyHash, "").c_str()
	//);
}

TEST(crypto, get_public_key) {
	std::vector<uint8_t> priv_key = ParseHex("0404040404040404040404040404040404040404040404040404040404040404");
	std::vector<uint8_t> pub_key(33);
	ARK::Crypto::get_public_key(priv_key, pub_key, true);
	auto pub_str = HexStr(pub_key);
	/*ASSERT_STREQ(
		"",
		pub_str.c_str()
	);

	priv_key = ParseHex("0000000000000000000000000000000000000000000000000000000000000001");
	pub_key = std::vector<uint8_t>(33);
	ARK::Crypto::get_public_key(priv_key, pub_key, true);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798",
		pub_str.c_str()
	);

	pub_key = std::vector<uint8_t>(64);
	ARK::Crypto::get_public_key(priv_key, pub_key, false);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"0479be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8",
		pub_str.c_str()
	);*/

	//priv_key = ParseDec("19898843618908353587043383062236220484949425084007183071220218307100305431102");
	priv_key = ParseHex("2BFE58AB6D9FD575BDC3A624E4825DD2B375D64AC033FBC46EA79DBAB4F69A3E");
	pub_key = std::vector<uint8_t>(33);
	ARK::Crypto::get_public_key(priv_key, pub_key, true);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"02b80011a883a0fd621ad46dfc405df1e74bf075cbaf700fd4aebef6e96f848340",
		pub_str.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	pub_key = std::vector<uint8_t>(33);
	ARK::Crypto::get_public_key(priv_key, pub_key, true);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"024289801366bcee6172b771cf5a7f13aaecd237a0b9a1ff9d769cabc2e6b70a34",
		pub_str.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	pub_key = std::vector<uint8_t>(64);
	ARK::Crypto::get_public_key(priv_key, pub_key, false);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"044289801366bcee6172b771cf5a7f13aaecd237a0b9a1ff9d769cabc2e6b70a34cec320a0565fb7caf11b1ca2f445f9b7b012dda5718b3cface369ee3a034ded6",
		pub_str.c_str()
	);
}

TEST(crypto, generate_wif) {
	std::vector<uint8_t> priv_key = ParseHex("0404040404040404040404040404040404040404040404040404040404040404");
	auto wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"S9hzwiZ5ziKjUiFpuZX4Lri3rUocDxZSTy7YzKKHvx8TSjUrYQ27",
		wif.c_str()
	);

	priv_key = ParseHex("0000000000000000000000000000000000000000000000000000000000000001");
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"S9aCCSFvm8kNeyFb1t6pLb5oJs9tv96ag6uA8Du6UM7zsmsNHQiz",
		wif.c_str()
	);

	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, false);
	ASSERT_STREQ(
		"6hTYzRJRsKyVvTnu7YWs9WvegPh5WiFrmf3JUTwPzQ8vtvPwoBG",
		wif.c_str()
	);

	
	//From ark - client:  should pass but doesn't.
		//const auto p = "rural shell desert cake couch car adapt aunt project faculty agree census";
		const auto p = "bike sustain face funny virus federal tip during sing trend banana bulb";
	priv_key = std::vector<uint8_t>(32);
	std::vector<uint8_t> pub_key(33);
	ARK::Crypto::get_keys(p, priv_key, pub_key);
	auto prv_s = HexStr(priv_key);
	auto pub_s = HexStr(pub_key);
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"SHcSK2KAbzPB91UQaCk2keMsZti86H5bmD19JN6WsD6WpPXZXNEW",
		wif.c_str()
	);
	
	
	//priv_key = ParseDec("19898843618908353587043383062236220484949425084007183071220218307100305431102");
	priv_key = ParseHex("2BFE58AB6D9FD575BDC3A624E4825DD2B375D64AC033FBC46EA79DBAB4F69A3E");
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"SB3iDxYmKgjkhfDZSKgLaBrp3Ynzd3yd3ZZF2ujVBK7vLpv6hWKK",
		wif.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"SDCe8styqokHi4pSe5jVRiYVV63Mef2TGsE1D4HhtGAL1DytHLtd",
		wif.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, false);
	ASSERT_STREQ(
		"6iHEQ5jbB9n9meZxCaFAAE39ii1zEyCCquca8GFCyvjSc1UFLp2",
		wif.c_str()
	);

	static const auto s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	priv_key = std::vector<uint8_t>(32);
	std::memcpy(&priv_key[0], s, priv_key.size());
	wif = ARK::Crypto::get_wif(ARK::Constants::Networks::Network_ADV::bitcoin.wif, priv_key, true);
	ASSERT_STREQ(
		"L1Knwj9W3qK3qMKdTvmg3VfzUs3ij2LETTFhxza9LfD5dngnoLG1",
		wif.c_str()
	);
}
