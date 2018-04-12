#include "api/transactionable/transaction_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "helpers/subcount.h"
#include "types/hash.h"
#include "utilities/connector.h"

#include <cstring>
#include <memory>

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
	char uri[512] = { '\0' }; //TODO review sizes

	strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
	strcat(uri, "?id=");
	strcat(uri, id.getValue());

	auto callback = netConnector.cb(uri);

  auto parser = ARK::Utilities::make_json_string(callback);

	return {
		parser->valueIn("transaction", "id"),
		parser->valueIn("transaction", "blockid"),
		parser->valueIn("transaction", "height"),
		atoi(parser->valueIn("transaction", "type")),
		parser->valueIn("transaction", "timestamp"),
		parser->valueIn("transaction", "amount"),
		parser->valueIn("transaction", "fee"),
		parser->valueIn("transaction", "vendorField"),
		parser->valueIn("transaction", "senderId"),
		parser->valueIn("transaction", "recipientId"),
		parser->valueIn("transaction", "senderPublicKey"),
		parser->valueIn("transaction", "signature"),
		parser->valueIn("transaction", "confirmations")
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
	char uri[256] = {'\0'}; //TODO review sizes
		strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
		strcat(uri, "?id=");
		strcat(uri, id.getValue());

	auto callback = netConnector.cb(uri);

	int txCount = subCount(callback, "id");

	auto parser = ARK::Utilities::make_json_string(callback);

	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);

	for (int i = 0; i < txCount; i++)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id"),
			parser->valueIn("transaction", "blockid"),
			parser->valueIn("transaction", "height"),
			atoi(parser->valueIn("transaction", "type")),
			parser->valueIn("transaction", "timestamp"),
			parser->valueIn("transaction", "amount"),
			parser->valueIn("transaction", "fee"),
			parser->valueIn("transaction", "vendorField"),
			parser->valueIn("transaction", "senderId"),
			parser->valueIn("transaction", "recipientId"),
			parser->valueIn("transaction", "senderPublicKey"),
			parser->valueIn("transaction", "signature"),
			parser->valueIn("transaction", "confirmations")
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
	auto callback = netConnector.cb(ARK::API::Paths::Transaction::unconfirmed_s);

	int txCount = subCount(callback, "id");

	auto parser = ARK::Utilities::make_json_string(callback);
	
	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);

	for (int i = 0; i < txCount; ++i)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id"),
			parser->valueIn("transaction", "blockid"),
			parser->valueIn("transaction", "height"),
			convert_to_int(parser->valueIn("transaction", "type")),
			parser->valueIn("transaction", "timestamp"),
			parser->valueIn("transaction", "amount"),
			parser->valueIn("transaction", "fee"),
			parser->valueIn("transaction", "vendorField"),
			parser->valueIn("transaction", "senderId"),
			parser->valueIn("transaction", "recipientId"),
			parser->valueIn("transaction", "senderPublicKey"),
			parser->valueIn("transaction", "signature"),
			parser->valueIn("transaction", "confirmations")
		);
	};

	return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Transaction::Gettable::vendorField
*	/api/transactions/get?id=
*
*	@brief:	This gets the vendorField from a given Transaction ID  
**************************************************/
const char *ARK::API::Transaction::Gettable::vendorField(
		ARK::Utilities::Network::Connector &netConnector,
		const Hash &txID
)
{
	char uri[90] = {'\0'}; //TODO review sizes
		strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, txID.getValue());

	auto callback = netConnector.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);

	return parser->valueIn("transaction", "vendorField");
}
/*************************************************/

};
};
};
