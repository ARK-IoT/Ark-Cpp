

#ifndef api_multisignature_h
#define api_multisignature_h

namespace ARK {
  namespace API {
    namespace MultiSignature {


      namespace multisignature_cb {

        struct pendingResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int fee;
        };

        struct signResponse : virtual ARK::API::Helpers::Successable {};
        
        struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getAccountsResponse : virtual ARK::API::Helpers::Successable {};

      };


    };
  };
};

#endif
