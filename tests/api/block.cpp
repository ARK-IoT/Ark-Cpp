#include "api.h"

#include "gtest/gtest.h"

TEST(block, test_block) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto block = _arkManager.block("4367122150875693402");
	ASSERT_STREQ("4367122150875693402", block.id());
	ASSERT_EQ(0, block.version());
	ASSERT_STREQ("", block.timestamp());
	ASSERT_STREQ("", block.height());
	ASSERT_STREQ("", block.previous_block());
	ASSERT_STREQ("", block.number_of_transactions());
	ASSERT_STREQ("", block.total_amount().arktoshi());
	ASSERT_STREQ("", block.total_fee().arktoshi());
	ASSERT_STREQ("", block.reward().arktoshi());
	ASSERT_STREQ("", block.payload_length());
	ASSERT_STREQ("", block.payload_hash().description());
	ASSERT_STREQ("", block.generator_public_key().description());
	ASSERT_STREQ("", block.generator_id().description());
	ASSERT_STREQ("", block.block_signature().description());
	ASSERT_STREQ("", block.confirmations());
	ASSERT_STREQ("", block.total_forged().arktoshi());


	/*  ==================================  */
	/* needs stream->string size fix for large callbacks */
	//  String blocks = _arkManager.blocks();
	//    Serial.println(blocks);
	//    Serial.println();
	//    delay(50);
	/*  ==================================  */

	ASSERT_STREQ("", _arkManager.blockEpoch());

	const auto height = _arkManager.blockHeight();
	ASSERT_STREQ("", height.id());
	ASSERT_STREQ("", height.height());

	/*  ==================================  */
	const auto blockNethashDescription = _arkManager.blockNethash().description();
	Serial.println("blockNethashDescription: ");
	Serial.println(blockNethashDescription);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	const auto blockFeeArk = _arkManager.blockFee().ark();
	Serial.println("blockFeeArk: ");
	Serial.println(blockFeeArk);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	_arkManager.blockFees().description(buf, sizeof(buf));
	Serial.println("blockFeesDescription: ");
	Serial.println(buf);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	const auto blockMilestone = _arkManager.blockMilestone();
	Serial.println("blockMilestone: ");
	Serial.println(blockMilestone);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	const auto blockRewardArk = _arkManager.blockReward().ark();
	Serial.println("blockRewardArk: ");
	Serial.println(blockRewardArk);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	const auto blockSupplyArk = _arkManager.blockSupply().ark();
	Serial.println("blockSupplyArk: ");
	Serial.println(blockSupplyArk);
	Serial.println("\n=====\n");
	delay(50);
	/*  ==================================  */

	/*  ==================================  */
	_arkManager.blockStatus().description(buf, sizeof(buf));
	Serial.println("blockStatusDescription: ");
	Serial.println(buf);
	delay(50);

}