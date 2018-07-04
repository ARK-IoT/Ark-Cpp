#include "gtest/gtest.h"

#include "utilities/platform.h"
#include "utilities/json.h"
#include "models/transaction.h"
#include "crypto/ark_crypto.h"
#include "crypto/util.h"

TEST(utilities, transactionToJson) {
	const auto expected_json = "{"
	"\"amount\":1000,"// The amount to send expressed as an integer value.
		"\"fee\":10000000," // 0.1 ARK expressed as an integer value.
		"\"id\":\"9d327fb1f26f1824a727ee58df60d3c646513ffb930e1959ea893e7a882dbba8\"," // Transaction ID.
		"\"recipientId\":\"AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff\"," // Recipient ID.
		"\"senderPublicKey\":\"03a02b9d5fdd1307c2ee4652ba54d492d1fd11a7d1bb3f3a44c4a05e79f19de933\"," // Sender's public key.
		"\"signSignature\":\"30440220687b0059bfcc11bcd023bf057bd82fab76ee09f78080a171c46e70961b4ed2d5022043a92debb946d7afdb0735eae2c497651bed08a73e541e0f88a72173bc8ddc62\"," // Sender's second passphrase signature.
		"\"signature\":\"30440220687b0059bfcc11bcd023bf057bd82fab76ee09f78080a171c46e70961b4ed2d5022043a92debb946d7afdb0735eae2c497651bed08a73e541e0f88a72173bc8ddc62\"," // Transaction signature.
		"\"timestamp\":27953413," // Based on UTC time of genesis since epoch.
		"\"type\":0," // Transaction type. 0 = Normal transaction.
		"\"vendorField\":\"test_transaction\""
	"}";

	const ARK::Transaction t(
		"9d327fb1f26f1824a727ee58df60d3c646513ffb930e1959ea893e7a882dbba8",
		"",
		"",
		ARK::TransactionType::NORMAL,
		27953413,
		"1000",
		"10000000",
		"test_transaction",
		"",
		"AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff",
		"03a02b9d5fdd1307c2ee4652ba54d492d1fd11a7d1bb3f3a44c4a05e79f19de933",
		"30440220687b0059bfcc11bcd023bf057bd82fab76ee09f78080a171c46e70961b4ed2d5022043a92debb946d7afdb0735eae2c497651bed08a73e541e0f88a72173bc8ddc62",
		"30440220687b0059bfcc11bcd023bf057bd82fab76ee09f78080a171c46e70961b4ed2d5022043a92debb946d7afdb0735eae2c497651bed08a73e541e0f88a72173bc8ddc62",
		""
	);
	auto json = ARK::Utilities::make_json_string();
	const auto json_str = json->transactionToJson(t);
	
	ASSERT_STREQ(expected_json, json_str.c_str());
}
