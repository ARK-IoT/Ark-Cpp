

#ifndef api_signature_h
#define api_signature_h

namespace ARK {
  namespace API {
    namespace Signature {


      namespace signature_cb {

        struct feeResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int fee;
        };

        struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};

      };
      
      
    };
  };
};

#endif
