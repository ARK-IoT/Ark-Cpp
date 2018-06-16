

#include "utilities/platform.h"

#ifndef USE_IOT

#include "models/transaction.h"
#include "utilities/json.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include <cstring>

namespace ARK
{
namespace Utilities
{
namespace
{
/**************************************************
*
**************************************************/
struct JSON :
		public JSONInterface
{
	private:
		json _json;

	public:
		/**************************************************
		*	Constructor
		**************************************************/
		JSON(
				std::string _jsonStr
		) : _json(!_jsonStr.empty() ? json::parse(_jsonStr) : json()) {}
		/*************************************************/

		/*************************************************/

		/**************************************************
		* valueFor(key)
		*
		* { "key1": value1, "key2": value2 }
		**************************************************/
		std::string valueFor(
				const char *const key
		) override
		{
			const auto& forKey = _json[key];
			return get_value(forKey);
		};
		/*************************************************/

		/**************************************************
		* valueIn(key, subkey)
		*
		* { "key": { "subkey": subvalue } }
		**************************************************/
		std::string valueIn(
				const char *const key,
				const char *const subkey
		) override
		{
			const auto& forKey = _json[key][subkey];
			return get_value(forKey);
		};
		/*************************************************/

		/**************************************************
		* subvalueFor(key, position)
		*
		* { "key": { subValue1, subvalue2 } }
		**************************************************/
		std::string subvalueFor(
				const char *const key,
				int pos
		) override
		{
			const auto& forKey = _json[key][pos];
			return get_value(forKey);
		};
		/*************************************************/
		
		/**************************************************
		* subarrayValueIn(key, position, subkey)
		*
		* { "key": [ { "subkey": subvalue } ] }
		**************************************************/
		std::string subarrayValueIn(
				const char *const key,
				int pos,
				const char *const subkey
		) override
		{
			const auto& forKey = _json[key][pos][subkey];
			return get_value(forKey);
		};
		/*************************************************/
		
		std::string transactionToJson(const Transaction& transaction) override {
			_json = {
				{ "type", static_cast<TransactionTypeIntType>(transaction.type()) },		// Transaction type. 0 = Normal transaction.
				{ "amount", std::strtoull(transaction.amount().arktoshi(), nullptr, 10) },	// The amount to send expressed as an integer value.
				{ "asset", {/* TODO:  add assert to ARK::Transaction */} },					// Transaction asset, dependent on tx type.
				{ "fee", std::strtoull(transaction.fee().arktoshi(), nullptr, 10) },		// The transaction fee expressed as an integer value.
				{ "id", transaction.id() },													// Transaction ID.
				{ "recipientId", transaction.recipient_id().getValue() }, // Recipient ID.
				{ "senderPublicKey", transaction.sender_publickey().getValue() }, // Sender's public key.
				{ "signature", transaction.signature().getValue() }, // Transaction signature.
				{ "timestamp", transaction.timestamp() } // Based on UTC time of genesis since epoch.
			};
			const auto& sign_signature = transaction.sign_signature();
			if (sign_signature) {
				_json["signSignature"] = sign_signature.getValue(); // Sender's second passphrase signature.
			}
			return _json.dump();
				/*
				{
				type: 0, // Transaction type. 0 = Normal transaction.
				amount: 100000000000, // The amount to send expressed as an integer value.
				asset: {}, // Transaction asset, dependent on tx type.
				fee: 100000000, // 0.1 ARK expressed as an integer value.
				id: "500224999259823996", // Transaction ID.
				recipientId: "AGihocTkwDygiFvmg6aG8jThYTic47GzU9", // Recipient ID.
				senderPublicKey: "56e106a1d4a53dbe22cac52fefd8fc4123cfb4ee482f8f25a4fc72eb459b38a5", // Sender's public key.
				signSignature: "03fdd33bed30270b97e77ada44764cc8628f6ad3bbd84718571695262a5a18baa37bd76a62dd25bc21beacd61eaf2c63af0cf34edb0d191d225f4974cd3aa509", // Sender's second passphrase signature.
				signature: "9419ca3cf11ed2e3fa4c63bc9a4dc18b5001648e74522bc0f22bda46a188e462da4785e5c71a43cfc0486af08d447b9340ba8b93258c4c7f50798060fff2d709", // Transaction signature.
				timestamp: 27953413 // Based on UTC time of genesis since epoch.
				}
				*/
		}

	private:
		/*************************************************/
		std::string get_value(
				const json& j
		) const
		{
			if ( j.is_string() )
			{
				return j.get<std::string>();
			}
			std::ostringstream ss;
			ss << j;
			std::string jStr = ss.str();
			return jStr;
		}
		/*************************************************/	

};
		
};

/*************************************************/
std::unique_ptr<JSONInterface> make_json_string(
		std::string json_str /* = std::string()*/
)
{
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};

#endif
