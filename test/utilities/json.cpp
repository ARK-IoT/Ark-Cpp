#include "gtest/gtest.h"

#include "utilities/platform.h"
#include "utilities/json.h"
#include "models/transaction.h"
#include "crypto/ark_crypto.h"
#include "crypto/util.h"

TEST(utilities, transactionToJson) {
	static const auto expected_json = "{";
	"\"type\":0," // Transaction type. 0 = Normal transaction.
	"\"amount\":100000000000,"// The amount to send expressed as an integer value.
	"\"asset\":{}," // Transaction asset, dependent on tx type.
	"\"fee\":100000000," // 0.1 ARK expressed as an integer value.
	"\"id\":\"500224999259823996\"," // Transaction ID.
	"\"recipientId\":\"AGihocTkwDygiFvmg6aG8jThYTic47GzU9\"," // Recipient ID.
	"\"senderPublicKey\":\"56e106a1d4a53dbe22cac52fefd8fc4123cfb4ee482f8f25a4fc72eb459b38a5\"," // Sender's public key.
	"\"signSignature\":\"03fdd33bed30270b97e77ada44764cc8628f6ad3bbd84718571695262a5a18baa37bd76a62dd25bc21beacd61eaf2c63af0cf34edb0d191d225f4974cd3aa509\"," // Sender's second passphrase signature.
	"\"signature\":\"9419ca3cf11ed2e3fa4c63bc9a4dc18b5001648e74522bc0f22bda46a188e462da4785e5c71a43cfc0486af08d447b9340ba8b93258c4c7f50798060fff2d709\"," // Transaction signature.
	"\"timestamp\":27953413" // Based on UTC time of genesis since epoch.
	"}";

	auto secret = ParseHex("passphrase");
	auto second_secret = ParseHex("secondPassphrase");
	auto t = ARK::Crypto::create_transaction(
		ARK::Constants::Networks::Network_ADV::main.pubKeyHash, 
		"AGihocTkwDygiFvmg6aG8jThYTic47GzU9", 
		100000000000u, 
		std::string(), 
		&secret[0], 
		&second_secret[0]
	);
	auto json = ARK::Utilities::make_json_string();
	const auto json_str = json->transactionToJson(t);
	
	ASSERT_STREQ(expected_json, json_str.c_str());
}
