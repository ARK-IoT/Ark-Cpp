#include "gtest/gtest.h"

#include "api/api.h"

TEST(api, test_peer_peer)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto peer = _arkManager.peer("167.114.29.55", 4002);
	ASSERT_STREQ("167.114.29.55", peer.ip());
	ASSERT_EQ(4002, peer.port());
	ASSERT_STRNE("", peer.version());
	//ASSERT_EQ(0, peer.errors());
	ASSERT_STRNE("", peer.os());
	ASSERT_STRNE("0", peer.height());
	ASSERT_STRNE("", peer.status());
	ASSERT_NE(0, peer.delay());
}

	/*  ==================================  */
	/*  ==================================  */
	/*	BROKEN: fix for large callbacks  */
	/*	Peers callback is ~10,000 bytes  */
	//  String peersDescription = _arkManager.peers().getValue();
	//	Serial.println("peersDescription: ");
	//	Serial.println(peersDescription);
	//	Serial.println("\n=====\n");
	/*  ==================================  */
	/*  ==================================  */

TEST(api, test_peer_version)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto version = _arkManager.peerVersion();
	ASSERT_STRNE("", version.version());
	ASSERT_STREQ("", version.build());
}

TEST(api, test_peer_post_transaction) {
#if 0 // TODO: enable when devnet is working.  switch to devnet and delete mainnet addresses
	//const auto passphrase1 = "later knock problem deal swallow bonus menu game version merit salt lobster";	// D8FcqJonziwnSSoczuJQde19v2FzrMZuPA
	//const auto passphrase2 = "grocery tone repeat tone soldier entry plunge rich until canal age scene";	// DRAiWhynzcoSR1muJ1NnrF5MEqptyRm1sd

	//ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Mainnet);

	const auto t = ARK::make_transaction(
		//ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash,
		ARK::Constants::Networks::Network_ADV::main.pubKeyHash,
		//"DGUac5xr1cn7D2VVG7hEmV1cb1wfvbbc6p",
		"AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH",
		00000001,
		"ark-cpp - unit test",
		//"tower sponsor engine cram define bone agree mountain sad find place rug"  //DARK
		// "eyebrow shoot dwarf pattern tattoo account grid treat lesson legend doll wink" // AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH
		"moon silk magnet unhappy protect water soft walnut hire tide street boss" // AeXM1xpkCrarUTBraEpnGnp2ZrAyRAQYqS
	);
	ASSERT_TRUE(_arkManager.postTransaction(*t));
#endif
}
