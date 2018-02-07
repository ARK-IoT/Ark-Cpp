

#ifndef SIGNATURE_GETTABLE_H
#define SIGNATURE_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Signature
{
/*  ==========================================================================  */
/*  ========================================  */
/*  PROTECTED: ARK::API::Signature::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/signatures/fee  */
    Balance fee(const ARK::Utilities::Network::Connector& _netConnector);
    Balance feefromJSON(const char* const _jsonStr);
/*  ==========================================================================  */
};
/*  ========================================  */
/*  ==========================================================================  */

};
};
};



/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::SignatureGettable::fee  */
/*  /api/signatures/fee  */
Balance ARK::API::Signature::Gettable::fee(const ARK::Utilities::Network::Connector& _netConnector)
{
    auto callback = _netConnector.cb(ARK::API::Paths::Signatures::fee_s);

    return ARK::API::Signature::Gettable::feefromJSON(callback);
}

/*
{
  "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Signature::Gettable::feefromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return jString.valueFor("fee");
}
/*  ================================  */
/*  ==========================================================================  */

#endif