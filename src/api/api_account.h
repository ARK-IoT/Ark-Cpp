

#ifndef api_account_h
#define api_account_h

#include "api_model.h"

namespace ARK {
  namespace API { 
    namespace Account {

      struct TopAccount {
        public:
          String address;
          long double balance;
          String publicKey;
      };


      namespace accounts_cb {

        struct getBalanceResponse {
          public:
            bool success;
            long double balance;
            long double unconfirmedBalance;
        };
        
        struct getPublickeyResponse {
          public:
            bool success;
            String publicKey;
        };

        struct getDelegatesFeeResponse {
          public:
            bool success;
            long double fee;
        };
        
        struct getDelegatesResponse {
          public:
            bool success;
            ARK::Model::Delegate delegates[];
        };

        struct addDelegatesResponse{
          public:
            String secret;
            String publicKey;
            String secondSecret;
        };

        class Signature {};
        struct getAccountResponse_t {
          public:
            String address;
            long double unconfirmedBalance;
            long double balance;
            String publicKey;
            long int unconfirmedSignature;
            long int secondSignature;
            String secondPublicKey;
            Signature multisignatures[];
            Signature u_multisignatures [];
        };
        struct getAccountResponse{
          public:
            bool success;
            getAccountResponse_t getAccountResponse [];
        };

        struct getAllAccountsResponse {
          public:
            bool success; // Indicates whether or not errors occurred
        };

        struct topAccountResponse_t {
          public:
            String address;
            long double balance;
            String publicKey;
        };
        struct topResponse{
          public:
            bool success;
            topAccountResponse_t accounts[];
        };

      };

      
    };
  };
};

#endif
