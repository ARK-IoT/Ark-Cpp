

#ifndef ACCOUNT_GETTABLE_H
#define ACCOUNT_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Account
{
/*************************************************
*  PROTECTED: ARK::API::Account::Gettable
**************************************************/
class Gettable
{
  protected:

		/*************************************************
		*	ARK::API::Account::Gettable::balance
		*		/api/accounts/getBalance?address=arkAddress
		**************************************************/
		ARK::API::Account::Respondable::Balances balance(
				ARK::Utilities::Network::Connector &netManager,
				const Address &arkAddress
		)
		{
			char uri[256] = {'\0'}; // TODO: check size
				strcpy(uri, ARK::API::Paths::Account::getBalance_s);
				strcat(uri, "?address=");
				strcat(uri, arkAddress.getValue());
			auto callback = netManager.cb(uri);
			return ARK::API::Account::Gettable::balancefromJSON(callback);
		};
		/*************************************************
		*
		*	{
		*		"success":true,
		*		"balance":  "Balance",
		*		"unconfirmedBalance": "Balance"
		*	}
		*
		**************************************************/
		ARK::API::Account::Respondable::Balances balancefromJSON(const char *const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
				parser.valueFor("balance"),
				parser.valueFor("unconfirmedBalance")
			};
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*	ARK::API::Account::Gettable::publickey
		*		/api/accounts/getPublickey?address=arkAddress
		**************************************************/
		Publickey publickey(
				ARK::Utilities::Network::Connector &netManager,
				const Address &arkAddress
		)
		{
			char uri[256] = {'\0'}; // TODO:  check size
				strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
				strcat(uri, "?address=");
				strcat(uri, arkAddress.getValue());
			auto callback = netManager.cb(uri);
			return ARK::API::Account::Gettable::publickeyfromJSON(callback);
		};
		/*************************************************
		*
		*	{
		*		"success":true,
		*		"publicKey":  "Publickey"
		*	}
		*
		**************************************************/
		Publickey publickeyfromJSON(const char *const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return Publickey(parser.valueFor("publicKey"));
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*	ARK::API::Account::Gettable::delegatesFee
		*		/api/accounts/delegates/fee?address=arkAddress
		**************************************************/
		Balance delegatesFee(
				ARK::Utilities::Network::Connector &netManager,
				const Address &arkAddress
		)
		{
			char uri[256] = {'\0'}; // TODO:  check size
				strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
				strcat(uri, "?address=");
				strcat(uri, arkAddress.getValue());
			auto callback = netManager.cb(uri);
			return ARK::API::Account::Gettable::delegatesFeefromJSON(callback);
		};
		/*************************************************
		*
		*	{
		*		"success":true,
		*		"fee":2500000000
		*	}
		*
		**************************************************/
		Balance delegatesFeefromJSON(const char *const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return Balance(parser.valueFor("fee"));
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*	ARK::API::Account::Gettable::delegates
		*		/api/accounts/delegates?address=arkAddress
		**************************************************/
		ARK::Delegate delegates(
				ARK::Utilities::Network::Connector &netManager,
				const Address &arkAddress
		)
		{
			char uri[256] = {'\0'}; // TODO:  check size
				strcpy(uri, ARK::API::Paths::Account::delegates_s);
				strcat(uri, "?address=");
				strcat(uri, arkAddress.getValue());
			auto callback = netManager.cb(uri);
			return ARK::API::Account::Gettable::delegatesfromJSON(callback);
		};
		/*************************************************
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
		*
		**************************************************/
		ARK::Delegate delegatesfromJSON(const char *const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
					parser.subarrayValueIn("delegates", 0, "username"),
					parser.subarrayValueIn("delegates", 0, "address"),
					parser.subarrayValueIn("delegates", 0, "publicKey"),
					parser.subarrayValueIn("delegates", 0, "vote"),
					atoi(parser.subarrayValueIn("delegates", 0, "producedblocks")),
					atoi(parser.subarrayValueIn("delegates", 0, "missedblocks")),
					atoi(parser.subarrayValueIn("delegates", 0, "rate")),
					atof(parser.subarrayValueIn("delegates", 0, "approval")),
					atof(parser.subarrayValueIn("delegates", 0, "productivity"))
			};
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*	ARK::API::Account::Gettable::account
		*		/api/accounts?address=arkAddress 
		**************************************************/
		ARK::Account account(
				ARK::Utilities::Network::Connector &netManager,
				const Address &arkAddress
		)
		{
			char uri[81 + 1] = {'\0'}; // TODO:  check size
				strcpy(uri, ARK::API::Paths::Account::accounts_s);
				strcat(uri, "?address=");
				strcat(uri, arkAddress.getValue());
			auto callback = netManager.cb(uri);
			return ARK::API::Account::Gettable::accountfromJSON(callback);
		};
		/*************************************************
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
		*
		**************************************************/
		ARK::Account accountfromJSON(const char *const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
				parser.valueIn("account", "address"),
				parser.valueIn("account", "unconfirmedBalance"),
				parser.valueIn("account", "balance"),
				parser.valueIn("account", "publicKey"),
				atoi(parser.valueIn("account", "unconfirmedSignature")),
				atoi(parser.valueIn("account", "secondSignature")),
				parser.valueIn("account", "secondPublicKey"),
				parser.valueIn("account", "multisignatures"),
				parser.valueIn("account", "u_multisignatures")
			};
		};
		/*************************************************/

};
/*************************************************/

};
};
};

#endif
