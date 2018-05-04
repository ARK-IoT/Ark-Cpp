

#ifndef SIGNATURE_GETTABLE_H
#define SIGNATURE_GETTABLE_H

#include "types/balance.h"
#include "api/paths.h"
#include "utilities/connector.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
namespace Signature
{
/*************************************************
*	PROTECTED: ARK::API::Signature::Gettable
**************************************************/
class Gettable
{
	protected:
		/*************************************************
		* ARK::API::SignatureGettable::fee
		*	/api/signatures/fee
		**************************************************/
		Balance fee(
				ARK::Utilities::Network::Connector &netConnector
		);
		/*************************************************/

};
/*************************************************/

};
};
};

#endif
