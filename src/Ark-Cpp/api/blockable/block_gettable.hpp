

#ifndef BLOCK_GETTABLE_HPP
#define BLOCK_GETTABLE_HPP

namespace ARK
{
namespace API
{
namespace Block
{

/*************************************************
*  PROTECTED: ARK::API::Block::Gettable
**************************************************/
class Gettable
{
protected:
  /*************************************************
  * ARK::API::Block::Gettable::block
  *   api/blocks/get?id=_blockID
  **************************************************/
  ARK::Block block(
      ARK::Utilities::Network::Connector &netConnector,
      const char *const blockId)
  {
    char uri[256] = {'\0'}; // TODO:  check size
    strcpy(uri, ARK::API::Paths::Block::get_s);
    strcat(uri, "?id=");
    strcat(uri, blockId);
    auto callback = netConnector.cb(uri);
    return blockfromJSON(callback);
  };
  /*************************************************
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
  ARK::Block blockfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return {
        parser.valueIn("block", "id"),
        atoi(parser.valueIn("block", "version")),
        parser.valueIn("block", "timestamp"),
        parser.valueIn("block", "height"),
        parser.valueIn("block", "previousBlock"),
        parser.valueIn("block", "numberOfTransactions"),
        parser.valueIn("block", "totalAmount"),
        parser.valueIn("block", "totalFee"),
        parser.valueIn("block", "reward"),
        parser.valueIn("block", "payloadLength"),
        parser.valueIn("block", "payloadHash"),
        parser.valueIn("block", "generatorPublicKey"),
        parser.valueIn("block", "generatorId"),
        parser.valueIn("block", "blockSignature"),
        parser.valueIn("block", "confirmations"),
        parser.valueIn("block", "totalForged")};
  }
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
  *   /api/blocks/getEpoch
  *
  *   blockEpoch example:
  *     2017-03-21T13:00:00.000Z
  **************************************************/
  const char *epoch(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getEpoch_s);
    return epochfromJSON(callback);
  };
  /*************************************************
  * {
  *   "success":true,
  *   "epoch":  "String"
  * }
  **************************************************/
  const char *epochfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
    return parser.valueFor("epoch");
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::height 
  *   /api/blocks/getHeight
  **************************************************/
  ARK::API::Block::Respondable::Height height(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getHeight_s);
    return heightfromJSON(callback);
  };
  /*************************************************
    * {
    *   "success":true,
    *   "height": String,
    *   "id": "String"
    * }
    **************************************************/
  ARK::API::Block::Respondable::Height heightfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
    return {
        parser.valueFor("height"),
        parser.valueFor("id")};
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::nethash
  *   /api/blocks/getNethash 
  **************************************************/
  Hash nethash(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getNethash_s);
    return nethashfromJSON(callback);
  };
  /*************************************************
  * {
  *   "success":true,
  *   "nethash":  "Hash"
  * }
  **************************************************/
  Hash nethashfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
    return Hash(parser.valueFor("nethash"));
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::fee 
  *   /api/blocks/getFee
  **************************************************/
  Balance fee(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getFee_s);
    return feefromJSON(callback);
  };
  /*************************************************
  * {
  *   "success":true,
  *   "fee":  Balance
  * }
  **************************************************/
  Balance feefromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return Balance(parser.valueFor("fee"));
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::fees
  *   /api/blocks/getFees 
  **************************************************/
  ARK::Fees fees(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getFees_s);
    return feesfromJSON(callback);
  };
  /*************************************************
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
  ARK::Fees feesfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return {
        parser.valueIn("fees", "send"),
        parser.valueIn("fees", "vote"),
        parser.valueIn("fees", "secondsignature"),
        parser.valueIn("fees", "delegate"),
        parser.valueIn("fees", "multisignature")};
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::milestone
  *   /api/blocks/getMilestone
  **************************************************/
  const char *milestone(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getMilestone_s);
    return milestonefromJSON(callback);
  };
  /*************************************************
  * {
  *   "success":true,
  *   "milestone": String
  * }
  **************************************************/
  const char *milestonefromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return parser.valueFor("milestone");
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::reward
  *   /api/blocks/getReward
  **************************************************/
  Balance reward(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getReward_s);
    return rewardfromJSON(callback);
  };

  /*************************************************
  * { 
  *   "success":true,
  *   "reward": Balance
  * }
  **************************************************/
  Balance rewardfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return Balance(parser.valueFor("reward"));
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::supply
  *   /api/blocks/getSupply
  **************************************************/
  Balance supply(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getSupply_s);
    return supplyfromJSON(callback);
  };
  /*************************************************
  * {
  *   "success":true,
  *   "supply": Balance
  * }
  **************************************************/
  Balance supplyfromJSON(const char *jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return Balance(parser.valueFor("supply"));
  };
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
   *  ARK::API::Block::Gettable::status 
   *    api/blocks/getStatus
  **************************************************/
  ARK::API::Block::Respondable::Status status(ARK::Utilities::Network::Connector &netConnector)
  {
    auto callback = netConnector.cb(ARK::API::Paths::Block::getStatus_s);
    return statusfromJSON(callback);
  };
  /*************************************************
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
  ARK::API::Block::Respondable::Status statusfromJSON(const char *const jsonStr)
  {
    ARK::Utilities::JSONParser parser(jsonStr, sizeof(jsonStr) / sizeof(jsonStr[0]));
    return {
        parser.valueFor("epoch"),
        parser.valueFor("height"),
        parser.valueFor("fee"),
        atoi(parser.valueFor("milestone")),
        parser.valueFor("nethash"),
        parser.valueFor("reward"),
        parser.valueFor("supply")};
  };
  /*************************************************/
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

#endif
