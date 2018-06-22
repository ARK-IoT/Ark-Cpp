#include "gtest/gtest.h"

#include "utilities/platform.h"
#include "utilities/json.h"
#include "models/transaction.h"
#include "crypto/ark_crypto.h"
#include "crypto/util.h"

TEST(utilities, transactionToJson) {
	static const auto expected_json = "{"
	"\"amount\":1000,"// The amount to send expressed as an integer value.
	"\"asset\":{}," // Transaction asset, dependent on tx type.
	"\"fee\":10000000," // 0.1 ARK expressed as an integer value.
	"\"id\":\"9d327fb1f26f1824a727ee58df60d3c646513ffb930e1959ea893e7a882dbba8\"," // Transaction ID.
	"\"recipientId\":\"AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff\"," // Recipient ID.
	"\"senderPublicKey\":\"03a02b9d5fdd1307c2ee4652ba54d492d1fd11a7d1bb3f3a44c4a05e79f19de933\"," // Sender's public key.
	//"\"signSignature\":\"\"," // Sender's second passphrase signature.
	"\"signature\":\"30440220687b0059bfcc11bcd023bf057bd82fab76ee09f78080a171c46e70961b4ed2d5022043a92debb946d7afdb0735eae2c497651bed08a73e541e0f88a72173bc8ddc62\"," // Transaction signature.
	"\"timestamp\":27953413" // Based on UTC time of genesis since epoch.
	"\"type\":0," // Transaction type. 0 = Normal transaction.
	"}";

	uint8_t priv_key[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	std::vector<uint8_t> pub_key(ARK::Crypto::COMPRESSED_PUBLIC_KEY_SIZE);
	ARK::Crypto::get_keys("secret", priv_key, pub_key);
	auto t = ARK::Crypto::create_transaction(
		ARK::Constants::Networks::Network_ADV::main.pubKeyHash, 
		"AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff", 
		1000u, 
		std::string(), 
		priv_key
	);
	auto json = ARK::Utilities::make_json_string();
	const auto json_str = json->transactionToJson(t);
	
	ASSERT_STREQ(expected_json, json_str.c_str());
}
