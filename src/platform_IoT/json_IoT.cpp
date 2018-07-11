

#include "utilities/platform.h"
#include "models/transaction.h"
#include "utilities/json.h"

#include "ArduinoJson.h"

#include <cstring>
#include <memory>

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
		const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
		std::string jsonStr;

	public:
		/**************************************************
		*
		**************************************************/
		JSON(
				std::string _jsonStr
		)
		{
			jsonStr = _jsonStr;
		}
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
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key].as<const char*>());
		}
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
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][subkey].as<const char*>());
		}
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
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][pos].as<const char*>());
		}
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
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][pos][subkey].as<const char*>());
		}
		/*************************************************/

		std::string transactionToJson(const Transaction& transaction) override {
			const size_t BUFFER_SIZE = 1024;

			StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
			JsonObject& root = jsonBuffer.createObject();
			root["type"] = static_cast<TransactionTypeIntType>(transaction.type());				// Transaction type. 0 = Normal transaction.
			root.set<long>("amount", strtoull(transaction.amount().arktoshi(), nullptr, 10));	// The amount to send expressed as an integer value.
			root.set<long>("fee", strtoull(transaction.fee().arktoshi(), nullptr, 10));			// The transaction fee expressed as an integer value.
			root["id"] = transaction.id();														// Transaction ID.
			root["recipientId"] = transaction.recipient_id().getValue();						// Recipient ID.
			root["senderPublicKey"] = transaction.sender_publickey().getValue();				// Sender's public key.
			root["signature"] = transaction.signature().getValue();								// Transaction signature.
			root["timestamp"] = transaction.timestamp();										// Based on UTC time of genesis since epoch.

			const auto& sign_signature = transaction.sign_signature();
			if (sign_signature) {
				root["signSignature"] = sign_signature.getValue(); // Sender's second passphrase signature.
			}
			if (transaction.vendor_field()[0] != '\0') {
				root["vendorField"] = transaction.vendor_field();
			}
			char buf[BUFFER_SIZE] = {};

			root.printTo<BUFFER_SIZE>(buf);
			return buf;
		}
};

}

/**************************************************
* make_json_string
**************************************************/
std::unique_ptr<JSONInterface> make_json_string(
	std::string json_str /* = std::string() */
)
{
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};
