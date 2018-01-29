

#ifndef SIGNATURABLE_H
#define SIGNATURABLE_H

#include "signature_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  ==============================  */
/*  PUBLIC: ARK::API::Signaturable  */
class Signaturable :
  public Signature::Gettable,
  virtual ARK::Utilities::Network::Connectable
{
  public:
/*  ==========================================================================  */
    /*  /api/signatures/fee  */
    Balance signaturesFee()
    {
      return ARK::API::Signature::Gettable::fee(this->netConnector);
    };
/*  ==========================================================================  */
};
/*  ==============================  */
/*  ==========================================================================  */

// namespace signature_cb {
//   struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};
// };
};
};

#endif
