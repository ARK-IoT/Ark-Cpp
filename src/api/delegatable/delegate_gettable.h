
#ifndef delegate_gettable_h
#define delegate_gettable_h

namespace ARK {
  namespace API {

    /*  =====================================  */
    /*  PROTECTED: ARK::API::DelegateGettable  */

    class DelegateGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/delegates/count  */
        int count(ARK::Utilities::Network::Manager _netManager);
        int countfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/delegates/search?q=sleepdeficit  */
        ARK::Delegate::SearchResponse search(ARK::Utilities::Network::Manager _netManager, String _username);
        ARK::Delegate::SearchResponse searchfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/delegates/voters?publicKey=_pubKey  */
        ARK::VotersResponse voters(ARK::Utilities::Network::Manager _netManager, Publickey _publicKey);
        ARK::VotersResponse votersfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /* 
          /api/delegates/get?username=sleepdeficit
          /api/delegates/get?publicKey=_pubKey
       */
        ARK::Delegate delegate(ARK::Utilities::Network::Manager _netManager, String _parameter);
        ARK::Delegate delegatefromJSON(String _jsonStr);

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
        // String delegates(ARK::Utilities::Network::Manager _netManager);
        // String delegatesfromJSON(String _jsonStr);
/*  ==========================================================================  */

        /*  /api/delegates/fee  */
        Balance fee(ARK::Utilities::Network::Manager _netManager);
        Balance feefromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
        String forgedByAccount(ARK::Utilities::Network::Manager _netManager, Publickey _generatorPublicKey);
        String forgedByAccountfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/delegates/forging/getNextForgers  */
        ARK::Delegate::NextForgersResponse nextForgers(ARK::Utilities::Network::Manager _netManager);
        ARK::Delegate::NextForgersResponse nextForgersfromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  =====================================  */
  };
};

/*  ==========================================================================  */

/*  =================================  */
/*  ARK::API::DelegateGettable::count  */

/*  /api/delegates/count  */
int ARK::API::DelegateGettable::count(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Delegate::count_s;
  String callback = _netManager.cb(uri);
  return ARK::API::DelegateGettable::countfromJSON(callback);
};

/*
{ 
  "success":true,
  "count":166
}
*/
int ARK::API::DelegateGettable::countfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("count").toInt();
};
/*  =================================  */

/*  ==========================================================================  */

/*  ==================================  */
/*  ARK::API::DelegateGettable::search  */

/*  /api/delegates/search?q=sleepdeficit  */
ARK::Delegate::SearchResponse ARK::API::DelegateGettable::search(ARK::Utilities::Network::Manager _netManager, String _username) {
  String uri = ARK::API::Endpoints::Delegate::search_s;
    uri += "?q=";
    uri += _username;
  String callback = _netManager.cb(uri);
  return ARK::API::DelegateGettable::searchfromJSON(callback);
};

/*
{ 
  "success":true,
  "delegates":[
    { 
      "username":"_username",
      "address":"_arkAddress",
      "publicKey":"_pubkey",
      "vote":"0000000000000",
      "producedblocks":0,
      "missedblocks":0
    }
  ]
}
*/
ARK::Delegate::SearchResponse ARK::API::DelegateGettable::searchfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);          
  return {
    jString.subarrayValueIn("delegates", 0, "username"),
    jString.subarrayValueIn("delegates", 0, "address"),
    jString.subarrayValueIn("delegates", 0, "publicKey"),
    jString.subarrayValueIn("delegates", 0, "vote"),
    jString.subarrayValueIn("delegates", 0, "producedblocks").toInt(),
    jString.subarrayValueIn("delegates", 0, "missedblocks").toInt(),
  };
};
/*  ==================================  */

/*  ==========================================================================  */

/*  ==================================  */
/*  ARK::API::DelegateGettable::voters  */

/*  /api/delegates/voters?publicKey=_pubKey  */
ARK::VotersResponse ARK::API::DelegateGettable::voters(ARK::Utilities::Network::Manager _netManager, Publickey _publicKey) {
  String uri = ARK::API::Endpoints::Delegate::voters_s;
    uri += "?publicKey=" + _publicKey.description();
  String callback = _netManager.cb(uri);
  return ARK::API::DelegateGettable::votersfromJSON(callback);
};

/*
{ "success":true,
  "accounts":[
    { "username":"_username",
      "address":"_address",
      "publicKey":"_publicKey",
      "balance":"_balance"
    },
    { "username":"sleepdeficit",
      "address":"_address",
      "publicKey":"_publicKey",
      "balance":"_balance"
    }
  ]
}
*/
ARK::VotersResponse ARK::API::DelegateGettable::votersfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  int voterCount = ARK::API::Helpers::substringCount(_jsonStr, "username");
  ARK::VotersResponse voterResponse(voterCount);
  for (int i = 0; i < voterCount; i++) {
    ARK::Voter voter = {
      jString.subarrayValueIn("accounts", i, "username"),
      jString.subarrayValueIn("accounts", i, "address"),
      jString.subarrayValueIn("accounts", i, "publicKey"),
      jString.subarrayValueIn("accounts", i, "balance")
    };
    voterResponse.list[i] = voter;
  };
  return voterResponse;
};
/*  ==================================  */

/*  ==========================================================================  */

/*  ====================================  */
/*  ARK::API::DelegateGettable::delegate  */

/* 
  /api/delegates/get?username=sleepdeficit
  /api/delegates/get?publicKey=_pubKey
*/
ARK::Delegate ARK::API::DelegateGettable::delegate(ARK::Utilities::Network::Manager _netManager, String _parameter) {
  String uri = ARK::API::Endpoints::Delegate::get_s;
  if (_parameter.length() > 20) {
    uri += "?publicKey="; 
  } else { 
    uri += "?username="; 
  };
  uri += _parameter;
  String callback = _netManager.cb(uri);
  return ARK::API::DelegateGettable::delegatefromJSON(callback);
};

/*
{ 
  "success":true,
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
ARK::Delegate ARK::API::DelegateGettable::delegatefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.subvalueIn("delegate", "username"),
    jString.subvalueIn("delegate", "address"),
    jString.subvalueIn("delegate", "publicKey"),
    jString.subvalueIn("delegate", "vote"),
    jString.subvalueIn("delegate", "producedblocks").toInt(),
    jString.subvalueIn("delegate", "missedblocks").toInt(),
    jString.subvalueIn("delegate", "rate").toInt(),
    jString.subvalueIn("delegate", "approval").toFloat(),
    jString.subvalueIn("delegate", "productivity").toFloat()
  };
};
/*  ====================================  */

/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
/*  =====================================  */
/*  ARK::API::DelegateGettable::delegates  */
// /*  /api/delegates  */
// String ARK::API::DelegateGettable::delegates(ARK::Utilities::Network::Manager _netManager) {
//   String uri = ARK::API::Endpoints::Delegate::delegates_s;
//   String callback = _netManager.cb(uri);
//   return ARK::API::DelegateGettable::delegatesfromJSON(callback);
// };
/*
{ "success":true,
  "delegates":[
    { "username":"d_chris",
      "address":"DQUjMT6fhJWbwhaYL5pPdX9v5qPiRcAzRb",
      "publicKey":"02bcfa0951a92e7876db1fb71996a853b57f996972ed059a950d910f7d541706c9",
      "vote":"11511729062473143",
      "producedblocks":38129,
      "missedblocks":11252,
      "rate":1,
      "approval":88.81,
      "productivity":77.21
    },
    ...
    { "username":"phildark",
      "address":"D6mtwEK2cyT2BRaUZtmgaWYg3XTpEML8s8",
      "publicKey":"03f734e0baae2207eb1a225cf435e75c79b935a806c79edf5733e402cad8852dd8",
      "vote":"2431020000000",
      "producedblocks":7157,
      "missedblocks":4685,
      "rate":51,"approval":0.02,
      "productivity":60.44
    }
  ],
  "totalCount":166
}
*/
// String ARK::API::DelegateGettable::delegatesfromJSON(String _jsonStr) {
//   Serial.println("========== delegatesfromJSON ==========");

//   // Serial.println("_jsonStr");
//   // Serial.println(_jsonStr);
//   // Serial.println();

//   ARK::Utilities::JSONString jString(_jsonStr);
//   int top51Count = 51;

//   // ARK::Delegate delegate[5];
//   ARK::DelegatesResponse delegatesResponse(5);


//   for (int i = 0; i < 5; i++) {
//     ARK::Delegate delegate = {
//       jString.subarrayValueIn("delegates", i, "username"),
//       jString.subarrayValueIn("delegates", i, "address"),
//       jString.subarrayValueIn("delegates", i, "publicKey"),
//       jString.subarrayValueIn("delegates", i, "vote"),
//       jString.subarrayValueIn("delegates", i, "producedblocks").toInt(),
//       jString.subarrayValueIn("delegates", i, "missedblocks").toInt(),
//       jString.subarrayValueIn("delegates", i, "rate").toInt(),
//       jString.subarrayValueIn("delegates", i, "approval").toFloat(),
//       jString.subarrayValueIn("delegates", i, "productivity").toFloat()
//     };
//     delegatesResponse.list[i] = delegate;
//   };
//   String resp;
//   for ( int i = 0; i < 5; i++ ) {
//     resp += "delegate ";  resp += i + 1;	resp += ":\n	";
//       resp += delegatesResponse.list[i].description();
//   };
//   resp += "totalCount:\n";
//     resp += jString.valueFor("totalCount");
//   return resp;
// };
/*  =====================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::DelegateGettable::fee  */

/*  /api/delegates/fee  */
Balance ARK::API::DelegateGettable::fee(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Delegate::fee_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  else { return ARK::API::DelegateGettable::feefromJSON(callback); };
};

/*
{
  "success":true,
  "fee":2500000000
}
*/
Balance ARK::API::DelegateGettable::feefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return { jString.valueFor("fee") };
};
/*  ===============================  */

/*  ==========================================================================  */

/*  ===========================================  */
/*  ARK::API::DelegateGettable::forgedByAccount  */

/*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
String ARK::API::DelegateGettable::forgedByAccount(ARK::Utilities::Network::Manager _netManager, Publickey _generatorPublicKey) {
  String uri = ARK::API::Endpoints::Delegate::getForgedByAccount_s;
    uri += "?generatorPublicKey=" + _generatorPublicKey.description();
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  else { return ARK::API::DelegateGettable::forgedByAccountfromJSON(callback); };
};

/*
{
  "success":true,
  "fees":"44300000000",
  "rewards":"7626000000000",
  "forged":"7670300000000"
}
*/
String ARK::API::DelegateGettable::forgedByAccountfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Delegate::ForgedByAccountResponse forgedByAccount = {
    jString.valueFor("fees"),
    jString.valueFor("rewards"),
    jString.valueFor("forged")
  };
  return forgedByAccount.description();
};
/*  ===========================================  */

/*  ==========================================================================  */

/*  =======================================  */
/*  ARK::API::DelegateGettable::nextForgers  */

/*  /api/delegates/forging/getNextForgers  */
ARK::Delegate::NextForgersResponse ARK::API::DelegateGettable::nextForgers(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Delegate::getNextForgers_s;
  String callback = _netManager.cb(uri);
  return ARK::API::DelegateGettable::nextForgersfromJSON(callback);
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
ARK::Delegate::NextForgersResponse ARK::API::DelegateGettable::nextForgersfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  Publickey delegates[10];
  for (int i = 0; i < 10; i++) {
    delegates[i] = jString.subvalueFor("delegates", i);
  };
  return {
    jString.valueFor("currentBlock"),
    jString.valueFor("currentSlot"),
    delegates
  };
};
/*  =======================================  */



#endif
