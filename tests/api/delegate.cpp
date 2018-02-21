#include "api.h"

#include "gtest/gtest.h"

TEST(delegate, test_delegate) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

	ASSERT_EQ(0, _arkManager.delegatesCount());

	const auto search = _arkManager.delegateSearch("sleepdeficit");
	ASSERT_STREQ("", search.username());
	ASSERT_STREQ("", search.address().description());
	ASSERT_STREQ("", search.public_key().description());
	const auto& vote = search.vote();
	ASSERT_STREQ("", vote.ark());
	ASSERT_STREQ("", vote.arktoshi());
	ASSERT_EQ(0, search.produced_blocks());
	ASSERT_EQ(0, search.missed_blocks());
	  


/*  ==================================  */
//  String delegateVotersDescription = _arkManager.delegateVoters(darkPubkey).description();
//    Serial.println("delegateVotersDescription: ");
//    Serial.println(delegateVotersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
	auto delegate = _arkManager.delegate("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("", delegate.address().description());
	ASSERT_STREQ("", delegate.public_key().description());
	ASSERT_STREQ("", delegate.vote().arktoshi());
	ASSERT_EQ(0, delegate.produced_blocks());
	ASSERT_EQ(0, delegate.missed_blocks());
	ASSERT_EQ(0, delegate.rate());
	ASSERT_EQ(0, delegate.approval());
	ASSERT_EQ(0, delegate.productivity());	

    delegate = _arkManager.delegate(darkPubkey.description());
    ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("", delegate.address().description());
	ASSERT_STREQ("", delegate.public_key().description());
	ASSERT_STREQ("", delegate.vote().arktoshi());
	ASSERT_EQ(0, delegate.produced_blocks());
	ASSERT_EQ(0, delegate.missed_blocks());
	ASSERT_EQ(0, delegate.rate());
	ASSERT_EQ(0, delegate.approval());
	ASSERT_EQ(0, delegate.productivity());	

/*  ==================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
	//TODO:  fails here
	const auto delegateFee = _arkManager.delegateFee();
	ASSERT_STREQ("", delegateFee.ark());
	ASSERT_STREQ("", delegateFee.arktoshi());

	const auto forged_by_account = _arkManager.delegateForgedByAccount(darkPubkey);
	ASSERT_STREQ("", forged_by_account.fees().ark());
	ASSERT_STREQ("", forged_by_account.fees().arktoshi());
	ASSERT_STREQ("", forged_by_account.forged().ark());
	ASSERT_STREQ("", forged_by_account.forged().arktoshi());
	ASSERT_STREQ("", forged_by_account.rewards().ark());
	ASSERT_STREQ("", forged_by_account.rewards().arktoshi());
	
	const auto next_forgers = _arkManager.delegateNextForgers();
	ASSERT_STREQ("", next_forgers.current_block());
	ASSERT_STREQ("", next_forgers.current_slot());
	ASSERT_STREQ("", next_forgers.delegates().description());
}
