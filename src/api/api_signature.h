

#ifndef api_signature_h
#define api_signature_h

namespace ARK {
  namespace API {
    namespace Signature {

      namespace signature_cb {

        struct feeResponse {
          public:
            bool success;
            long int fee;
        };

        struct addSignatureResponse {
          public:
            bool success;
        };

      };
      
    };
  };
};

#endif
