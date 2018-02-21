#include "gtest/gtest.h"

#include "api.h"

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

	ASSERT_STREQ("", _arkManager.blockEpoch().c_str());

	const auto height = _arkManager.blockHeight();
	ASSERT_STREQ("", height.id());
	ASSERT_STREQ("", height.height());

	ASSERT_STREQ("", _arkManager.blockNethash().description());

	const auto block_fee = _arkManager.blockFee();
	ASSERT_STREQ("", block_fee.ark());
	ASSERT_STREQ("", block_fee.arktoshi());

	const auto fees = _arkManager.blockFees();
	ASSERT_STREQ("", fees.send().arktoshi());
	ASSERT_STREQ("", fees.vote().arktoshi());
	ASSERT_STREQ("", fees.delegate().arktoshi());
	ASSERT_STREQ("", fees.second_signature().arktoshi());
	ASSERT_STREQ("", fees.multi_signature().arktoshi());

	ASSERT_STREQ("", _arkManager.blockMilestone().c_str());

	const auto block_reward = _arkManager.blockReward();
	ASSERT_STREQ("", block_reward.ark());
	ASSERT_STREQ("", block_reward.arktoshi());



	/*  ==================================  */
	const auto block_supply = _arkManager.blockSupply();
	ASSERT_STREQ("", block_supply.ark());
	ASSERT_STREQ("", block_supply.arktoshi());

	
	const auto block_status = _arkManager.blockStatus();
	ASSERT_STREQ("", block_status.epoch());
	ASSERT_STREQ("", block_status.height());
	const auto& fee = block_status.fee();
	ASSERT_STREQ("", fee.ark());
	ASSERT_STREQ("", fee.arktoshi());
	ASSERT_EQ(0, block_status.milestone());
	ASSERT_STREQ("", block_status.nethash().description());
	const auto& reward = block_status.reward();
	ASSERT_STREQ("", reward.ark());
	ASSERT_STREQ("", reward.arktoshi());
	const auto& supply = block_status.supply();
	ASSERT_STREQ("", supply.ark());
	ASSERT_STREQ("", supply.arktoshi());
}
