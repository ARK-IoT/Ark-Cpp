

#ifndef block_gettable_h
#define block_gettable_h

namespace ARK {
  namespace API { 

    /*  ==================================  */
    /*  PROTECTED: ARK::API::BlockGettable  */
    class BlockGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/blocks/get?id=_blockID */
        ARK::Block block(ARK::Utilities::Network::Manager _netManager, String _blockId);
        ARK::Block blockfromJSON(String _jsonStr);

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks   */
    /*   blocks callback is ~63,712 bytes   */
        /*  /api/blocks  */
        // String blocks(ARK::Utilities::Network::Manager _netManager) {
        // String blocksfromJSON(String _jsonStr) {
/*  ==========================================================================  */

        /*  /api/blocks/getEpoch  */
        String epoch(ARK::Utilities::Network::Manager _netManager);
        String epochfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getHeight  */
        ARK::Block::BlockHeightResponse height(ARK::Utilities::Network::Manager _netManager);
        ARK::Block::BlockHeightResponse heightfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getNethash  */
        Hash nethash(ARK::Utilities::Network::Manager _netManager);
        Hash nethashfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getFee  */
        Balance fee(ARK::Utilities::Network::Manager _netManager);
        Balance feefromJSON(String _jsonStr);
        
/*  ==========================================================================  */

        /*  /api/blocks/getFees  */
        ARK::Fees fees(ARK::Utilities::Network::Manager _netManager);
        ARK::Fees feesfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getMilestone  */
        String milestone(ARK::Utilities::Network::Manager _netManager);
        String milestonefromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getReward  */
        Balance reward(ARK::Utilities::Network::Manager _netManager);
        Balance rewardfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getSupply  */
        Balance supply(ARK::Utilities::Network::Manager _netManager);
        Balance supplyfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/blocks/getStatus  */
        ARK::Block::Block::BlockStatusResponse status(ARK::Utilities::Network::Manager _netManager);
        ARK::Block::Block::BlockStatusResponse statusfromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  ==================================  */

  };
};

/*  ==========================================================================  */

/*  ==============================  */
/*  ARK::API::BlockGettable::block  */

/*  /api/blocks/get?id=_blockID */
ARK::Block ARK::API::BlockGettable::block(ARK::Utilities::Network::Manager _netManager, String _blockId) {
  String uri = ARK::API::Endpoints::Block::get_s;
    uri += "?id=" + _blockId;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::blockfromJSON(callback);
};

/*
{ "success":true,
  "block":{
    "id":"_blockID",
    "version":_version,
    "timestamp":_timestamp,
    "height":_height,
    "previousBlock":"_previousBlock",
    "numberOfTransactions":_numberOfTransactions,
    "totalAmount":_totalAmount,
    "totalFee":_totalFee,
    "reward":_reward,
    "payloadLength":_payloadLength,
    "payloadHash":"_payloadHash",
    "generatorPublicKey":"_generatorPubkey",
    "generatorId":"_generatorID",
    "blockSignature":"_blockSig",
    "confirmations":_confirmations,
    "totalForged":"_totalForged"
  }
}
*/
ARK::Block ARK::API::BlockGettable::blockfromJSON(String _jsonStr) {
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
    jString.valueIn("block", "totalForged")
  };
};
/*  ==============================  */

/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks   */
/*   blocks callback is ~63,712 bytes   */
/*  ===============================  */
/*  ARK::API::BlockGettable::blocks  */
// /*  /api/blocks */
// String blocks(ARK::Utilities::Network::Manager _netManager) {
//   String uri = ARK::API::Endpoints::Block::blocks_s;
//   String callback = _netManager.cb(uri);
//   if (callback.indexOf("false") >= 0) { return callback; };
//   return ARK::API::BlockGettable::blocksfromJSON(callback);
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

/*  ==============================  */
/*  ARK::API::BlockGettable::epoch  */

/*  /api/blocks/getEpoch  */
String ARK::API::BlockGettable::epoch(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getEpoch_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::epochfromJSON(callback);
};

/*
{
  "success":true,
  "epoch":"_epoch"
}
*/
String ARK::API::BlockGettable::epochfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  return jString.valueFor("epoch");
};
/*  ==============================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::BlockGettable::height  */

/*  /api/blocks/getHeight  */
ARK::Block::BlockHeightResponse ARK::API::BlockGettable::height(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getHeight_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::heightfromJSON(callback);
};

/*
{
  "success":true,
  "height":_height,
  "id":"_blockID"
}
*/
ARK::Block::BlockHeightResponse ARK::API::BlockGettable::heightfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  return {
    jString.valueFor("height"),
    jString.valueFor("id")
  };
};
/*  ===============================  */

/*  ==========================================================================  */

/*  ================================  */
/*  ARK::API::BlockGettable::nethash  */

/*  /api/blocks/getNethash  */
Hash ARK::API::BlockGettable::nethash(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getNethash_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::nethashfromJSON(callback);
};

/*
{
  "success":true,
  "nethash":"_nethash"
}
*/
Hash ARK::API::BlockGettable::nethashfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return { jString.valueFor("nethash") };
};
/*  ================================  */

/*  ==========================================================================  */

/*  ============================  */
/*  ARK::API::BlockGettable::fee  */

/*  /api/blocks/getFee  */
Balance ARK::API::BlockGettable::fee(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getFee_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::feefromJSON(callback);
};

/*
{ "success":true,
  "fee":10000000
}
*/
Balance ARK::API::BlockGettable::feefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return { jString.valueFor("fee") };
};
/*  ============================  */

/*  ==========================================================================  */

/*  =============================  */
/*  ARK::API::BlockGettable::fees  */

/*  /api/blocks/getFees  */
ARK::Fees ARK::API::BlockGettable::fees(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getFees_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::feesfromJSON(callback);
};

/*
{ "success":true,
  "fees":{
    "send":10000000,
    "vote":100000000,
    "secondsignature":500000000,
    "delegate":2500000000,
    "multisignature":500000000
  }
}
*/
ARK::Fees ARK::API::BlockGettable::feesfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueIn("fees", "send"),
    jString.valueIn("fees", "vote"),
    jString.valueIn("fees", "secondsignature"),
    jString.valueIn("fees", "delegate"),
    jString.valueIn("fees", "multisignature")
  };
};
/*  =============================  */

/*  ==========================================================================  */

/*  ==================================  */
/*  ARK::API::BlockGettable::milestone  */

/*  /api/blocks/getMilestone  */
String ARK::API::BlockGettable::milestone(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getMilestone_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::milestonefromJSON(callback);
};

/*
{
  "success":true,
  "milestone":0
}
*/
String ARK::API::BlockGettable::milestonefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return jString.valueFor("milestone");
};
/*  ==================================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::BlockGettable::reward  */

/*  /api/blocks/getReward  */
Balance ARK::API::BlockGettable::reward(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getReward_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::rewardfromJSON(callback);
};

/*
{ "success":true,
  "reward":200000000
}
*/
Balance ARK::API::BlockGettable::rewardfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return { jString.valueFor("reward") };
};
/*  ===============================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::BlockGettable::supply  */

/*  /api/blocks/getSupply  */
Balance ARK::API::BlockGettable::supply(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getSupply_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::supplyfromJSON(callback);
};

/*
{
  "success":true,
  "supply":12957554000000000
}
*/
Balance ARK::API::BlockGettable::supplyfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return { jString.valueFor("supply") };
};
/*  ===============================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::BlockGettable::status  */

/*  /api/blocks/getStatus  */
ARK::Block::Block::BlockStatusResponse ARK::API::BlockGettable::status(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getStatus_s;
  String callback = _netManager.cb(uri);
  return ARK::API::BlockGettable::statusfromJSON(callback);
};

/*
{ "success":true,
  "epoch":"_epoch",
  "height":_height,
  "fee":_fee,
  "milestone":_milestone,
  "nethash":"_nethash",
  "reward":_reward,
  "supply":_supply
}
*/
ARK::Block::Block::BlockStatusResponse ARK::API::BlockGettable::statusfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueFor("epoch"),
    jString.valueFor("height"),
    jString.valueFor("fee"),
    jString.valueFor("milestone").toInt(),
    jString.valueFor("nethash"),
    jString.valueFor("reward"),
    jString.valueFor("supply")
  };
};
/*  ===============================  */


#endif
