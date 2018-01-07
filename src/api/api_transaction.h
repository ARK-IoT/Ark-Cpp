

#ifndef api_transaction_h
#define api_transaction_h

namespace ARK {
  namespace API {
    namespace Transaction {
        

      namespace transaction_cb {
        
        struct getTransactionResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Transaction transaction;
        };
          
        struct getTransactionsResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Transaction transactions[];
        };
        
        struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getUnconfirmedTransactionResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getUnconfirmedTransactionsResponse : virtual ARK::API::Helpers::Successable {};
          
      };


    };
  };
};

#endif
