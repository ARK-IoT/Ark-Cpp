

#ifndef BLOCK_GETTABLE_H
#define BLOCK_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Block
{

/*  ==========================================================================  */
/*  ==================================  */
/*  PROTECTED: ARK::API::Block::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/blocks/get?id=_blockID */
    ARK::Block block(
        ARK::Utilities::Network::Connector _netConnector,
        String _blockId);

    ARK::Block blockfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks   */
  /*   blocks callback is ~63,712 bytes   */
  /*  /api/blocks  */
  // String blocks(ARK::Utilities::Network::Connector _netConnector) {
  // String blocksfromJSON(String _jsonStr) {
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getEpoch  */
    String epoch(ARK::Utilities::Network::Connector _netConnector);
    String epochfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getHeight  */
    ARK::API::Block::Respondable::Height height(ARK::Utilities::Network::Connector _netConnector);
    ARK::API::Block::Respondable::Height heightfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getNethash  */
    Hash nethash(ARK::Utilities::Network::Connector _netConnector);
    Hash nethashfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFee  */
    Balance fee(ARK::Utilities::Network::Connector _netConnector);
    Balance feefromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFees  */
    ARK::Fees fees(ARK::Utilities::Network::Connector _netConnector);
    ARK::Fees feesfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getMilestone  */
    String milestone(ARK::Utilities::Network::Connector _netConnector);
    String milestonefromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getReward  */
    Balance reward(ARK::Utilities::Network::Connector _netConnector);
    Balance rewardfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getSupply  */
    Balance supply(ARK::Utilities::Network::Connector _netConnector);
    Balance supplyfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getStatus  */
    ARK::API::Block::Respondable::Status status(ARK::Utilities::Network::Connector _netConnector);
    ARK::API::Block::Respondable::Status statusfromJSON(String _jsonStr);
/*  ==========================================================================  */
};
/*  ==================================  */
/*  ==========================================================================  */
};
};
};




/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::block  */
/*  /api/blocks/get?id=_blockID */
ARK::Block ARK::API::Block::Gettable::block(
    ARK::Utilities::Network::Connector _netConnector,
    String _blockId)
{
  String uri = ARK::API::Paths::Block::get_s;
  uri += "?id=" + _blockId;
  String callback = _netConnector.cb(uri);
  return ARK::API::Block::Gettable::blockfromJSON(callback);
};

/*
{ "success":true,
  "block":{
    "id": "String",
    "version":  int,
    "timestamp":  String,
    "height": String,
    "previousBlock":  "Striing",
    "numberOfTransactions": String,
    "totalAmount":  Balance,
    "totalFee": Balance,
    "reward": Balance,
    "payloadLength":  String,
    "payloadHash":  "Hash",
    "generatorPublicKey": "Publickey",
    "generatorId":  "Address",
    "blockSignature": "Signature",
    "confirmations":  String,
    "totalForged":" Balance"
  }
}
*/
ARK::Block ARK::API::Block::Gettable::blockfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {
      jString.valueIn("block", "id"),
      jString.valueIn("block", "version").toInt(),
      jString.valueIn("block", "timestamp"),
      jString.valueIn("block", "height"),
      jString.valueIn("block", "previousBlock"),
      jString.valueIn("block", "numberOfTransactions"),
      jString.valueIn("block", "totalAmount"),
      jString.valueIn("block", "totalFee"),
      jString.valueIn("block", "reward"),
      jString.valueIn("block", "payloadLength"),
      jString.valueIn("block", "payloadHash"),
      jString.valueIn("block", "generatorPublicKey"),
      jString.valueIn("block", "generatorId"),
      jString.valueIn("block", "blockSignature"),
      jString.valueIn("block", "confirmations"),
      jString.valueIn("block", "totalForged")};
};
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks   */
/*   blocks callback is ~63,712 bytes   */
/*  ===============================  */
/*  ARK::API::Block::Gettable::blocks  */
// /*  /api/blocks */
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
// String blocksfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
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
/*  ===============================  */
/*  ==========================================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Block::Gettable::epoch  */
/*  /api/blocks/getEpoch  */
String ARK::API::Block::Gettable::epoch(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getEpoch_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::epochfromJSON(callback);
};

/*
{
  "success":true,
  "epoch":  "String"
}
*/
String ARK::API::Block::Gettable::epochfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return jString.valueFor("epoch");
};
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::height  */
/*  /api/blocks/getHeight  */
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::height(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getHeight_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::heightfromJSON(callback);
};

/*
{
  "success":true,
  "height": String,
  "id": "String"
}
*/
ARK::API::Block::Respondable::Height ARK::API::Block::Gettable::heightfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {
      jString.valueFor("height"),
      jString.valueFor("id")};
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::Block::Gettable::nethash  */
/*  /api/blocks/getNethash  */
Hash ARK::API::Block::Gettable::nethash(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getNethash_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::nethashfromJSON(callback);
};

/*
{
  "success":true,
  "nethash":  "Hash"
}
*/
Hash ARK::API::Block::Gettable::nethashfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {jString.valueFor("nethash")};
};
/*  ================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================  */
/*  ARK::API::Block::Gettable::fee  */
/*  /api/blocks/getFee  */
Balance ARK::API::Block::Gettable::fee(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getFee_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::feefromJSON(callback);
};

/*
{ "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Block::Gettable::feefromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {jString.valueFor("fee")};
};
/*  ============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =============================  */
/*  ARK::API::Block::Gettable::fees  */
/*  /api/blocks/getFees  */
ARK::Fees ARK::API::Block::Gettable::fees(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getFees_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::feesfromJSON(callback);
};

/*
{ "success":true,
  "fees":{
    "send": Balance,
    "vote": Balance,
    "secondsignature": Balance,
    "delegate": Balance,
    "multisignature": Balance
  }
}
*/
ARK::Fees ARK::API::Block::Gettable::feesfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {
      jString.valueIn("fees", "send"),
      jString.valueIn("fees", "vote"),
      jString.valueIn("fees", "secondsignature"),
      jString.valueIn("fees", "delegate"),
      jString.valueIn("fees", "multisignature")};
};
/*  =============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Block::Gettable::milestone  */
/*  /api/blocks/getMilestone  */
String ARK::API::Block::Gettable::milestone(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getMilestone_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::milestonefromJSON(callback);
};

/*
{
  "success":true,
  "milestone": String
}
*/
String ARK::API::Block::Gettable::milestonefromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return jString.valueFor("milestone");
};
/*  ==================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::reward  */
/*  /api/blocks/getReward  */
Balance ARK::API::Block::Gettable::reward(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getReward_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::rewardfromJSON(callback);
};

/*
{ "success":true,
  "reward": Balance
}
*/
Balance ARK::API::Block::Gettable::rewardfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {jString.valueFor("reward")};
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::supply  */
/*  /api/blocks/getSupply  */
Balance ARK::API::Block::Gettable::supply(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getSupply_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::supplyfromJSON(callback);
};

/*
{
  "success":true,
  "supply": Balance
}
*/
Balance ARK::API::Block::Gettable::supplyfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {jString.valueFor("supply")};
};
/*  ===============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::Block::Gettable::status  */
/*  /api/blocks/getStatus  */
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::status(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Block::getStatus_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Block::Gettable::statusfromJSON(callback);
};

/*
{ "success":true,
  "epoch":  "String",
  "height": String,
  "fee":  Balance,
  "milestone":  String,
  "nethash":" Hash",
  "reward":_reward,
  "supply":_supply
}
*/
ARK::API::Block::Respondable::Status ARK::API::Block::Gettable::statusfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);
  
  return {
      jString.valueFor("epoch"),
      jString.valueFor("height"),
      jString.valueFor("fee"),
      jString.valueFor("milestone").toInt(),
      jString.valueFor("nethash"),
      jString.valueFor("reward"),
      jString.valueFor("supply")};
};
/*  ===============================  */
/*  ==========================================================================  */


#endif
