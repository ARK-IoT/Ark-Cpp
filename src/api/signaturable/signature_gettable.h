

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
    Balance fee(ARK::Utilities::Network::Connector _netConnector);
    Balance feefromJSON(String _jsonStr);
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
Balance ARK::API::Signature::Gettable::fee(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Signatures::fee_s;

  String callback = _netConnector.cb(uri);

  return ARK::API::Signature::Gettable::feefromJSON(callback);
}

/*
{
  "success":true,
  "fee":  Balance
}
*/
Balance ARK::API::Signature::Gettable::feefromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return jString.valueFor("fee");
}
/*  ================================  */
/*  ==========================================================================  */

#endif