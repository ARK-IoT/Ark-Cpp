

#ifndef SIGNATURE_GETTABLE_H
#define SIGNATURE_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Signature
{
/*************************************************
*  PROTECTED: ARK::API::Signature::Gettable
**************************************************/
class Gettable
{
  protected:
    /*************************************************
    * ARK::API::SignatureGettable::fee
    *   /api/signatures/fee
    **************************************************/
    Balance fee(ARK::Utilities::Network::Connector& netConnector)
    {
      auto callback = netConnector.cb(ARK::API::Paths::Signatures::fee_s);
      return feefromJSON(callback);
    }
    /*************************************************
    *
    *	{
    *		"success":true,
    *		"fee":  Balance
    *	}
    *
    **************************************************/

    Balance feefromJSON(const char* const jsonStr)
    {
      ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
      return Balance(parser.valueFor("fee"));
    }
    /*************************************************/

};
/*************************************************/

};
};
};

#endif
