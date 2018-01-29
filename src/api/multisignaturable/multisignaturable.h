

#ifndef MULTISIGNATURABLE_H
#define MULTISIGNATURABLE_H

#include "multisignature_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  ===================================  */
/*  PUBLIC: ARK::API::MultiSignaturable  */
class MultiSignaturable :
    public MultiSignature::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
/*  ==========================================================================  */
    /*  /api/multisignatures/pending?publicKey=  */
    String multisignaturesPending(Publickey _publicKey)
    {
      return ARK::API::MultiSignature::Gettable::pending(this->netConnector, _publicKey);
    };
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
    // /*  Only on Mainnet?  */
    //     /*  /api/multisignatures/accounts?publicKey=  */
    //     String multisignaturesAccounts(String _publicKey)
    //     { return ARK::API::MultiSignature::Gettable::accounts(this->netConnector, _publicKey); };
/*  ==========================================================================  */
};
/*  ===================================  */
/*  ==========================================================================  */

// namespace multisignature_cb {
//   struct signResponse : virtual ARK::API::Helpers::Successable {};
//   struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};

#endif
