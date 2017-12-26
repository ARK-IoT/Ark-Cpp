

#ifndef api_transaction_h
#define api_transaction_h

#include "transaction.h"

namespace api_n {
  namespace transaction_n {
      
    namespace transaction_cb {
      
      struct TransactionsGetTransactionResponse {
        public:
          bool success;
          ARK::Model::Transaction transaction;
      };
        
      struct TransactionsGetTransactionsResponse {
        public:
          bool success;
          ARK::Model::Transaction transactions[];
      };
      
      struct TransactionsAddTransactionsResponse {
        public:
          bool success;
      };
      
      struct TransactionsGetUnconfirmedTransactionResponse {
        public:
          bool success;
      };
      
      struct TransactionsGetUnconfirmedTransactionsResponse {
        public:
          bool success;
      };
        
    };

  };
};

#endif
