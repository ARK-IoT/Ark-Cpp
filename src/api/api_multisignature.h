

#ifndef api_multisignature_h
#define api_multisignature_h

namespace ARK {
  namespace API {
    namespace MultiSignature {

      namespace multisignature_cb {

        struct pendingResponse {
          public:
            bool success;
            long int fee;
        };

        struct signResponse {
          public:
            bool success;
        };
        
        struct addMultisignatureResponse {
          public:
            bool success;
        };
        
        struct getAccountsResponse {
          public:
            bool success;
        };

      };

    };
  };
};

#endif
