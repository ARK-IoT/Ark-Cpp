

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
    Balance fee(ARK::Utilities::Network::Connector& netConnector);
    Balance feefromJSON(const char* const jsonStr);
    /*************************************************/

};
/*************************************************/

};
};
};



/*************************************************
* ARK::API::SignatureGettable::fee
*   /api/signatures/fee
**************************************************/
Balance ARK::API::Signature::Gettable::fee(ARK::Utilities::Network::Connector& netConnector)
{
	auto callback = netConnector.cb(ARK::API::Paths::Signatures::fee_s);
	return ARK::API::Signature::Gettable::feefromJSON(callback);
}
/*************************************************
*
*	{
*		"success":true,
*		"fee":  Balance
*	}
*
**************************************************/

Balance ARK::API::Signature::Gettable::feefromJSON(const char* const jsonStr)
{
  ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
  return Balance(parser.valueFor("fee"));
}
/*************************************************/


#endif