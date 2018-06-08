

#include "api/transactionable/transaction_gettable.h"

namespace ARK
{
namespace API
{
namespace Transaction
{
/*************************************************
* ARK::API::Transaction::Gettable::transaction
*	/api/transactions/get?id=
*
*	{
*		"success":true,
*		"transaction":
*		{
*			"id":"_txID",
*			"blockid":"_blockID",
*			"height":_height,
*			"type":_type,
*			"timestamp":_timestamp,
*			"amount":_amount,
*			"fee":_fee,
*			"vendorField":"_vendorField",
*			"senderId":"_senderID",
*			"recipientId":"_recipientID",
*			"senderPublicKey":"_senderPubkey",
*			"signature":"_txSig",
*			"confirmations":_confirmations
*		}
*	}
**************************************************/
ARK::Transaction ARK::API::Transaction::Gettable::transaction(
		ARK::Utilities::Network::Connector& netConnector, 
		const Hash& id
)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, id.getValue());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueIn("transaction", "id").c_str(),
		parser->valueIn("transaction", "blockid").c_str(),
		parser->valueIn("transaction", "height").c_str(),
		static_cast<TransactionType>(convert_to_int(parser->valueIn("transaction", "type"))),
		static_cast<uint32_t>(convert_to_int(parser->valueIn("transaction", "timestamp"))),
		convert_to_double(parser->valueIn("transaction", "amount")),
		convert_to_double(parser->valueIn("transaction", "fee")),
		parser->valueIn("transaction", "vendorField").c_str(),
		parser->valueIn("transaction", "senderId").c_str(),
		parser->valueIn("transaction", "recipientId").c_str(),
		parser->valueIn("transaction", "senderPublicKey").c_str(),
		parser->valueIn("transaction", "signature").c_str(),
		parser->valueIn("transaction", "confirmations").c_str()
	};
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Transaction::Gettable::transactionUnconfirmed
*	/api/transactions/unconfirmed/get?id=
*
*	{ 
*		"success":true,
*		"transaction":
*		{
*			"id":"_txID",
*			"blockid":"_blockID",
*			"height":_height,
*			"type":_type,
*			"timestamp":_timestamp,
*			"amount":_amount,
*			"fee":_fee,
*			"vendorField":_vendorField,
*			"senderId":"_senderId",
*			"recipientId":"_recipientId",
*			"senderPublicKey":_senderPubkey,
*			"signature":"_txSig",
*			"confirmations":_confirmations
*		}
*	}
*		| or |
*	{
*		"success":false,
*		"error":"Transaction not found"
*	}
**************************************************/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionUnconfirmed(
		ARK::Utilities::Network::Connector &netConnector,
		const Hash &id)
{
	char uri[126 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
		strcat(uri, "?id=");
		strcat(uri, id.getValue());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);

	int txCount = substringCount(callback.c_str(), "id");
	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);

	for (int i = 0; i < txCount; i++)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id").c_str(),
			parser->valueIn("transaction", "blockid").c_str(),
			parser->valueIn("transaction", "height").c_str(),
			static_cast<TransactionType>(convert_to_int(parser->valueIn("transaction", "type").c_str())),
			convert_to_int(parser->valueIn("transaction", "timestamp")),
			convert_to_double(parser->valueIn("transaction", "amount")),
			convert_to_double(parser->valueIn("transaction", "fee")),
			parser->valueIn("transaction", "vendorField").c_str(),
			parser->valueIn("transaction", "senderId").c_str(),
			parser->valueIn("transaction", "recipientId").c_str(),
			parser->valueIn("transaction", "senderPublicKey").c_str(),
			parser->valueIn("transaction", "signature").c_str(),
			parser->valueIn("transaction", "confirmations").c_str()
		);
	};
	return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Transaction::Gettable::transactionsUnconfirmed
*	/api/transactions/unconfirmed
*
*	{
*		"success":true,
*		"transactions":[]
*	}
**************************************************/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionsUnconfirmed(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Transaction::unconfirmed_s);
	auto parser = ARK::Utilities::make_json_string(callback);

	int txCount = substringCount(callback.c_str(), "id");
	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);

	for (int i = 0; i < txCount; ++i)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id").c_str(),
			parser->valueIn("transaction", "blockid").c_str(),
			parser->valueIn("transaction", "height").c_str(),
			static_cast<TransactionType>(convert_to_int(parser->valueIn("transaction", "type"))),
			static_cast<uint32_t>(convert_to_int(parser->valueIn("transaction", "timestamp"))),
			convert_to_double(parser->valueIn("transaction", "amount")),
			convert_to_double(parser->valueIn("transaction", "fee")),
			parser->valueIn("transaction", "vendorField").c_str(),
			parser->valueIn("transaction", "senderId").c_str(),
			parser->valueIn("transaction", "recipientId").c_str(),
			parser->valueIn("transaction", "senderPublicKey").c_str(),
			parser->valueIn("transaction", "signature").c_str(),
			parser->valueIn("transaction", "confirmations").c_str()
		);
	};
	return { transactions.get(), txCount };
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Transaction::Gettable::vendorField
*	/api/transactions/get?id=
*
*	@brief:	This gets the vendorField from a given Transaction ID  
**************************************************/
const char* ARK::API::Transaction::Gettable::vendorField(
		ARK::Utilities::Network::Connector &netConnector,
		const Hash &txID
)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, txID.getValue());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return parser->valueIn("transaction", "vendorField").c_str();
}
/*************************************************/

};
};
};
