

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
        const ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::API::Account::Respondable::Balances balancefromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    Publickey publickey(
        const ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    Publickey publickeyfromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    Balance delegatesFee(
        const ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    Balance delegatesFeefromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    ARK::Delegate delegates(
        const ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::Delegate delegatesfromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    ARK::Account account(
        const ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

    ARK::Account accountfromJSON(const char* const _jsonStr);
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
    const ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO: check size
    strcpy(uri, ARK::API::Paths::Account::getBalance_s);
    strcat(uri, "?address=");
    const auto len = strlen(uri);
    arkAddress.description(uri + len, sizeof(uri) - len);
  
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

  return {jString.valueFor("balance"), jString.valueFor("unconfirmedBalance")};
};
/*  ==================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::publickey  */
/*  /api/accounts/getPublickey?address=arkAddress */
Publickey ARK::API::Account::Gettable::publickey(
    const ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
    strcat(uri, "?address=");
    const auto len = strlen(uri);
    arkAddress.description(uri + len, sizeof(uri) - len);

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

  return {Publickey(jString.valueFor("publicKey"))};
};
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Account::Gettable::delegatesFee  */
/*  /api/accounts/delegates/fee?address=arkAddress  */
Balance ARK::API::Account::Gettable::delegatesFee(
    const ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{

    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
    strcat(uri, "?address=");
    const auto len = strlen(uri);
    arkAddress.description(uri + len, sizeof(uri) - len);


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

  return {jString.valueFor("fee")};
};
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Gettable::delegates  */
/*  /api/accounts/delegates?address=arkAddress  */
ARK::Delegate ARK::API::Account::Gettable::delegates(
    const ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegates_s);
    strcat(uri, "?address=");
    const auto len = strlen(uri);
    arkAddress.description(uri + len, sizeof(uri) - len);

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

  return {
      jString.subarrayValueIn("delegates", 0, "username"),
      jString.subarrayValueIn("delegates", 0, "address"),
      jString.subarrayValueIn("delegates", 0, "publicKey"),
      jString.subarrayValueIn("delegates", 0, "vote"),
      jString.subarrayValueIn("delegates", 0, "producedblocks").toInt(),
      jString.subarrayValueIn("delegates", 0, "missedblocks").toInt(),
      jString.subarrayValueIn("delegates", 0, "rate").toInt(),
      jString.subarrayValueIn("delegates", 0, "approval").toFloat(),
      jString.subarrayValueIn("delegates", 0, "productivity").toFloat()};
};
/*  ======================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::account  */
/*  /api/accounts?address=arkAddress  */
ARK::Account ARK::API::Account::Gettable::account(
    const ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::accounts_s);
    strcat(uri, "?address=");
    const auto len = strlen(uri);
    arkAddress.description(uri + len, sizeof(uri) - len);


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

  return {
      jString.subvalueIn("account", "address"),
      jString.subvalueIn("account", "unconfirmedBalance"),
      jString.subvalueIn("account", "balance"),
      jString.subvalueIn("account", "publicKey"),
      jString.subvalueIn("account", "unconfirmedSignature").toInt(),
      jString.subvalueIn("account", "secondSignature").toInt(),
      jString.subvalueIn("account", "secondPublicKey"),
      jString.subvalueIn("account", "multisignatures"),
      jString.subvalueIn("account", "u_multisignatures")};
};
/*  ====================================  */
/*  ==========================================================================  */

#endif
