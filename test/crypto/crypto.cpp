#include "gtest/gtest.h"

#include "crypto/ark_crypto.h"
#include "crypto/util.h"
#include "constants/networks.h"
#include "Sha256.hpp"

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
		ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, ParseHex("0361eba308995231b03f005323fa71fc8dcda34564800fde41d166222d6811ebf6")).c_str()
	);

	// main net
	ASSERT_STREQ(
		"AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH",
		ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::main.pubKeyHash, ParseHex("02579b22787db8a7cb838729ad21bb0471e472027904df3d674ef074006a9a22c0")).c_str()
	);

	// test net ??
	//ASSERT_STREQ(
	//	"",
	//	ARK::Crypto::get_address(ARK::Constants::Networks::Network_ADV::testnet.pubKeyHash, ParseHex("")).c_str()
	//);
}

TEST(crypto, validate_address) {
	// valid
	ASSERT_TRUE(ARK::Crypto::validate_address("AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH", ARK::Constants::Networks::Network_ADV::main.pubKeyHash));
	ASSERT_TRUE(ARK::Crypto::validate_address("D8WEzKygD4BYDngjXyWC84om6GBvBMkVFY", ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash));
	ASSERT_TRUE(ARK::Crypto::validate_address("a6fpb1BJZq4otWiVsBcuLG1ZGs5WsqqQtH", 0x52));

	// invalid
	ASSERT_FALSE(ARK::Crypto::validate_address("BQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH", ARK::Constants::Networks::Network_ADV::main.pubKeyHash));
	ASSERT_FALSE(ARK::Crypto::validate_address("E8WEzKygD4BYDngjXyWC84om6GBvBMkVFY", ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash));
	ASSERT_FALSE(ARK::Crypto::validate_address("b6fpb1BJZq4otWiVsBcuLG1ZGs5WsqqQtH", 0x52));
}

TEST(crypto, get_private_key) {
	auto phrase = "seven age job canoe call lonely case same bounce giggle pluck mouse";
	uint8_t priv_key[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	ARK::Crypto::get_private_key(phrase, priv_key);
	auto priv_key_str = HexStr(priv_key, priv_key + ARK::Crypto::PRIVATE_KEY_SIZE);
	ASSERT_STREQ(
		"391c39c785128986b8959d40aeb9698071d68ebd07967b8f7d3ed8a35d4433c6",
		priv_key_str.c_str()
	);
}

TEST(crypto, get_public_key) {
	// TODO?:  test for n=1 is not supported with currenty ECC implementation.
	// see https://github.com/kmackay/micro-ecc/issues/128
	/*std::vector<uint8_t> priv_key = ParseHex("0000000000000000000000000000000000000000000000000000000000000001");
	std::vector<uint8_t> pub_key(ARK::Crypto::COMPRESSED_PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(priv_key, pub_key, true);
	auto pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798",
		pub_str.c_str()
	);

	pub_key = std::vector<uint8_t>(ARK::Crypto::PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(priv_key, pub_key, false);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"0479be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8",
		pub_str.c_str()
	);*/

	//priv_key = ParseDec("19898843618908353587043383062236220484949425084007183071220218307100305431102");
	auto priv_key = ParseHex("2BFE58AB6D9FD575BDC3A624E4825DD2B375D64AC033FBC46EA79DBAB4F69A3E");
	auto pub_key = std::vector<uint8_t>(ARK::Crypto::COMPRESSED_PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(&priv_key[0], pub_key, true);
	auto pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"02b80011a883a0fd621ad46dfc405df1e74bf075cbaf700fd4aebef6e96f848340",
		pub_str.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	pub_key = std::vector<uint8_t>(ARK::Crypto::COMPRESSED_PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(&priv_key[0], pub_key, true);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"024289801366bcee6172b771cf5a7f13aaecd237a0b9a1ff9d769cabc2e6b70a34",
		pub_str.c_str()
	);

	pub_key = std::vector<uint8_t>(ARK::Crypto::PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(&priv_key[0], pub_key, false);
	pub_str = HexStr(pub_key);
	ASSERT_STREQ(
		"044289801366bcee6172b771cf5a7f13aaecd237a0b9a1ff9d769cabc2e6b70a34cec320a0565fb7caf11b1ca2f445f9b7b012dda5718b3cface369ee3a034ded6",
		pub_str.c_str()
	);
}

TEST(crypto, to_wif) {
	std::vector<uint8_t> priv_key_vect = ParseHex("0000000000000000000000000000000000000000000000000000000000000001");
	uint8_t priv_key[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	std::memcpy(priv_key, &priv_key_vect[0], sizeof(priv_key));
	auto wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"S9aCCSFvm8kNeyFb1t6pLb5oJs9tv96ag6uA8Du6UM7zsmsNHQiz",
		wif.c_str()
	);

	//priv_key = ParseDec("19898843618908353587043383062236220484949425084007183071220218307100305431102");
	priv_key_vect = ParseHex("2BFE58AB6D9FD575BDC3A624E4825DD2B375D64AC033FBC46EA79DBAB4F69A3E");
	std::memcpy(priv_key, &priv_key_vect[0], sizeof(priv_key));
	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"SB3iDxYmKgjkhfDZSKgLaBrp3Ynzd3yd3ZZF2ujVBK7vLpv6hWKK",
		wif.c_str()
	);

	//priv_key = ParseDec("48968302285117906840285529799176770990048954789747953886390402978935544927851");
	priv_key_vect = ParseHex("6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B");
	std::memcpy(priv_key, &priv_key_vect[0], sizeof(priv_key));
	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, true);
	ASSERT_STREQ(
		"SDCe8styqokHi4pSe5jVRiYVV63Mef2TGsE1D4HhtGAL1DytHLtd",
		wif.c_str()
	);

	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::devnet.wif, priv_key, true);
	ASSERT_STREQ(
		"SDCe8styqokHi4pSe5jVRiYVV63Mef2TGsE1D4HhtGAL1DytHLtd",
		wif.c_str()
	);

	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::main.wif, priv_key, false);
	ASSERT_STREQ(
		"6iHEQ5jbB9n9meZxCaFAAE39ii1zEyCCquca8GFCyvjSc1UFLp2",
		wif.c_str()
	);

	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::devnet.wif, priv_key, false);
	ASSERT_STREQ(
		"6iHEQ5jbB9n9meZxCaFAAE39ii1zEyCCquca8GFCyvjSc1UFLp2",
		wif.c_str()
	);

	static const auto priv_key_str = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	std::memcpy(&priv_key[0], priv_key_str, ARK::Crypto::PRIVATE_KEY_SIZE);
	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::bitcoin.wif, priv_key, true);
	ASSERT_STREQ(
		"L1Knwj9W3qK3qMKdTvmg3VfzUs3ij2LETTFhxza9LfD5dngnoLG1",
		wif.c_str()
	);

	ARK::Crypto::get_private_key(passphrase, priv_key);
	wif = ARK::Crypto::to_wif(ARK::Constants::Networks::Network_ADV::devnet.wif, priv_key, true);
	ASSERT_STREQ(
		"SEZuJZouNK8GLXNApjciH4QnSKiNr971exVcL2Y6XfrDF5o977zB",
		wif.c_str()
	);
}

TEST(crypto, from_wif) {
	uint8_t priv_key[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	uint8_t version;
	bool compressed;	
	ARK::Crypto::from_wif("S9aCCSFvm8kNeyFb1t6pLb5oJs9tv96ag6uA8Du6UM7zsmsNHQiz", version, priv_key, compressed);
	ASSERT_STREQ(
		"0000000000000000000000000000000000000000000000000000000000000001",
		HexStr(priv_key, priv_key + ARK::Crypto::PRIVATE_KEY_SIZE).c_str()
	);
	ASSERT_TRUE(compressed);
	ASSERT_EQ(ARK::Constants::Networks::Network_ADV::main.wif, version);

	ARK::Crypto::from_wif("SB3iDxYmKgjkhfDZSKgLaBrp3Ynzd3yd3ZZF2ujVBK7vLpv6hWKK", version, priv_key, compressed);
	ASSERT_STRCASEEQ(
		"2BFE58AB6D9FD575BDC3A624E4825DD2B375D64AC033FBC46EA79DBAB4F69A3E",  // DEC: "19898843618908353587043383062236220484949425084007183071220218307100305431102"
		HexStr(priv_key, priv_key + ARK::Crypto::PRIVATE_KEY_SIZE).c_str()
	);
	ASSERT_TRUE(compressed);
	ASSERT_EQ(ARK::Constants::Networks::Network_ADV::main.wif, version);


	ARK::Crypto::from_wif("SDCe8styqokHi4pSe5jVRiYVV63Mef2TGsE1D4HhtGAL1DytHLtd", version, priv_key, compressed);
	ASSERT_STRCASEEQ(
		"6C4313B03F2E7324D75E642F0AB81B734B724E13FEC930F309E222470236D66B",  // DEC: "48968302285117906840285529799176770990048954789747953886390402978935544927851"
		HexStr(priv_key, priv_key + ARK::Crypto::PRIVATE_KEY_SIZE).c_str()
	);
	ASSERT_TRUE(compressed);
	ASSERT_EQ(ARK::Constants::Networks::Network_ADV::main.wif, version);

	uint8_t expected_priv_key[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	ARK::Crypto::get_private_key(passphrase, expected_priv_key);
	ARK::Crypto::from_wif("SEZuJZouNK8GLXNApjciH4QnSKiNr971exVcL2Y6XfrDF5o977zB", version, priv_key, compressed);
	auto b = std::memcmp(expected_priv_key, priv_key, sizeof(priv_key)) == 0;
	ASSERT_TRUE(b);
	ASSERT_TRUE(compressed);
	ASSERT_EQ(ARK::Constants::Networks::Network_ADV::main.wif, version);
}

TEST(crypto, sign) {
	uint8_t d[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	std::vector<uint8_t> temp = ParseHex("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140");
	std::memcpy(d, &temp[0], sizeof(d));
	auto message = "Equations are more important to me, because politics is for the present, but an equation is something for eternity.";
	auto hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(message), std::strlen(message));
	std::vector<uint8_t> signature;
	ARK::Crypto::sign(hash, d, signature);
	ASSERT_STRCASEEQ(
		"3044022054c4a33c6423d689378f160a7ff8b61330444abb58fb470f96ea16d99d4a2fed022007082304410efa6b2943111b6a4e0aaa7b7db55a07e9861d1fb3cb1f421044a5",
		HexStr(signature).c_str()
	);

	message = "Not only is the Universe stranger than we think, it is stranger than we can think.";
	hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(message), std::strlen(message));
	ARK::Crypto::sign(hash, d, signature);
	ASSERT_STRCASEEQ(
		"3045022100ff466a9f1b7b273e2f4c3ffe032eb2e814121ed18ef84665d0f515360dab3dd002206fc95f5132e5ecfdc8e5e6e616cc77151455d46ed48f5589b7db7771a332b283",
		HexStr(signature).c_str()
	);

	temp = ParseHex("69ec59eaa1f4f2e36b639716b7c30ca86d9a5375c7b38d8918bd9c0ebc80ba64");
	std::memcpy(d, &temp[0], sizeof(d));
	message = "Computer science is no more about computers than astronomy is about telescopes.";
	hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(message), std::strlen(message));
	ARK::Crypto::sign(hash, d, signature);
	ASSERT_STRCASEEQ(
		"304402207186363571d65e084e7f02b0b77c3ec44fb1b257dee26274c38c928986fea45d02200de0b38e06807e46bda1f1e293f4f6323e854c86d58abdd00c46c16441085df6",
		HexStr(signature).c_str()
	);

	temp = ParseHex("00000000000000000000000000007246174ab1e92e9149c6e446fe194d072637");
	std::memcpy(d, &temp[0], sizeof(d));
	message = "...if you aren't, at any given time, scandalized by code you wrote five or even three years ago, you're not learning anywhere near enough";
	hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(message), std::strlen(message));
	ARK::Crypto::sign(hash, d, signature);
	ASSERT_STRCASEEQ(
		"3045022100fbfe5076a15860ba8ed00e75e9bd22e05d230f02a936b653eb55b61c99dda48702200e68880ebb0050fe4312b1b1eb0899e1b82da89baa5b895f612619edf34cbd37",
		HexStr(signature).c_str()
	);

	temp = ParseHex("000000000000000000000000000000000000000000056916d0f9b31dc9b637f3");
	std::memcpy(d, &temp[0], sizeof(d));
	message = "The question of whether computers can think is like the question of whether submarines can swim.";
	hash = Sha256::getHash(reinterpret_cast<const unsigned char*>(message), std::strlen(message));
	ARK::Crypto::sign(hash, d, signature);
	ASSERT_STRCASEEQ(
		"3045022100cde1302d83f8dd835d89aef803c74a119f561fbaef3eb9129e45f30de86abbf9022006ce643f5049ee1f27890467b77a6a8e11ec4661cc38cd8badf90115fbd03cef",
		HexStr(signature).c_str()
	);
}