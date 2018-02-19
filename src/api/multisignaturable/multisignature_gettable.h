

#ifndef MULTISIGNATURE_GETTABLE_H
#define MULTISIGNATURE_GETTABLE_H

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
		*   /api/multisignatures/pending?publicKey=
		**************************************************/
    const char* pending(ARK::Utilities::Network::Connector& netConnector, const Publickey& publicKey);
    
		const char* pendingfromJSON(const char* const jsonStr);
    /*************************************************/


/**************************************************************************************************/


    /*************************************************/
    /*************************************************/
    /*  Only on Mainnet?  */
    // /*  /api/multisignatures/accounts?publicKey=  */
    // String accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey);
    // /*  ???  */
    // String accountsfromJSON(String _jsonStr);
    /*************************************************/
    /*************************************************/


};
/*************************************************/

};
};
};


/*************************************************
* ARK::API::MultiSignatureGettable::pending
*   /api/multisignatures/pending?publicKey=
**************************************************/
const char* ARK::API::MultiSignature::Gettable::pending(
    ARK::Utilities::Network::Connector& netConnector, 
    const Publickey& publicKey
)
{
	char uri[512] = { '\0' }; //TODO: check size

	strcpy(uri, ARK::API::Paths::MultiSignatures::pending_s);
	strcat(uri, "?publicKey=");
	strcat(uri, publicKey.getValue());

	auto callback = netConnector.cb(uri);
	return ARK::API::MultiSignature::Gettable::pendingfromJSON(callback);
};
/*************************************************
*
*	{
*		"success":true,
*		"transactions":[]
*	}
*
**************************************************/
const char* ARK::API::MultiSignature::Gettable::pendingfromJSON(const char* const jsonStr)
{
  ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
  return parser.valueFor("transactions");
};
/*************************************************/


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

#endif
