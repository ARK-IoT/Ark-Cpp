

#include "api/accountable/account_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "utilities/connector.h"

namespace ARK
{
namespace API
{
namespace Account
{
/*************************************************
*	ARK::API::Account::Gettable::balance
*	/api/accounts/getBalance?address=arkAddress
*
*	{
*		"success":true,
*		"balance":  "Balance",
*		"unconfirmedBalance": "Balance"
*	}
**************************************************/
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balance(
		ARK::Utilities::Network::Connector &netManager,
		const Address &arkAddress
)
{
	char uri[256] = {'\0'}; // TODO: check size
		strcpy(uri, ARK::API::Paths::Account::getBalance_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());

	auto callback = netManager.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("balance"),
		parser->valueFor("unconfirmedBalance")
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Gettable::publickey
*	/api/accounts/getPublickey?address=arkAddress
*
/*************************************************
*	{
*		"success":true,
*		"publicKey":  "Publickey"
*	}
**************************************************/
Publickey ARK::API::Account::Gettable::publickey(
		ARK::Utilities::Network::Connector &netManager,
		const Address &arkAddress
)
{
	char uri[256] = {'\0'}; // TODO:  check size
		strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());

	auto callback = netManager.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);
	return Publickey(parser->valueFor("publicKey"));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Gettable::delegatesFee
*	/api/accounts/delegates/fee?address=arkAddress
*
*	{
*		"success":true,
*		"fee":2500000000
*	}
**************************************************/
Balance ARK::API::Account::Gettable::delegatesFee(
		ARK::Utilities::Network::Connector &netManager,
		const Address &arkAddress
)
{
	char uri[256] = {'\0'}; // TODO:  check size
		strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());

	auto callback = netManager.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(parser->valueFor("fee"));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Gettable::delegates
*	/api/accounts/delegates?address=arkAddress
*
*	{
*		"success":true,
*		"delegates":
*		[
*			{
*				"username": "sleepdeficit",
*				"address":  "Address",
*				"publicKey":  "Publickey",
*				"vote": "Balance",
*				"producedblocks": const char*,
*				"missedblocks": String,
*				"rate": int,
*				"approval": double,
*				"productivity": double
*			}
*		]
*	}
**************************************************/
ARK::Delegate ARK::API::Account::Gettable::delegates(
		ARK::Utilities::Network::Connector &netManager,
		const Address &arkAddress
)
{
	char uri[256] = {'\0'}; // TODO:  check size
		strcpy(uri, ARK::API::Paths::Account::delegates_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());

	auto callback = netManager.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->subarrayValueIn("delegates", 0, "username"),
		parser->subarrayValueIn("delegates", 0, "address"),
		parser->subarrayValueIn("delegates", 0, "publicKey"),
		parser->subarrayValueIn("delegates", 0, "vote"),
		atoi(parser->subarrayValueIn("delegates", 0, "producedblocks")),
		atoi(parser->subarrayValueIn("delegates", 0, "missedblocks")),
		atoi(parser->subarrayValueIn("delegates", 0, "rate")),
		atof(parser->subarrayValueIn("delegates", 0, "approval")),
		atof(parser->subarrayValueIn("delegates", 0, "productivity"))
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Gettable::account
*	/api/accounts?address=arkAddress 
*
*	{
*		"success":true,
*		"account":
*		{
*			"address":  "Address",
*			"unconfirmedBalance": "Balance",
*			"balance":  "Balance",
*			"publicKey":  "Publickey",
*			"unconfirmedSignature": int,
*			"secondSignature":  int,
*			"secondPublicKey":  "Publickey",
*			"multisignatures":[],
*			"u_multisignatures":[]
*		}
*	}
**************************************************/
ARK::Account ARK::API::Account::Gettable::account(
		ARK::Utilities::Network::Connector &netManager,
		const Address &arkAddress
)
{
	char uri[81 + 1] = {'\0'}; // TODO:  check size
		strcpy(uri, ARK::API::Paths::Account::accounts_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());

	auto callback = netManager.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);

	return {
		parser->valueIn("account", "address"),
		parser->valueIn("account", "unconfirmedBalance"),
		parser->valueIn("account", "balance"),
		parser->valueIn("account", "publicKey"),
		atoi(parser->valueIn("account", "unconfirmedSignature")),
		atoi(parser->valueIn("account", "secondSignature")),
		parser->valueIn("account", "secondPublicKey"),
		parser->valueIn("account", "multisignatures"),
		parser->valueIn("account", "u_multisignatures")
	};
};
/*************************************************/

};
};
};
