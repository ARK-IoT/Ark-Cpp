#include "gtest/gtest.h"

#include "api.h"

TEST(transaction, test_transaction) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const Hash transactionID("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e");
	const auto transaction = _arkManager.transaction(transactionID);
	ASSERT_STREQ("", transaction.id());
	ASSERT_STREQ("", transaction.block_id());
	ASSERT_STREQ("", transaction.height());
	ASSERT_EQ(0, transaction.type());
	ASSERT_STREQ("", transaction.timestamp());
	ASSERT_STREQ("", transaction.amount().arktoshi());
	ASSERT_STREQ("", transaction.fee().arktoshi());
	ASSERT_STREQ("", transaction.vendor_field());
	ASSERT_STREQ("", transaction.sender_id().description());
	ASSERT_STREQ("", transaction.recipient_id().description());
	ASSERT_STREQ("", transaction.sender_publickey().description());
	ASSERT_STREQ("", transaction.signature());
	ASSERT_STREQ("", transaction.confirmations());


	/*  ==================================  */
	/*  ==================================  */
	/*    BROKEN: fix for large callbacks  */
	/*    Peers callback is ~28,908 bytes  */
	//  String transactions = _arkManager.transactions();
	//    Serial.println("transactions: ");
	//    Serial.println(transactions);
	//    Serial.println("\n=====\n");
	//    delay(50);
	/*  ==================================  */
	/*  ==================================  */

	/*  ==================================  */
	ASSERT_STREQ("", _arkManager.transactionUnconfirmed(transactionID).c_str());
	ASSERT_STREQ("", _arkManager.transactionsUnconfirmed().c_str());
}
