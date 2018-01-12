

#ifndef api_account_h
#define api_account_h

namespace ARK {
  namespace API { 
    namespace Account {


      namespace Get {


        /*   {"success":true,"balance":"_balance","unconfirmedBalance":"_u_balance"}  */
        String balancefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("balance") + " | " + jString.valueFor("unconfirmedBalance");
        };
        /*  /api/accounts/getBalance?address=arkAddress */
        String balance(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::getBalance_s;
            uri += "?address=" + _arkAddress;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::Get::balancefromJSON(callback);
        };





        /*  {"success":true,"publicKey":"_pubkey"} */
        String publickeyfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("publicKey");
        };
        /*  /api/accounts/getPublickey?address=arkAddress */
        String publickey(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::getPublickey_s;
            uri += "?address=" + _arkAddress;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::Get::publickeyfromJSON(callback);
        };



        

        /*  {"success":true,"fee":2500000000} */
        String delegatesFeefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("fee");
        };
        /*  /api/accounts/delegates/fee?address=arkAddress  */
        String delegatesFee(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::delegatesFee_s;
            uri += "?address=" + _arkAddress;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::Get::delegatesFeefromJSON(callback);
        };





        /*
        { "success":true,
          "delegates":[{
            "username":"sleepdeficit",
            "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
            "publicKey":"_pubKey",
            "vote":"7481085341862",
            "producedblocks":31138,
            "missedblocks":2991,
            "rate":19,
            "approval":0.06,
            "productivity":91.24
          }]
        }
        */
        String delegatesfromJSON(String _jsonStr) {
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
        /*  /api/accounts/delegates?address=arkAddress  */
        String delegates(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::delegates_s;
            uri += "?address=" + _arkAddress;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::Get::delegatesfromJSON(callback);
        };





        /*
        { "success":true,
          "account":{
            "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
            "unconfirmedBalance":"0",
            "balance":"0",
            "publicKey":"_pubkey",
            "unconfirmedSignature":1,
            "secondSignature":1,
            "secondPublicKey":"_spubkey",
            "multisignatures":[],
            "u_multisignatures":[]
          }
        }
        */
        String accountsfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::Account account = {
            jString.valueFor("address"),
            jString.valueFor("unconfirmedBalance"),
            jString.valueFor("balance"),
            jString.valueFor("publicKey"),
            jString.valueFor("unconfirmedSignature").toInt(),
            jString.valueFor("secondSignature").toInt(),
            jString.valueFor("secondPublicKey"),
            jString.valueFor("multisignatures"),
            jString.valueFor("u_multisignatures")
          };
          return account.description();
        };
        /*  /api/accounts?address=arkAddress  */
        String accounts(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::accounts_s;
            uri += "?address=" + _arkAddress;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::Get::accountsfromJSON(callback);
        };



      };




      namespace accounts_cb {

        struct addDelegatesResponse {
          public:
            String secret;
            String publicKey;
            String secondSecret;
        };

      };
      
      
    };
  };
};

#endif
