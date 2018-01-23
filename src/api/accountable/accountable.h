

#ifndef accountable_h
#define accountable_h

#include "account_gettable.h"

namespace ARK {
  namespace API {

    /*  =============================  */
    /*  PUBLIC: ARK::API::Accountable  */
    class Accountable : public AccountGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/accounts/getBalance?address=arkAddress */
        ARK::Account::BalanceResponse accountBalance(Address _arkAddress)
        { return ARK::API::AccountGettable::balance(this->netManager, _arkAddress); };

/*  ==========================================================================  */

        /*  /api/accounts/getPublickey?address=arkAddress */
        Publickey accountPublickey(Address _arkAddress)
        { return ARK::API::AccountGettable::publickey(this->netManager, _arkAddress); };

/*  ==========================================================================  */

        /*  /api/accounts/delegates/fee?address=arkAddress  */
        Balance accountDelegatesFee(Address _arkAddress)
        { return ARK::API::AccountGettable::delegatesFee(this->netManager, _arkAddress); };

/*  ==========================================================================  */

        /*  /api/accounts/delegates?address=arkAddress  */
        ARK::Delegate accountDelegates(Address _arkAddress)
        { return ARK::API::AccountGettable::delegates(this->netManager, _arkAddress); };

/*  ==========================================================================  */

        /*  /api/accounts?address=arkAddress  */
        ARK::Account account(Address _arkAddress)
        { return ARK::API::AccountGettable::account(this->netManager, _arkAddress); };

/*  ==========================================================================  */

    };
    /*  =============================  */

  };
};


#endif
