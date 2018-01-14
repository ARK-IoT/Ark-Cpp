

#ifndef api_account_h
#define api_account_h

namespace ARK {
  namespace API { 
    namespace Account {

      namespace Get {

        /*  /api/accounts/getBalance?address=arkAddress */
        String balance(ARK::Utilities::Network::Manager _netManager, String _arkAddress);
        String balancefromJSON(String _jsonStr);

        /*  /api/accounts/getPublickey?address=arkAddress */
        String publickey(ARK::Utilities::Network::Manager _netManager, String _arkAddress);
        String publickeyfromJSON(String _jsonStr);

        /*  /api/accounts/delegates/fee?address=arkAddress  */
        String delegatesFee(ARK::Utilities::Network::Manager _netManager, String _arkAddress);
        String delegatesFeefromJSON(String _jsonStr);

        /*  /api/accounts/delegates?address=arkAddress  */
        String delegates(ARK::Utilities::Network::Manager _netManager, String _arkAddress);
        String delegatesfromJSON(String _jsonStr);

        /*  /api/accounts?address=arkAddress  */
        String account(ARK::Utilities::Network::Manager _netManager, String _arkAddress);
        String accountfromJSON(String _jsonStr);

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



/*
{
  "success":true,
  "balance":"_balance",
  "unconfirmedBalance":"_u_balance"
}
*/
String ARK::API::Account::Get::balancefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Account::Account::AccountBalanceResponse balances = {
    jString.valueFor("balance"),
    jString.valueFor("unconfirmedBalance")
  };
  return balances.description();
};

/*  /api/accounts/getBalance?address=arkAddress */
String ARK::API::Account::Get::balance(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getBalance_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Account::Get::balancefromJSON(callback);
};




/*
{
  "success":true,
  "publicKey":"_pubkey"
}
*/
String ARK::API::Account::Get::publickeyfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("publicKey");
};

/*  /api/accounts/getPublickey?address=arkAddress */
String ARK::API::Account::Get::publickey(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getPublickey_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Account::Get::publickeyfromJSON(callback);
};




/*
{
  "success":true,
  "fee":2500000000
}
*/
String ARK::API::Account::Get::delegatesFeefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("fee");
};

/*  /api/accounts/delegates/fee?address=arkAddress  */
String ARK::API::Account::Get::delegatesFee(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::delegatesFee_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
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
String ARK::API::Account::Get::delegatesfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Delegate delegate = {
    jString.subarrayValueIn("delegates", 0, "username"),
    jString.subarrayValueIn("delegates", 0, "address"),
    jString.subarrayValueIn("delegates", 0, "publicKey"),
    jString.subarrayValueIn("delegates", 0, "vote"),
    jString.subarrayValueIn("delegates", 0, "producedblocks").toInt(),
    jString.subarrayValueIn("delegates", 0, "missedblocks").toInt(),
    jString.subarrayValueIn("delegates", 0, "rate").toInt(),
    jString.subarrayValueIn("delegates", 0, "approval").toFloat(),
    jString.subarrayValueIn("delegates", 0, "productivity").toFloat()
  };
  return delegate.description();
};

/*  /api/accounts/delegates?address=arkAddress  */
String ARK::API::Account::Get::delegates(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::delegates_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
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
String ARK::API::Account::Get::accountfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Account account = {
    jString.valueIn("account", "address"),
    jString.valueIn("account", "unconfirmedBalance"),
    jString.valueIn("account", "balance"),
    jString.valueIn("account", "publicKey"),
    jString.valueIn("account", "unconfirmedSignature").toInt(),
    jString.valueIn("account", "secondSignature").toInt(),
    jString.valueIn("account", "secondPublicKey"),
    jString.valueIn("account", "multisignatures"),
    jString.valueIn("account", "u_multisignatures")
  };
  return account.description();
};

/*  /api/accounts?address=arkAddress  */
String ARK::API::Account::Get::account(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::accounts_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Account::Get::accountfromJSON(callback);
};


#endif
