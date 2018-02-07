

#ifndef ACCOUNT_GETTABLE_H
#define ACCOUNT_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Account
{

/*  ==========================================================================  */
/*  ======================================  */
/*  PROTECTED: ARK::API::Account::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    ARK::API::Account::Respondable::Balances balance(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::API::Account::Respondable::Balances balancefromJSON(const char* const _jsonStr);
    ARK::API::Account::Respondable::Balances balancefromJSON(const String& _jsonStr) {
        return balancefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    Publickey publickey(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    Publickey publickeyfromJSON(const char* const _jsonStr);
    Publickey publickeyfromJSON(const String& _jsonStr) {
        return publickeyfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    Balance delegatesFee(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    Balance delegatesFeefromJSON(const char* const _jsonStr);
    Balance delegatesFeefromJSON(const String& _jsonStr) {
        return delegatesFeefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    ARK::Delegate delegates(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::Delegate delegatesfromJSON(const char* const _jsonStr);
    ARK::Delegate delegatesfromJSON(const String& _jsonStr) {
        return delegatesfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    ARK::Account account(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::Account accountfromJSON(const char* const _jsonStr);
    ARK::Account accountfromJSON(const String& _jsonStr) {
        return accountfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ======================================  */
/*  ==========================================================================  */
};
};
};




/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Account::Gettable::balance  */
/*  /api/accounts/getBalance?address=arkAddress */
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balance(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO: check size
    strcpy(uri, ARK::API::Paths::Account::getBalance_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.description());
  
    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::balancefromJSON(callback);
};

/*
{ "success":true,
  "balance":  "Balance",
  "unconfirmedBalance": "Balance"
}
*/
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balancefromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return ARK::API::Account::Respondable::Balances(Balance(jString.valueFor("balance").c_str()), Balance(jString.valueFor("unconfirmedBalance").c_str()));
};
/*  ==================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::publickey  */
/*  /api/accounts/getPublickey?address=arkAddress */
Publickey ARK::API::Account::Gettable::publickey(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.description());

    auto callback = netManager.cb(uri);
    return ARK::API::Account::Gettable::publickeyfromJSON(callback);
};

/*
{ "success":true,
  "publicKey":  "Publickey"
}
*/
Publickey ARK::API::Account::Gettable::publickeyfromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return Publickey(jString.valueFor("publicKey").c_str());
};
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Account::Gettable::delegatesFee  */
/*  /api/accounts/delegates/fee?address=arkAddress  */
Balance ARK::API::Account::Gettable::delegatesFee(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{

    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.description());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::delegatesFeefromJSON(callback);
};

/*
{ "success":true,
  "fee":2500000000
}
*/
Balance ARK::API::Account::Gettable::delegatesFeefromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return Balance(jString.valueFor("fee").c_str());
};
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Gettable::delegates  */
/*  /api/accounts/delegates?address=arkAddress  */
ARK::Delegate ARK::API::Account::Gettable::delegates(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegates_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.description());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::delegatesfromJSON(callback);
};

/*
{ "success":true,
  "delegates":[{
    "username": "sleepdeficit",
    "address":  "Address",
    "publicKey":  "Publickey",
    "vote": "Balance",
    "producedblocks": String,
    "missedblocks": String,
    "rate": int,
    "approval": double,
    "productivity": double
  }]
}
*/
ARK::Delegate ARK::API::Account::Gettable::delegatesfromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

    return Delegate(
        jString.subarrayValueIn("delegates", 0, "username").c_str(),
        jString.subarrayValueIn("delegates", 0, "address").c_str(),
        jString.subarrayValueIn("delegates", 0, "publicKey").c_str(),
        jString.subarrayValueIn("delegates", 0, "vote").c_str(),
        jString.subarrayValueIn("delegates", 0, "producedblocks").toInt(),
        jString.subarrayValueIn("delegates", 0, "missedblocks").toInt(),
        jString.subarrayValueIn("delegates", 0, "rate").toInt(),
        jString.subarrayValueIn("delegates", 0, "approval").toFloat(),
        jString.subarrayValueIn("delegates", 0, "productivity").toFloat()
    );
};
/*  ======================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::account  */
/*  /api/accounts?address=arkAddress  */
ARK::Account ARK::API::Account::Gettable::account(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::accounts_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.description());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::accountfromJSON(callback);
};

/*
{ "success":true,
  "account":{
    "address":  "Address",
    "unconfirmedBalance": "Balance",
    "balance":  "Balance",
    "publicKey":  "Publickey",
    "unconfirmedSignature": int,
    "secondSignature":  int,
    "secondPublicKey":  "Publickey",
    "multisignatures":[],
    "u_multisignatures":[]
  }
}
*/
ARK::Account ARK::API::Account::Gettable::accountfromJSON(const char* const _jsonStr)
{
    ARK::Utilities::JSONString jString(_jsonStr);

    return ARK::Account(
        jString.subvalueIn("account", "address").c_str(),
        jString.subvalueIn("account", "unconfirmedBalance").c_str(),
        jString.subvalueIn("account", "balance").c_str(),
        jString.subvalueIn("account", "publicKey").c_str(),
        jString.subvalueIn("account", "unconfirmedSignature").toInt(),
        jString.subvalueIn("account", "secondSignature").toInt(),
        jString.subvalueIn("account", "secondPublicKey").c_str(),
        jString.subvalueIn("account", "multisignatures").c_str(),
        jString.subvalueIn("account", "u_multisignatures").c_str()
    );
};
/*  ====================================  */
/*  ==========================================================================  */

#endif
