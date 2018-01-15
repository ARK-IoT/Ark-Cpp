

#ifndef blockable_h
#define blockable_h

namespace ARK {
  namespace API { 


    class BlockGettable {
      protected:


        /*  /api/blocks/get?id=_blockID */
        String block(ARK::Utilities::Network::Manager _netManager, String _blockId);
        String blockfromJSON(String _jsonStr);


    // String blocks(ARK::Utilities::Network::Manager _netManager) {
    // String blocksfromJSON(String _jsonStr) {


        /*  /api/blocks/getEpoch  */
        String epoch(ARK::Utilities::Network::Manager _netManager);
        String epochfromJSON(String _jsonStr);

        /*  /api/blocks/getHeight  */
        String height(ARK::Utilities::Network::Manager _netManager);
        String heightfromJSON(String _jsonStr);

        /*  /api/blocks/getNethash  */
        String nethash(ARK::Utilities::Network::Manager _netManager);
        String nethashfromJSON(String _jsonStr);

        /*  /api/blocks/getFee  */
        String fee(ARK::Utilities::Network::Manager _netManager);
        String feefromJSON(String _jsonStr);
        
        /*  /api/blocks/getFees  */
        String fees(ARK::Utilities::Network::Manager _netManager);
        String feesfromJSON(String _jsonStr);

        /*  /api/blocks/getMilestone  */
        String milestone(ARK::Utilities::Network::Manager _netManager);
        String milestonefromJSON(String _jsonStr);

        /*  /api/blocks/getReward  */
        String reward(ARK::Utilities::Network::Manager _netManager);
        String rewardfromJSON(String _jsonStr);

        /*  /api/blocks/getSupply  */
        String supply(ARK::Utilities::Network::Manager _netManager);
        String supplyfromJSON(String _jsonStr);

        /*  /api/blocks/getStatus  */
        String status(ARK::Utilities::Network::Manager _netManager);
        String statusfromJSON(String _jsonStr);


        

    };



    class Blockable : public BlockGettable, virtual ARK::Utilities::Network::Managable {

      public: 

        /*  /api/blocks/get?id=_blockID */
          String block(String _blockId)
          { return ARK::API::BlockGettable::block(this->netManager, _blockId); };

      /* needs stream->string size fix for large callbacks */
          // /*  /api/blocks */
          // String blocks()
          // { return ARK::API::BlockGettable::blocks(this->netManager); };

          /*  /api/blocks/getEpoch  */
          String blockEpoch()
          { return ARK::API::BlockGettable::epoch(this->netManager); };

          /*  /api/blocks/getHeight  */
          String blockHeight()
          { return ARK::API::BlockGettable::height(this->netManager); };

          /*  /api/blocks/getNethash  */
          String blockNethash()
          { return ARK::API::BlockGettable::nethash(this->netManager); };

          /*  /api/blocks/getFee  */
          String blockFee()
          { return ARK::API::BlockGettable::fee(this->netManager); };

          /*  /api/blocks/getFees  */
          String blockFees()
          { return ARK::API::BlockGettable::fees(this->netManager); };

          /*  /api/blocks/getMilestone  */
          String blockMilestone()
          { return ARK::API::BlockGettable::milestone(this->netManager); };

          /*  /api/blocks/getReward  */
          String blockReward()
          { return ARK::API::BlockGettable::reward(this->netManager); };

          /*  /api/blocks/getSupply  */
          String blockSupply()
          { return ARK::API::BlockGettable::supply(this->netManager); };

          /*  /api/blocks/getStatus  */
          String blockStatus()
          { return ARK::API::BlockGettable::status(this->netManager); };

/*  needs stream->string size fix for large callbacks */
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
          // /*  /api/blocks */
          // String blocks(ARK::Utilities::Network::Manager _netManager) {
          //   String uri = ARK::API::Endpoints::Block::blocks_s;
          //   String callback = _netManager.cb(uri);
          //   if (callback.indexOf("false") >= 0) { return callback; };
          //   return ARK::API::BlockGettable::blocksfromJSON(callback);
          // };


    };


  };
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
String ARK::API::BlockGettable::blockfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  ARK::Block block = {
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
  return block.description();
};

/*  /api/blocks/get?id=_blockID */
String ARK::API::BlockGettable::block(ARK::Utilities::Network::Manager _netManager, String _blockId) {
  String uri = ARK::API::Endpoints::Block::get_s;
    uri += "?id=" + _blockId;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  else { return ARK::API::BlockGettable::blockfromJSON(callback); };
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

/*  /api/blocks/getEpoch  */
String ARK::API::BlockGettable::epoch(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getEpoch_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::epochfromJSON(callback);
};




/*
{
  "success":true,
  "height":_height,
  "id":"_blockID"
}
*/
String ARK::API::BlockGettable::heightfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  ARK::Block::BlockHeightResponse blockHeight = {
    jString.valueFor("height"),
    jString.valueFor("id")
  };
  return blockHeight.description();
};

/*  /api/blocks/getHeight  */
String ARK::API::BlockGettable::height(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getHeight_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::heightfromJSON(callback);
};




/*
{
  "success":true,
  "nethash":"_nethash"
}
*/
String ARK::API::BlockGettable::nethashfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return jString.valueFor("nethash");
};

/*  /api/blocks/getNethash  */
String ARK::API::BlockGettable::nethash(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getNethash_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::nethashfromJSON(callback);
};




/*
{
  "success":true,
  "fee":10000000
}
*/
String ARK::API::BlockGettable::feefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return jString.valueFor("fee");
};

/*  /api/blocks/getFee  */
String ARK::API::BlockGettable::fee(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getFee_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::feefromJSON(callback);
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
String ARK::API::BlockGettable::feesfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Fees fees = {
    jString.valueIn("fees", "send"),
    jString.valueIn("fees", "vote"),
    jString.valueIn("fees", "secondsignature"),
    jString.valueIn("fees", "delegate"),
    jString.valueIn("fees", "multisignature")
  };
  return fees.description();
};

/*  /api/blocks/getFees  */
String ARK::API::BlockGettable::fees(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getFees_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::feesfromJSON(callback);
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

/*  /api/blocks/getMilestone  */
String ARK::API::BlockGettable::milestone(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getMilestone_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::milestonefromJSON(callback);
};




/*
{
  "success":true,
  "reward":200000000
}
*/
String ARK::API::BlockGettable::rewardfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return jString.valueFor("reward");
};

/*  /api/blocks/getReward  */
String ARK::API::BlockGettable::reward(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getReward_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::rewardfromJSON(callback);
};




/*
{
  "success":true,
  "supply":12957554000000000
}
*/
String ARK::API::BlockGettable::supplyfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);  
  return jString.valueFor("supply");
};

/*  /api/blocks/getSupply  */
String ARK::API::BlockGettable::supply(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getSupply_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::supplyfromJSON(callback);
};




/*
{ 
  "success":true,
  "epoch":"_epoch",
  "height":_height,
  "fee":_fee,
  "milestone":_milestone,
  "nethash":"_nethash",
  "reward":_reward,
  "supply":_supply
}
*/
String ARK::API::BlockGettable::statusfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Block::Block::BlockStatusResponse statusResponse = {
    jString.valueFor("epoch"),
    jString.valueFor("height"),
    jString.valueFor("fee"),
    jString.valueFor("milestone").toInt(),
    jString.valueFor("nethash"),
    jString.valueFor("reward"),
    jString.valueFor("supply")
  };
  return statusResponse.description();
};

/*  /api/blocks/getStatus  */
String ARK::API::BlockGettable::status(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Block::getStatus_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::BlockGettable::statusfromJSON(callback);
};


#endif
