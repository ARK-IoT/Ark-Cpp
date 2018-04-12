#include "api/multisignaturable/multisignature_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>

namespace ARK
{
namespace API
{
namespace MultiSignature
{

/*************************************************
* ARK::API::MultiSignatureGettable::pending
* /api/multisignatures/pending?publicKey=
*
*	{
*		"success":true,
*		"transactions":[]
*	}
**************************************************/
const char *ARK::API::MultiSignature::Gettable::pending(
    ARK::Utilities::Network::Connector &netConnector,
    const Publickey &publicKey
)
{
  char uri[512] = {'\0'}; //TODO: check size
    strcpy(uri, ARK::API::Paths::MultiSignatures::pending_s);
    strcat(uri, "?publicKey=");
    strcat(uri, publicKey.getValue());

  auto callback = netConnector.cb(uri);

  auto parser = ARK::Utilities::make_json_string(callback);

  return parser->valueFor("transactions");
};
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
};
};
