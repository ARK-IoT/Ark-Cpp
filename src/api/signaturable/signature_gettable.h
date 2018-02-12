

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
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);
    Balance feefromJSON(const char* const _jsonStr);
    Balance feefromJSON(const String& _jsonStr) {
        return feefromJSON(_jsonStr.c_str());
    }
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
Balance ARK::API::Signature::Gettable::fee(ARK::Utilities::Network::Connector& _netConnector)
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

  return Balance(jString.valueFor("fee").c_str());
}
/*  ================================  */
/*  ==========================================================================  */

#endif