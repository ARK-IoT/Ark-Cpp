

#ifndef signaturable_h
#define signaturable_h

#include "signature_gettable.h"

namespace ARK {
  namespace API {

    /*  ==============================  */
    /*  PUBLIC: ARK::API::Signaturable  */
    class Signaturable : public SignatureGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/signatures/fee  */
        Balance signaturesFee()
        { return ARK::API::SignatureGettable::fee(this->netManager); };

/*  ==========================================================================  */

    };
    /*  ==============================  */

    // namespace signature_cb {
    //   struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};
    // };

  };
};


#endif
