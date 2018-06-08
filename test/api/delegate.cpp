#include "gtest/gtest.h"

#include "api/api.h"

namespace
{
	const Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
}

TEST(api, test_delegates_count)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ASSERT_NE(0, _arkManager.delegatesCount());
	const auto search = _arkManager.delegateSearch("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", search.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", search.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", search.public_key().getValue());
	const auto& vote = search.vote();
	ASSERT_NE(0.0, vote.getValue());
	ASSERT_NE(0, search.produced_blocks());
	ASSERT_NE(0, search.missed_blocks());
}

TEST(api, test_delegate_user)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	/*  ==================================  */
	//  String delegateVotersDescription = _arkManager.delegateVoters(darkPubkey).getValue();
	//    Serial.println("delegateVotersDescription: ");
	//    Serial.println(delegateVotersDescription);
	//    Serial.println("\n=====\n");
	/*  ==================================  */

	/*  ==================================  */
	auto delegate = _arkManager.delegate("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	ASSERT_NE(0.0, delegate.vote().getValue());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());
}

TEST(api, test_delegate_pub_key)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	auto delegate = _arkManager.delegate(darkPubkey.getValue());
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
	ASSERT_NE(0.0, delegate.vote().getValue());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());
}

TEST(api, test_delegate_fee)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	/*  ==================================  */
	/*    BROKEN: fix for large callbacks    */
	/*  Delegates callback is ~13,564 bytes  */
	//  String delegates = _arkManager.getDelegates();
	//    Serial.println("delegates: ");
	//    Serial.println(delegates);
	//    Serial.println("\n=====\n");
	/*  ==================================  */

	/*  ==================================  */
	//TODO:  fails here
	const auto delegateFee = _arkManager.delegateFee();
	ASSERT_EQ(25.0, delegateFee.getValue());
}

TEST(api, test_delegate_forged_by_account)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto forged_by_account = _arkManager.delegateForgedByAccount(darkPubkey);
	ASSERT_NE(0.0, forged_by_account.fees().getValue());
	ASSERT_NE(0.0, forged_by_account.forged().getValue());
	ASSERT_NE(0.0, forged_by_account.rewards().getValue());
	
	const auto next_forgers = _arkManager.delegateNextForgers();
	ASSERT_NE(0, next_forgers.current_block());
	ASSERT_NE(0, next_forgers.current_slot());
	//ASSERT_STREQ("", next_forgers.delegates().getValue());  //TODO: compare std::array
}
