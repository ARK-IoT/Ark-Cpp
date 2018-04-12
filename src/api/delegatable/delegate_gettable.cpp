#include "api/delegatable/delegate_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "api/helpers.h"
#include "helpers/subcount.h"

namespace ARK
{
namespace API
{
namespace Delegate
{
/*************************************************
* ARK::API::Delegate::Gettable::count
*	/api/delegates/count
*
*	{ 
*		"success":true,
*		"count":166
*	}
**************************************************/
int ARK::API::Delegate::Gettable::count(
    ARK::Utilities::Network::Connector &netConnector
)
{
  auto callback = netConnector.cb(ARK::API::Paths::Delegate::count_s);
	auto parser = ARK::Utilities::make_json_string(callback);
  return atoi(parser->valueFor("count"));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::search
* /api/delegates/search?q=sleepdeficit
*
*	{ 
*		"success":true,
*		"delegates":
*		[
*			{ 
*				"username":"_username",
*				"address":"_arkAddress",
*				"publicKey":"_pubkey",
*				"vote":"0000000000000",
*				"producedblocks":0,
*				"missedblocks":0
*			}
*		]
*	}
**************************************************/
ARK::API::Delegate::Respondable::Search ARK::API::Delegate::Gettable::search(
    ARK::Utilities::Network::Connector &_netConnector,
    const char *const username
)
{
  char uri[64] = {'\0'}; //TODO review size
    strcpy(uri, ARK::API::Paths::Delegate::search_s);
    strcat(uri, "?q=");
    strcat(uri, username);

  auto callback = _netConnector.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);

  return {
    parser->subarrayValueIn("delegates", 0, "username"),
    parser->subarrayValueIn("delegates", 0, "address"),
    parser->subarrayValueIn("delegates", 0, "publicKey"),
    parser->subarrayValueIn("delegates", 0, "vote"),
    atoi(parser->subarrayValueIn("delegates", 0, "producedblocks")),
    atoi(parser->subarrayValueIn("delegates", 0, "missedblocks"))
  };
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::voters
*	/api/delegates/voters?publicKey=_pubKey
*
*	{
*		"success":true,
*		"accounts":
*		[
*			{ 
*				"username": "const char*",
*				"address":  "Balance",
*				"publicKey":  "Publickey",
*				"balance":  "Balance"
*			},
*			{
*				"username": "const char*",
*				"address":  "Address",
*				"publicKey":  "Publickey",
*				"balance":  "Balance"
*			}
*		]
*	}
**************************************************/
ARK::API::Delegate::Respondable::Voters ARK::API::Delegate::Gettable::voters(
    ARK::Utilities::Network::Connector &netConnector,
    const Publickey &publicKey
)
{
  char uri[256] = {'\0'}; //TODO review size
    strcpy(uri, ARK::API::Paths::Delegate::voters_s);
    strcat(uri, "?publicKey=");
    strcat(uri, publicKey.getValue());

  auto callback = netConnector.cb(uri);

	int voterCount = subCount(callback, "username");

	auto parser = ARK::Utilities::make_json_string(callback);

  ARK::API::Delegate::Respondable::Voters voters(voterCount);

  for (int i = 0; i < voterCount; ++i)
  {
    voters[i] = {
      parser->subarrayValueIn("accounts", i, "username"),
      parser->subarrayValueIn("accounts", i, "address"),
      parser->subarrayValueIn("accounts", i, "publicKey"),
      parser->subarrayValueIn("accounts", i, "balance")
    };
  };
  return voters;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::delegate
*	/api/delegates/get?username=sleepdeficit
*	/api/delegates/get?publicKey=_pubKey
*
*	{ 
*		"success":true,
*		"delegate":
*		{
*			"username": "sleepdeficit",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": const char*,
*			"rate": int,
*			"approval": double,
*			"productivity": double
*		}
*	}
**************************************************/
ARK::Delegate ARK::API::Delegate::Gettable::delegate(
    ARK::Utilities::Network::Connector &netConnector,
    const char *const parameter
)
{
  char uri[512] = {'\0'}; //TODO: review sizes
  strcpy(uri, ARK::API::Paths::Delegate::get_s);

  if (strlen(parameter) > 20)
  {
    strcat(uri, "?publicKey=");
  }
  else
  {
    strcat(uri, "?username=");
  };
  strcat(uri, parameter);

  auto callback = netConnector.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);

  return {
    parser->valueIn("delegate", "username"),
    parser->valueIn("delegate", "address"),
    parser->valueIn("delegate", "publicKey"),
    parser->valueIn("delegate", "vote"),
    atoi(parser->valueIn("delegate", "producedblocks")),
    atoi(parser->valueIn("delegate", "missedblocks")),
    atoi(parser->valueIn("delegate", "rate")),
    atof(parser->valueIn("delegate", "approval")),
    atof(parser->valueIn("delegate", "productivity"))
  };
};
/*************************************************/

/**************************************************************************************************/

/*************************************************/
/*************************************************/
/*	BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
// String delegates(ARK::Utilities::Network::Connector _netConnector);
// String delegatesfromJSON(String _jsonStr);
/*************************************************/
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::fee
*	/api/delegates/fee
*	
*	{
*		"success":true,
*		"fee":  Balance
*	}
**************************************************/
Balance ARK::API::Delegate::Gettable::fee(
    ARK::Utilities::Network::Connector &netConnector
)
{
  auto callback = netConnector.cb(ARK::API::Paths::Delegate::fee_s);

	auto parser = ARK::Utilities::make_json_string(callback);

  return Balance(parser->valueFor("fee"));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::forgedByAccount
*	/api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
*
*	{
*		"success":true,
*		"fees": "Balance",
*		"rewards":  "Balance",
*		"forged": "Balance"
*	}
**************************************************/
ARK::API::Delegate::Respondable::ForgedByAccount ARK::API::Delegate::Gettable::forgedByAccount(
    ARK::Utilities::Network::Connector &netConnector,
    const Publickey &generatorPublicKey
)
{
  char uri[512] = {'\0'}; //TODO: review sizes
  	strcpy(uri, ARK::API::Paths::Delegate::getForgedByAccount_s);
  	strcat(uri, "?generatorPublicKey=");
  	strcat(uri, generatorPublicKey.getValue());

  auto callback = netConnector.cb(uri);

	auto parser = ARK::Utilities::make_json_string(callback);

  return {
		parser->valueFor("fees"),
		parser->valueFor("rewards"),
		parser->valueFor("forged")
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Gettable::nextForgers
*	/api/delegates/getNextForgers
*
*	{ 
*		"success":true,
*		"currentBlock":2307497,
*		"currentSlot":3189409,
*		"delegates":
*		[
*			"035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
*			"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*			"028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
*			"027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
*			"02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
*			"0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
*			"02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
*			"02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
*			"022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
*			"031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
*		]
*	}
**************************************************/
ARK::API::Delegate::Respondable::NextForgers ARK::API::Delegate::Gettable::nextForgers(
    ARK::Utilities::Network::Connector &netConnector
)
{
  auto callback = netConnector.cb(ARK::API::Paths::Delegate::getNextForgers_s);

	auto parser = ARK::Utilities::make_json_string(callback);

  Publickey delegateKeys[10];
  for (int i = 0; i < 10; ++i)
  {
    delegateKeys[i] = parser->subvalueFor("delegates", i);
  };
	
  return {
    atoi(parser->valueFor("currentBlock")),
    atoi(parser->valueFor("currentSlot")),
    delegateKeys
  };
};
/*************************************************/

};
};
};
