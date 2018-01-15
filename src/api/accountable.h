

#ifndef accountable_h
#define accountable_h

namespace ARK {
  namespace API { 


    class AccountGettable {
      protected:

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


    class Accountable : public AccountGettable, virtual ARK::Utilities::Network::Managable {
      public: 

        /*  /api/accounts/getBalance?address=arkAddress */
        String accountBalance(String _arkAddress)
        { return ARK::API::AccountGettable::balance(this->netManager, _arkAddress); };

        /*  /api/accounts/getPublickey?address=arkAddress */
        String accountPublickey(String _arkAddress)
        { return ARK::API::AccountGettable::publickey(this->netManager, _arkAddress); };

        /*  /api/accounts/delegates/fee?address=arkAddress  */
        String accountDelegatesFee(String _arkAddress)
        { return ARK::API::AccountGettable::delegatesFee(this->netManager, _arkAddress); };

        /*  /api/accounts/delegates?address=arkAddress  */
        String accountDelegates(String _arkAddress)
        { return ARK::API::AccountGettable::delegates(this->netManager, _arkAddress); };

        /*  /api/accounts?address=arkAddress  */
        String account(String _arkAddress)
        { return ARK::API::AccountGettable::account(this->netManager, _arkAddress); };

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
String ARK::API::AccountGettable::balancefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Account::Account::AccountBalanceResponse balances = {
    jString.valueFor("balance"),
    jString.valueFor("unconfirmedBalance")
  };
  return balances.description();
};

/*  /api/accounts/getBalance?address=arkAddress */
String ARK::API::AccountGettable::balance(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getBalance_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::AccountGettable::balancefromJSON(callback);
};




/*
{
  "success":true,
  "publicKey":"_pubkey"
}
*/
String ARK::API::AccountGettable::publickeyfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("publicKey");
};

/*  /api/accounts/getPublickey?address=arkAddress */
String ARK::API::AccountGettable::publickey(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getPublickey_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::AccountGettable::publickeyfromJSON(callback);
};




/*
{
  "success":true,
  "fee":2500000000
}
*/
String ARK::API::AccountGettable::delegatesFeefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("fee");
};

/*  /api/accounts/delegates/fee?address=arkAddress  */
String ARK::API::AccountGettable::delegatesFee(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::delegatesFee_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::AccountGettable::delegatesFeefromJSON(callback);
};




/*
{ "success":true,
  "delegates":[{
    "username":"sleepdeficit",
    "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
    "publicKey":"_pubKey",
    "vote":"_vote",
    "producedblocks":_producedBlocks,
    "missedblocks":_missedblocks,
    "rate":_rate,
    "approval":_approval,
    "productivity":_productivity
  }]
}
*/
String ARK::API::AccountGettable::delegatesfromJSON(String _jsonStr) {
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
String ARK::API::AccountGettable::delegates(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::delegates_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::AccountGettable::delegatesfromJSON(callback);
};




/*
{ "success":true,
  "account":{
    "address":"_arkAddress",
    "unconfirmedBalance":"_unconfirmedBalance",
    "balance":"_balance",
    "publicKey":"_pubkey",
    "unconfirmedSignature":_unconfirmedSignature,
    "secondSignature":_secondSignature,
    "secondPublicKey":"_secondPubkey",
    "multisignatures":[],
    "u_multisignatures":[]
  }
}
*/
String ARK::API::AccountGettable::accountfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Account account = {
    jString.subvalueIn("account", "address"),
    jString.subvalueIn("account", "unconfirmedBalance"),
    jString.subvalueIn("account", "balance"),
    jString.subvalueIn("account", "publicKey"),
    jString.subvalueIn("account", "unconfirmedSignature").toInt(),
    jString.subvalueIn("account", "secondSignature").toInt(),
    jString.subvalueIn("account", "secondPublicKey"),
    jString.subvalueIn("account", "multisignatures"),
    jString.subvalueIn("account", "u_multisignatures")
  };
  return account.description();
};

/*  /api/accounts?address=arkAddress  */
String ARK::API::AccountGettable::account(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
  String uri = ARK::API::Endpoints::Account::accounts_s;
    uri += "?address=" + _arkAddress;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::AccountGettable::accountfromJSON(callback);
};


#endif
