

#ifndef ACCOUNT_GETTABLE_H
#define ACCOUNT_GETTABLE_H

#include "account_respondable.h"
#include "account.h"
#include "connector.h"
#include "address.h"
#include "balance.h"
#include "publickey.h"
#include "delegate.h"

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

#endif
