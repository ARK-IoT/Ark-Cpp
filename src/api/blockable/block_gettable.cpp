

#include "api/blockable/block_gettable.h"

namespace ARK
{
namespace API
{
namespace Block
{
/*************************************************
* ARK::API::Block::Gettable::block
*	api/blocks/get?id=_blockID
*
* {
*   "success":true,
*   "block":
*   {
*     "id": "const char*",
*     "version":  int,
*     "timestamp":  const char*,
*     "height": const char*,
*     "previousBlock":  "const char*",
*     "numberOfTransactions": const char*,
*     "totalAmount":  Balance,
*     "totalFee": Balance,
*     "reward": Balance,
*     "payloadLength":  const char*,
*     "payloadHash":  "Hash",
*     "generatorPublicKey": "Publickey",
*     "generatorId":  "Address",
*     "blockSignature": "Signature",
*     "confirmations":  const char*,
*     "totalForged":" Balance"
*   }
* }
**************************************************/
ARK::Block ARK::API::Block::Gettable::block(
    ARK::Utilities::Network::Connector &netConnector,
    const char *const blockId
)
{
  char uri[80] = { '\0' };
    strcpy(uri, ARK::API::Paths::Block::get_s);
    strcat(uri, "?id=");
    strcat(uri, blockId);
  auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
  return {
    parser->valueIn("block", "id").c_str(),
    convert_to_int(parser->valueIn("block", "version").c_str()),
    parser->valueIn("block", "timestamp").c_str(),
    parser->valueIn("block", "height").c_str(),
    parser->valueIn("block", "previousBlock").c_str(),
    parser->valueIn("block", "numberOfTransactions").c_str(),
    parser->valueIn("block", "totalAmount").c_str(),
    parser->valueIn("block", "totalFee").c_str(),
    parser->valueIn("block", "reward").c_str(),
    parser->valueIn("block", "payloadLength").c_str(),
    parser->valueIn("block", "payloadHash").c_str(),
    parser->valueIn("block", "generatorPublicKey").c_str(),
    parser->valueIn("block", "generatorId").c_str(),
    parser->valueIn("block", "blockSignature").c_str(),
    parser->valueIn("block", "confirmations").c_str(),
    parser->valueIn("block", "totalForged").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************/
/*************************************************
  *   BROKEN: fix for large callbacks
  *   blocks callback is ~63,712 bytes
  **************************************************/
/*************************************************/
/*************************************************
  *   /api/blocks
  **************************************************/
// String blocks(ARK::Utilities::Network::Connector _netConnector) {
// String blocksfromJSON(String jsonStr) {
/*************************************************/
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::epoch
*	/api/blocks/getEpoch
*
*	@param:	ARK::Utilities::Network::Connector &netConnector
*	@param:	char buffer[]
*
*	@brief: blockEpoch example: 2017-03-21T13:00:00.000Z
*
* {
*   "success":true,
*   "epoch":  "String"
* }
**************************************************/
void ARK::API::Block::Gettable::epoch(
    ARK::Utilities::Network::Connector &netConnector,
		char buffer[]
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getEpoch_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	strcpy(buffer, parser->valueFor("epoch").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::height 
*	/api/blocks/getHeight
*
* {
*   "success":true,
*   "height": String,
*   "id": "String"
* }
**************************************************/
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::height(
    ARK::Utilities::Network::Connector &netConnector
)
{
  auto callback = netConnector.callback(ARK::API::Paths::Block::getHeight_s);
	auto parser = ARK::Utilities::make_json_string(callback);
  return { parser->valueFor("height").c_str(), parser->valueFor("id").c_str() };
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::nethash
*	/api/blocks/getNethash 
*
* {
*   "success":true,
*   "nethash":  "Hash"
* }
**************************************************/
Hash ARK::API::Block::Gettable::nethash(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getNethash_s);
	auto parser = ARK::Utilities::make_json_string(callback);
  return Hash(parser->valueFor("nethash").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::fee 
*	/api/blocks/getFee
*
* {
*   "success":true,
*   "fee":  Balance
* }
**************************************************/
Balance ARK::API::Block::Gettable::fee(
    ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getFee_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(convert_to_double(parser->valueFor("fee")));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::fees
*	/api/blocks/getFees 
*
* {
*   "success":true,
*   "fees":
*   {
*     "send": Balance,
*     "vote": Balance,
*     "secondsignature": Balance,
*     "delegate": Balance,
*     "multisignature": Balance
*   }
* }
**************************************************/
ARK::Fees ARK::API::Block::Gettable::fees(
    ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getFees_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueIn("fees", "send").c_str(),
		parser->valueIn("fees", "vote").c_str(),
		parser->valueIn("fees", "secondsignature").c_str(),
		parser->valueIn("fees", "delegate").c_str(),
		parser->valueIn("fees", "multisignature").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::milestone
*	/api/blocks/getMilestone
*
* {
*   "success":true,
*   "milestone": String
* }
**************************************************/
const char *ARK::API::Block::Gettable::milestone(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getMilestone_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return parser->valueFor("milestone").c_str();
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::reward
*	/api/blocks/getReward
*
* { 
*   "success":true,
*   "reward": Balance
* }
**************************************************/
Balance ARK::API::Block::Gettable::reward(
    ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getReward_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(convert_to_double(parser->valueFor("reward")));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Gettable::supply
*	/api/blocks/getSupply
*
* {
*   "success":true,
*   "supply": Balance
* }
**************************************************/
Balance ARK::API::Block::Gettable::supply(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getSupply_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(convert_to_double(parser->valueFor("supply")));
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*  ARK::API::Block::Gettable::status 
*	api/blocks/getStatus
*
* {
*   "success":true,
*   "epoch":  "String",
*   "height": String,
*   "fee":  Balance,
*   "milestone":  String,
*   "nethash":" Hash",
*   "reward":_reward,
*   "supply":_supply
* }
**************************************************/
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::status(
    ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getStatus_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return ARK::API::Block::Respondable::Status(
		parser->valueFor("epoch").c_str(),
		parser->valueFor("height").c_str(),
		convert_to_double(parser->valueFor("fee")),
		convert_to_int(parser->valueFor("milestone").c_str()),
		parser->valueFor("nethash").c_str(),
		convert_to_double(parser->valueFor("reward")),
		convert_to_double(parser->valueFor("supply"))
	);
};
/*************************************************/

};
};
};


/**************************************************************************************************/
/*************************************************/
/*************************************************
*   BROKEN: fix for large callbacks
*   blocks callback is ~63,712 bytes
**************************************************/
/*************************************************/
/*************************************************
* ARK::API::Block::Gettable::blocks
*   /api/blocks
**************************************************/
// String blocks(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Block::blocks_s;
//   String callback = _netConnector.cb(uri);
//   if (callback.indexOf("false") >= 0) { return callback; };
//   return ARK::API::Block::Gettable::blocksfromJSON(callback);
// };

// /*
// {
//   "success":true,
//   "blocks":[
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     },
//     ...
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     }
//   ],
//   "count":2313747
// }
// */
/*************************************************
*
*
**************************************************/
// String blocksfromJSON(String jsonStr) {
//   ARK::Utilities::JSONString jString(jsonStr);
//   // ARK::Block block = {
//   //   jString.valueFor("id").toInt(),
//   //   jString.valueFor("version").toFloat(),
//   //   jString.valueFor("timestamp").toInt(),
//   //   jString.valueFor("height").toInt(),
//   //   jString.valueFor("previousBlock").toInt(),
//   //   jString.valueFor("numberOfTransactions").toInt(),
//   //   jString.valueFor("totalAmount").toFloat(),
//   //   jString.valueFor("totalFee").toFloat(),
//   //   jString.valueFor("reward").toInt(),
//   //   jString.valueFor("payloadLength").toInt(),
//   //   jString.valueFor("payloadHash"),
//   //   jString.valueFor("generatorPublicKey"),
//   //   jString.valueFor("generatorId"),
//   //   jString.valueFor("blockSignature"),
//   //   jString.valueFor("confirmations").toInt(),
//   //   jString.valueFor("totalForged").toInt()
//   // };
//   return "";//block.description();
// };
/*************************************************/
/*************************************************/
/**************************************************************************************************/
