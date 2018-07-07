#include "gtest/gtest.h"

#include "api/api.h"
#if 0
TEST(api, test_peer_peer)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto peer = _arkManager.peer("167.114.29.55", 4002);
	ASSERT_STREQ("167.114.29.55", peer.ip());
	ASSERT_EQ(4002, peer.port());
	ASSERT_STREQ("1.1.1", peer.version());
	//ASSERT_EQ(0, peer.errors());
	ASSERT_STREQ("linux4.4.0-79-generic", peer.os());
	ASSERT_STRNE("0", peer.height());
	ASSERT_TRUE(strcmp("OK", peer.status()) == 0 || strcmp("EUNAVAILABLE", peer.status()) == 0 || strcmp("ETIMEOUT", peer.status()) == 0);
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
	ASSERT_STREQ("1.1.1", version.version());
	ASSERT_STREQ("", version.build());
}
#endif

TEST(api, test_peer_post_transaction) {
	//ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Mainnet);

	const auto t = ARK::make_transaction(
		//ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash,
		ARK::Constants::Networks::Network_ADV::main.pubKeyHash,
		//"DGUac5xr1cn7D2VVG7hEmV1cb1wfvbbc6p",
		"AeXM1xpkCrarUTBraEpnGnp2ZrAyRAQYqS",
		00000001,
		"ark-cpp TX",
		//"tower sponsor engine cram define bone agree mountain sad find place rug"
		"eyebrow shoot dwarf pattern tattoo account grid treat lesson legend doll wink"
	);
	ASSERT_TRUE(_arkManager.postTransaction(t));
}
