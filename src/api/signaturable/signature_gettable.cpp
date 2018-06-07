

#include "api/signaturable/signature_gettable.h"

namespace ARK
{
namespace API
{
namespace Signature
{
/*************************************************
* ARK::API::SignatureGettable::fee
*	/api/signatures/fee
*
*	{
*		"success":true,
*		"fee":  Balance
*	}
**************************************************/
Balance ARK::API::Signature::Gettable::fee(ARK::Utilities::Network::Connector &netConnector)
{
	auto callback = netConnector.callback(ARK::API::Paths::Signatures::fee_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return Balance(convert_to_double(parser->valueFor("fee")));
}
/*************************************************/

};
};
};
