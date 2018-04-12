

#ifndef MULTISIGNATURE_GETTABLE_H
#define MULTISIGNATURE_GETTABLE_H

#include "utilities/connector.h"
#include "types/publickey.h"

namespace ARK
{
namespace API
{
namespace MultiSignature
{
/*************************************************
*  PROTECTED: ARK::API::MultiSignature::Gettable
**************************************************/
class Gettable
{
	protected:
		/*************************************************
		* ARK::API::MultiSignatureGettable::pending
		*	/api/multisignatures/pending?publicKey=
		**************************************************/
		const char *pending(
				ARK::Utilities::Network::Connector &netConnector,
				const Publickey &publicKey
		);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************/
		/*************************************************/
		/*  Only on Mainnet?  */
		// /*  /api/multisignatures/accounts?publicKey=  */
		// String accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey);
		/*************************************************/
		/*************************************************/

};
/*************************************************/

};
};
};

#endif

/**************************************************************************************************/
/*************************************************/
/*************************************************/
/*  ARK::API::MultiSignature::Gettable::accounts  */
// /*  /api/multisignatures/accounts?publicKey=  */
// String ARK::API::MultiSignatureGettable::accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey) {
//   String uri = ARK::API::Paths::MultiSignatures::accounts_s;
//     uri += "?publicKey=";
//     uri += _publicKey;
//   String callback = _netConnector.cb(uri);
//   return ARK::API::MultiSignature::Gettable::accountsfromJSON(callback);
// };

/*  Only on Mainnet?  */
// String ARK::API::MultiSignature::Gettable::accountsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   return jString.valueFor("??");
// };
/*  ==========================================  */
/*************************************************/
/*************************************************/
/**************************************************************************************************/
