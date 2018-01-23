

#ifndef multisignaturable_h
#define multisignaturable_h

#include "multisignature_gettable.h"

namespace ARK {
  namespace API {

    /*  ===================================  */
    /*  PUBLIC: ARK::API::MultiSignaturable  */

    class MultiSignaturable : public MultiSignatureGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/multisignatures/pending?publicKey=  */
        String multisignaturesPending(Hash _publicKey)
        { return ARK::API::MultiSignatureGettable::pending(this->netManager, _publicKey); };

/*  ==========================================================================  */
    // /*  Only on Mainnet?  */
    //     /*  /api/multisignatures/accounts?publicKey=  */
    //     String multisignaturesAccounts(String _publicKey)
    //     { return ARK::API::MultiSignatureGettable::accounts(this->netManager, _publicKey); };
/*  ==========================================================================  */

    };
    /*  ===================================  */


    // namespace multisignature_cb {
    //   struct signResponse : virtual ARK::API::Helpers::Successable {};
    //   struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
    // };


  };
};


#endif
