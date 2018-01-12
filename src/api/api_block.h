

#ifndef api_block_h
#define api_block_h

namespace ARK {
  namespace API { 
    namespace Block {

        // const String blocks_s = "/api/blocks";


      namespace Get {

        /*
        { "success":true,
          "block":{
            "id":"4367122150875693402",
            "version":0,
            "timestamp":25271824,
            "height":2287265,
            "previousBlock":"17021413347323836951",
            "numberOfTransactions":0,
            "totalAmount":0,
            "totalFee":0,
            "reward":200000000,
            "payloadLength":0,
            "payloadHash":"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "generatorPublicKey":"02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586",
            "generatorId":"D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz",
            "blockSignature":"3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0",
            "confirmations":51,
            "totalForged":"200000000"
          }
        }
        */
        String blockfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr); 
          ARK::Block block = {
            jString.valueFor("id").toInt(),
            jString.valueFor("version").toInt(),
            jString.valueFor("timestamp").toInt(),
            jString.valueFor("height").toInt(),
            jString.valueFor("previousBlock").toInt(),
            jString.valueFor("numberOfTransactions").toInt(),
            jString.valueFor("totalAmount").toInt(),
            jString.valueFor("totalFee").toInt(),
            jString.valueFor("reward").toInt(),
            jString.valueFor("payloadLength").toInt(),
            jString.valueFor("payloadHash"),
            jString.valueFor("generatorPublicKey"),
            jString.valueFor("generatorId"),
            jString.valueFor("blockSignature"),
            jString.valueFor("confirmations").toInt(),
            jString.valueFor("totalForged").toInt()
          };
          return block.description();
        };
        /*  /api/blocks/get?id=_blockID */
        String block(ARK::Utilities::Network::Manager _netManager, String _blockId) {
          String uri = ARK::API::Endpoints::Block::get_s;
            uri += "?id=" + _blockId;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0) { return callback; }
          else { return ARK::API::Block::Get::blockfromJSON(callback); };
        };


/* 
  needs stream->string size fix for large callbacks
*/
        // /*
        // {
        //   "success":true,
        //   "blocks":[
        //     { 
        //       "id":"12985902365925092121",
        //       "version":0,
        //       "timestamp":25588144,
        //       "height":2313747,
        //       "previousBlock":"12092868908634754712",
        //       "numberOfTransactions":0,
        //       "totalAmount":0,
        //       "totalFee":0,
        //       "reward":200000000,
        //       "payloadLength":0,
        //       "payloadHash":"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
        //       "generatorPublicKey":"02ac90cbb1e8f0cf1983d5090f1a289f272a1e4e45f53e9a000579dff78cd3e4d2",
        //       "generatorId":"DHwLCgbGwognuapEP7Pb4rve8yFkL2BABL",
        //       "blockSignature":"3045022100a77d7cc1d8d2e6bd4bf6046e264c603cb5c194d2bdac8a13fc8a1b522507321d02203ee74474352a642d1c108c9b984d228a9300ae900130c507d264ebea038fb908",
        //       "confirmations":1,
        //       "totalForged":"200000000"
        //     },
        //     ...
        //     { 
        //       "id":"5017419818036669226",
        //       "version":0,
        //       "timestamp":25586952,
        //       "height":2313648,
        //       "previousBlock":"5897327420484645814",
        //       "numberOfTransactions":0,
        //       "totalAmount":0,
        //       "totalFee":0,
        //       "reward":200000000,
        //       "payloadLength":0,
        //       "payloadHash":"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
        //       "generatorPublicKey":"03c638259e874e38bb9621f29a907c3e2445b5bd61c76c3c3098bff83ebabbfeab",
        //       "generatorId":"DAZA9otpg7J3pAe9F2TukUa1hjCQnArMk8",
        //       "blockSignature":"304402202ac6469ea96ef0f07291a52aa640371f0a6e0cfe07e486061d09e851d81e1b7102205bb5d1240a01a73db24d4126e65bf0d99397a33180bd13a4997daec4997c1c02",
        //       "confirmations":100,
        //       "totalForged":"200000000"
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
        //   return ARK::API::Block::Get::blocksfromJSON(callback);
        // };




        /*  {"success":true,"epoch":"2017-03-21T13:00:00.000Z"} */
        String epochfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr); 
          return jString.valueFor("epoch");
        };
        /*  /api/blocks/getEpoch  */
        String epoch(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getEpoch_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::epochfromJSON(callback);
        };





        /*  {"success":true,"height":2287596,"id":"7592356398456751342"}  */
        String heightfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          String resp;
            resp += "height: ";
            resp += jString.valueFor("height").toInt();
            resp += " | id: ";
            resp += jString.valueFor("id");
          return resp;
        };
        /*  /api/blocks/getHeight  */
        String height(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getHeight_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::heightfromJSON(callback);
        };





        /*  {"success":true,"nethash":"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"}  */
        String nethashfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          return jString.valueFor("nethash");
        };
        /*  /api/blocks/getNethash  */
        String nethash(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getNethash_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::nethashfromJSON(callback);
        };





        /*  {"success":true,"fee":10000000}  */
        String feefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          return jString.valueFor("fee");
        };
        /*  /api/blocks/getFee  */
        String fee(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getFee_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::feefromJSON(callback);
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
        String feesfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::Fees fees = {
            jString.valueFor("send").toInt(),
            jString.valueFor("vote").toInt(),
            jString.valueFor("secondsignature").toInt(),
            jString.valueFor("delegate").toInt(),
            jString.valueFor("multisignature").toInt(),
          };
          return fees.description();
        };
        /*  /api/blocks/getFees  */
        String fees(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getFees_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::feesfromJSON(callback);
        };





        /*  {"success":true,"milestone":0}  */
        String milestonefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          return jString.valueFor("milestone");
        };
        /*  /api/blocks/getMilestone  */
        String milestone(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getMilestone_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::milestonefromJSON(callback);
        };





        /*  {"success":true,"reward":200000000}  */
        String rewardfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          return jString.valueFor("reward");
        };
        /*  /api/blocks/getReward  */
        String reward(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getReward_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::rewardfromJSON(callback);
        };





        /*  {"success":true,"supply":12957554000000000}  */
        String supplyfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);  
          return jString.valueFor("supply");
        };
        /*  /api/blocks/getSupply  */
        String supply(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getSupply_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::supplyfromJSON(callback);
        };





        /*
        { 
          "success":true,
          "epoch":"2017-03-21T13:00:00.000Z",
          "height":2287781,
          "fee":10000000,
          "milestone":0,
          "nethash":"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
          "reward":200000000,
          "supply":12957556200000000
        }
        */
        String statusfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::Block::Block::getStatusResponse statusResponse = {
            jString.valueFor("epoch"),
            jString.valueFor("height").toInt(),
            jString.valueFor("fee").toInt(),
            jString.valueFor("milestone").toInt(),
            jString.valueFor("nethash"),
            jString.valueFor("reward").toInt(),
            jString.valueFor("supply").toInt()
          };
          return statusResponse.description();
        };
        /*  /api/blocks/getStatus  */
        String status(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Block::getStatus_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Block::Get::statusfromJSON(callback);
        };
        

      
      };




        
      namespace block_cb {
        
        struct getBlockResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Block block;
        };
      
        struct getBlocksResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Block blocks[];
        };
      
        struct getEpochResponse : virtual ARK::API::Helpers::Successable {
          public:
            String epoch;
        };
      
        struct getHeightResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int height;
            long int id;
        };
      
        struct getNethashResponse : virtual ARK::API::Helpers::Successable {
          public:
            String nethash;
        };
      
        struct getFeeResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int fees;
        };
      
        struct getFeesResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double send;
            long double vote;
            long double secondsignature;
            long double delegate;
            long double multisignature;
        };
      
        struct getMilestoneResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int milestone;
        };
      
        struct getRewardResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double reward;
        };
      
        struct getSupplyResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int supply;
        };
      
        // struct getStatusResponse : virtual ARK::API::Helpers::Successable {
        //   public:
        //     String epoch;
        //     long int height;
        //     long double fee;
        //     long int milestone;
        //     String nethash;
        //     long double reward;
        //     long int supply;
        // };
      
      };
      
      
    };
  };
};

#endif
