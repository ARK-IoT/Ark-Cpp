

#include "api/accountable/account_gettable.h"

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
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::getBalance_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());
	auto callback = netManager.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("balance").c_str(),
		parser->valueFor("unconfirmedBalance").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Gettable::publickey
*	/api/accounts/getPublickey?address=arkAddress
*
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
	char uri[94 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());
	auto callback = netManager.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("publicKey").c_str()
	};
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
	char uri[95 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());
	auto callback = netManager.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(parser->valueFor("fee").c_str());
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
	char uri[91 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::delegates_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());
	auto callback = netManager.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->subarrayValueIn("delegates", 0, "username").c_str(),
		parser->subarrayValueIn("delegates", 0, "address").c_str(),
		parser->subarrayValueIn("delegates", 0, "publicKey").c_str(),
		parser->subarrayValueIn("delegates", 0, "vote").c_str(),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "producedblocks").c_str()),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "missedblocks").c_str()),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "rate").c_str()),
		convert_to_float(parser->subarrayValueIn("delegates", 0, "approval").c_str()),
		convert_to_float(parser->subarrayValueIn("delegates", 0, "productivity").c_str())
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
	char uri[81 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::accounts_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.getValue());
	auto callback = netManager.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);

		/********************
		*	FIXME 
		* multisignatures & u_multisignatures returns an array of Transaction ID's (Hash type)
		********************/

	return {
		parser->valueIn("account", "address").c_str(),
		parser->valueIn("account", "unconfirmedBalance").c_str(),
		parser->valueIn("account", "balance").c_str(),
		parser->valueIn("account", "publicKey").c_str(),
		convert_to_int(parser->valueIn("account", "unconfirmedSignature").c_str()),
		convert_to_int(parser->valueIn("account", "secondSignature").c_str()),
		parser->valueIn("account", "secondPublicKey").c_str(),

		// parser->subarrayValueIn("account", 0, "multisignatures").c_str(),	//	FIXME
		// multisigsArray,																										//	FIXME
		// parser->subarrayValueIn("account", 0, "u_multisignatures").c_str()	//	FIXME
		// u_multisigsArray																										//	FIXME

	};
};
/*************************************************/

};
};
};
