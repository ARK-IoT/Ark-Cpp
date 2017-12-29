

#ifndef api_account_h
#define api_account_h

namespace ARK {
  namespace API { 
    namespace Account {

      namespace accounts_cb {

        struct getBalanceResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double balance;
            long double unconfirmedBalance;
        };
        
        struct getPublickeyResponse : virtual ARK::API::Helpers::Successable {
          public:
            String publicKey;
        };

        struct getDelegatesFeeResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double fee;
        };
        
        struct getDelegatesResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Delegate delegates[];
        };

        struct addDelegatesResponse {
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
        struct getAccountResponse : virtual ARK::API::Helpers::Successable {
          public:
            getAccountResponse_t getAccountResponse [];
        };

        struct getAllAccountsResponse :virtual ARK::API::Helpers::Successable {};// whether or not errors occurred
        
        struct topResponse : virtual ARK::API::Helpers::Successable {
          public:
            struct TopAccount {
              public:
                String address;
                long double balance;
                String publicKey;
            };
        };

      };
      
      
    };
  };
};

#endif
