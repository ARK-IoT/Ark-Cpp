
#ifndef api_delegate_h
#define api_delegate_h
    
namespace ARK {
  namespace API {
    namespace Delegate {

      namespace Get {


        /*  {"success":true,"count":166}  */
        String countfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("count");
        };
        /*  /api/delegates/count  */
        String count(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Delegate::count_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Delegate::Get::countfromJSON(callback);
        };





        
        /*
        { "success":true,
          "delegates":[
            { "username":"_username",
              "address":"_arkAddress",
              "publicKey":"_pubkey",
              "vote":"0000000000000",
              "producedblocks":0,
              "missedblocks":0
            }
          ]
        }
        */
        String searchfromJSON(ARK::Utilities::Network::Manager _netManager, String _jsonStr) {

          ARK::Utilities::JSONString jString(_jsonStr);
          String delegateUsername = jString.valueFor("username");
          String uri = ARK::API::Endpoints::Delegate::get_s;
            uri += "?username=";
            uri += delegateUsername;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0) { return callback; };

          ARK::Utilities::JSONString delegateJString(callback);
          ARK::Delegate delegate = {
            delegateJString.valueFor("username"),
            delegateJString.valueFor("address"),
            delegateJString.valueFor("publicKey"),
            delegateJString.valueFor("vote").toInt(),
            delegateJString.valueFor("producedblocks").toInt(),
            delegateJString.valueFor("missedblocks").toInt(),
            delegateJString.valueFor("rate").toInt(),
            delegateJString.valueFor("approval").toFloat(),
            delegateJString.valueFor("productivity").toFloat()
          };
          return delegate.description();
        };
        /*  /api/delegates/search?q=sleepdeficit  */
        String search(ARK::Utilities::Network::Manager _netManager, String _username) {
          String uri = ARK::API::Endpoints::Delegate::search_s;
            uri += "?q=";
            uri += _username;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0) { return callback; };
          return ARK::API::Delegate::Get::searchfromJSON(_netManager, callback);
        };






        // /*
        // { "success":true,
        //   "accounts":[
        //     { "username":"io.pi.relay.ds3",
        //       "address":"DS3jiY1uPToqfGKmmfsdFnBhMmsrQY47gd",
        //       "publicKey":"03c57e437203403c5438bdb93f34d46a708a5d23a63fa9fe44c5fed1fa458d0717",
        //       "balance":"0"
        //     },
        //     { "username":"sleepdeficit",
        //       "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
        //       "publicKey":"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
        //       "balance":"7637485341862"
        //     }
        //   ]
        // }
        // */
        // String votersfromJSON(String _jsonStr) {
        //   ARK::Utilities::JSONString jString(_jsonStr);
        //   int votercount = ARK::API::Helpers::substringCount(_jsonStr, "username");
        //   ARK::Voters voters[votercount];
        //   for (int i = 0; i < votercount; i++) {
        //     ARK::Voter voter = {
        //       jString.valueFor("username"),
        //       jString.valueFor("address"),
        //       jString.valueFor("publicKey"),
        //       jString.valueFor("balance").toInt() 
        //     };
        //     voters[votercount].add(voter);
        //     delay(500);
        //   };
        //   return jString.valueFor("voters");
        // };
        // /*  /api/delegates/voters?publicKey=_pubKey  */
        // String voters(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
        //   String uri = ARK::API::Endpoints::Delegate::voters_s;
        //     uri += "?publicKey=" + _publicKey;
        //   String callback = _netManager.cb(uri);
        //   if (callback.indexOf("false") >= 0)
        //     return callback;
        //   return ARK::API::Delegate::Get::votersfromJSON(callback);
        // };






        /*
        { "success":true,
          "delegate":{
            "username":"sleepdeficit",
            "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
            "publicKey":"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
            "vote":"7637485341862",
            "producedblocks":31920,
            "missedblocks":2990,
            "rate":18,
            "approval":0.06,
            "productivity":91.44
          }
        }
        */
        String delegatefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);

          ARK::Delegate delegate = {
            jString.valueFor("username"),
            jString.valueFor("address"),
            jString.valueFor("publicKey"),
            jString.valueFor("vote").toInt(),
            jString.valueFor("producedblocks").toInt(),
            jString.valueFor("missedblocks").toInt(),
            jString.valueFor("rate").toInt(),
            jString.valueFor("approval").toFloat(),
            jString.valueFor("productivity").toFloat()
          };
          return delegate.description();
        };
        /* 
          /api/delegates/get?username=sleepdeficit
          /api/delegates/get?publicKey=_pubKey
       */
        String delegate(ARK::Utilities::Network::Manager _netManager, String _parameter) {
          String uri = ARK::API::Endpoints::Delegate::get_s;

          bool isPublicKey = false;
          for (int i = 0; i < (int)_parameter.length(); i++) {
            if (_parameter[i] == 0) { isPublicKey = true; };
          };
          if (isPublicKey) {
            uri += "?publicKey=";
          } else {
            uri += "?username=";
          };
          uri += _parameter;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0) {
            return callback;
          };
          return ARK::API::Delegate::Get::delegatefromJSON(callback);
        };





        // /*
        // { "success":true,
        //   "delegates":[
        //     { "username":"d_chris",
        //       "address":"DQUjMT6fhJWbwhaYL5pPdX9v5qPiRcAzRb",
        //       "publicKey":"02bcfa0951a92e7876db1fb71996a853b57f996972ed059a950d910f7d541706c9",
        //       "vote":"11511729062473143",
        //       "producedblocks":38129,
        //       "missedblocks":11252,
        //       "rate":1,
        //       "approval":88.81,
        //       "productivity":77.21
        //     },
        //     ...
        //     { "username":"phildark",
        //       "address":"D6mtwEK2cyT2BRaUZtmgaWYg3XTpEML8s8",
        //       "publicKey":"03f734e0baae2207eb1a225cf435e75c79b935a806c79edf5733e402cad8852dd8",
        //       "vote":"2431020000000",
        //       "producedblocks":7157,
        //       "missedblocks":4685,
        //       "rate":51,"approval":0.02,
        //       "productivity":60.44
        //     }
        //   ],
        //   "totalCount":166
        // }
        // */
        // String delegatesfromJSON(String _jsonStr) {
        //   ARK::Utilities::JSONString jString(_jsonStr);

        //   return jString.valueFor("delegates");
        // };
      
        // /*  /api/delegates  */
        // String delegates(ARK::Utilities::Network::Manager _netManager) {
        //   String uri = ARK::API::Endpoints::Delegate::delegates_s;
        //   String callback = _netManager.cb(uri);
        //   if (callback.indexOf("false") >= 0)
        //     return callback;
        //   return ARK::API::Delegate::Get::delegatesfromJSON(callback);
        // };





        /*  {"success":true,"fee":2500000000} */
        String feefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("fee");
        };
      
        /*  /api/delegates/fee  */
        String fee(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Delegate::fee_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Delegate::Get::feefromJSON(callback);
        };




        struct getForgedByAccountResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double fees;
            long int rewards;
            long int forged;
        };
        /*  {"success":true,"fees":"44300000000","rewards":"7626000000000","forged":"7670300000000"} */
        String forgedByAccountfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          
          return jString.valueFor("forged");
        };
      
        /*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
        String forgedByAccount(ARK::Utilities::Network::Manager _netManager, String _generatorPublicKey) {
          String uri = ARK::API::Endpoints::Delegate::getForgedByAccount_s;
            uri += "?generatorPublicKey=" + _generatorPublicKey;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Delegate::Get::forgedByAccountfromJSON(callback);
        };




        struct getNextForgersResponse : virtual ARK::API::Helpers::Successable {
          public:
            int currentBlock;
            int currentSlot;
            String delegates;

            getNextForgersResponse() {
              this->currentBlock = 0;
              this->currentSlot = 0;
              this->delegates = "";
            };

            getNextForgersResponse(int _currentBlock, int _currentSlot, String _delegates) {
              this->currentBlock = _currentBlock;
              this->currentSlot = _currentSlot;
              this->delegates = _delegates;
            };

            // String description() {
            //   String resp;
            //     resp += "currentBlock: ";
            //         resp += this->currentBlock; resp += "\n";
            //     resp += "currentSlot: ";
            //         resp += this->currentSlot; resp += "\n";
            //     resp += "delegates: ";
            //       resp += this->delegates; resp += "\n";
            //   return resp;
            // };

        };
        /*
        { "success":true,
          "currentBlock":2307497,
          "currentSlot":3189409,
          "delegates":[
            "035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
            "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
            "028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
            "027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
            "02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
            "0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
            "02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
            "02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
            "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
            "031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
          ]
        }
        */
        String nextForgersfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          getNextForgersResponse nextforgers = {
            jString.valueFor("currentBlock").toInt(),
            jString.valueFor("currentSlot").toInt(),
            jString.valueFor("delegates")
          };
          return "";//nextforgers.description();
        };
        /*  /api/delegates/forging/getNextForgers  */
        String nextForgers(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Delegate::getNextForgers_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Delegate::Get::nextForgersfromJSON(callback);
        };




      };






      namespace delegates_cb {
        
        struct addDelegateResponse : virtual ARK::API::Helpers::Successable {};
        
        struct enableForgingResponse : virtual ARK::API::Helpers::Successable {};
        
        struct disableForgingResponse : virtual ARK::API::Helpers::Successable {};
        
      };      
      
      
    };
  };
};

#endif
