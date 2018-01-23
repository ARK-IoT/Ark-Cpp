

#ifndef transactionable_h
#define transactionable_h

#include "transaction_gettable.h"

namespace ARK {
  namespace API {

    /*  =================================  */
    /*  PUBLIC: ARK::API::Transactionable  */
    class Transactionable : public TransactionGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/transactions/get?id=  */
        ARK::Transaction transaction(Hash _id)
        { return ARK::API::TransactionGettable::transaction(this->netManager, _id); };

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks  */
    /*    Peers callback is ~28,908 bytes  */
        /*  /api/transactions  */
        // String transactions()
        // { return ARK::API::TransactionGettable::transactions(this->netManager); };
/*  ==========================================================================  */

        /*  /api/transactions/unconfirmed/get?id=  */
        ARK::Transaction transactionUnconfirmed(Hash _id)
        { return ARK::API::TransactionGettable::transactionUnconfirmed(this->netManager, _id); };

/*  ==========================================================================  */

        /*  /api/transactions/unconfirmed/  */
        ARK::Transaction transactionsUnconfirmed()
        { return ARK::API::TransactionGettable::transactionsUnconfirmed(this->netManager); };

/*  ==========================================================================  */

    };
    /*  =================================  */

  // namespace transaction_cb {
  //   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
  // };

  };
};


#endif
