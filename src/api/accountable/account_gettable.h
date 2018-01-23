

#ifndef account_gettable_h
#define account_gettable_h

namespace ARK {
  namespace API {

    /*  ====================================  */
    /*  PROTECTED: ARK::API::AccountGettable  */
    class AccountGettable {
      protected:

/*  ==========================================================================  */

        ARK::Account::BalanceResponse balance(ARK::Utilities::Network::Manager _netManager, Address _arkAddress);
        ARK::Account::BalanceResponse balancefromJSON(String _jsonStr);

/*  ==========================================================================  */

        Publickey publickey(ARK::Utilities::Network::Manager _netManager, Address _arkAddress);
        Publickey publickeyfromJSON(String _jsonStr);

/*  ==========================================================================  */

        Balance delegatesFee(ARK::Utilities::Network::Manager _netManager, Address _arkAddress);
        Balance delegatesFeefromJSON(String _jsonStr);

/*  ==========================================================================  */

        ARK::Delegate delegates(ARK::Utilities::Network::Manager _netManager, Address _arkAddress);
        ARK::Delegate delegatesfromJSON(String _jsonStr);

/*  ==========================================================================  */

        ARK::Account account(ARK::Utilities::Network::Manager _netManager, Address _arkAddress);
        ARK::Account accountfromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  ====================================  */

  };
};

/*  ==========================================================================  */

/*  ==================================  */
/*  ARK::API::AccountGettable::balance  */

/*  /api/accounts/getBalance?address=arkAddress */
ARK::Account::BalanceResponse ARK::API::AccountGettable::balance(ARK::Utilities::Network::Manager _netManager, Address _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getBalance_s;
    uri += "?address=" + _arkAddress.description();
  String callback = _netManager.cb(uri);    
  return ARK::API::AccountGettable::balancefromJSON(callback);
};

/*
{ "success":true,
  "balance":"_balance",
  "unconfirmedBalance":"_u_balance"
}
*/
ARK::Account::BalanceResponse ARK::API::AccountGettable::balancefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return { jString.valueFor("balance"), jString.valueFor("unconfirmedBalance") };
};
/*  ==================================  */

/*  ==========================================================================  */

/*  ====================================  */
/*  ARK::API::AccountGettable::publickey  */

/*  /api/accounts/getPublickey?address=arkAddress */
Publickey ARK::API::AccountGettable::publickey(ARK::Utilities::Network::Manager _netManager, Address _arkAddress) {
  String uri = ARK::API::Endpoints::Account::getPublickey_s;
    uri += "?address=" + _arkAddress.description();
  String callback = _netManager.cb(uri);
  return ARK::API::AccountGettable::publickeyfromJSON(callback);
};

/*
{ "success":true,
  "publicKey":"_pubkey"
}
*/
Publickey ARK::API::AccountGettable::publickeyfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return { Publickey( jString.valueFor("publicKey") ) };
};
/*  ====================================  */

/*  ==========================================================================  */

/*  =======================================  */
/*  ARK::API::AccountGettable::delegatesFee  */

/*  /api/accounts/delegates/fee?address=arkAddress  */
Balance ARK::API::AccountGettable::delegatesFee(
  ARK::Utilities::Network::Manager _netManager,
  Address _arkAddress) {
    String uri = ARK::API::Endpoints::Account::delegatesFee_s;
      uri += "?address=" + _arkAddress.description();
    String callback = _netManager.cb(uri);
    return ARK::API::AccountGettable::delegatesFeefromJSON(callback);
};

/*
{ "success":true,
  "fee":2500000000
}
*/
Balance ARK::API::AccountGettable::delegatesFeefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return { jString.valueFor("fee") };
};
/*  =======================================  */

/*  ==========================================================================  */

/*  ====================================  */
/*  ARK::API::AccountGettable::delegates  */

/*  /api/accounts/delegates?address=arkAddress  */
ARK::Delegate ARK::API::AccountGettable::delegates(ARK::Utilities::Network::Manager _netManager, Address _arkAddress) {
  String uri = ARK::API::Endpoints::Account::delegates_s;
    uri += "?address=" + _arkAddress.description();
  String callback = _netManager.cb(uri);
  return ARK::API::AccountGettable::delegatesfromJSON(callback);
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
ARK::Delegate ARK::API::AccountGettable::delegatesfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
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
};
/*  ====================================  */

/*  ==========================================================================  */

/*  ==================================  */
/*  ARK::API::AccountGettable::account  */

/*  /api/accounts?address=arkAddress  */
ARK::Account ARK::API::AccountGettable::account(ARK::Utilities::Network::Manager _netManager, Address _arkAddress) {
  String uri = ARK::API::Endpoints::Account::accounts_s;
    uri += "?address=" + _arkAddress.description();
  String callback = _netManager.cb(uri);
  return ARK::API::AccountGettable::accountfromJSON(callback);
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
ARK::Account ARK::API::AccountGettable::accountfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
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
};
/*  ==================================  */



#endif
