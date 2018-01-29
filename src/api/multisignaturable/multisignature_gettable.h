

#ifndef MULTISIGNATURE_GETTABLE_H
#define MULTISIGNATURE_GETTABLE_H

namespace ARK
{
namespace API
{
namespace MultiSignature
{
/*  ==========================================================================  */
/*  =============================================  */
/*  PROTECTED: ARK::API::MultiSignature::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/multisignatures/pending?publicKey=  */
    String pending(ARK::Utilities::Network::Connector _netConnector, Publickey _publicKey);
    String pendingfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
    /*  Only on Mainnet?  */
    // /*  /api/multisignatures/accounts?publicKey=  */
    // String accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey);
    // /*  ???  */
    // String accountsfromJSON(String _jsonStr);
/*  ==========================================================================  */
/*  ==========================================================================  */
};
/*  =============================================  */
/*  ==========================================================================  */
};
};
};




/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::MultiSignatureGettable::pending  */
/*  /api/multisignatures/pending?publicKey=  */
String ARK::API::MultiSignature::Gettable::pending(ARK::Utilities::Network::Connector _netConnector, Publickey _publicKey)
{
  String uri = ARK::API::Paths::MultiSignatures::pending_s;
  uri += "?publicKey=";
  uri += _publicKey.description();

  String callback = _netConnector.cb(uri);

  return ARK::API::MultiSignature::Gettable::pendingfromJSON(callback);
};

/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::MultiSignature::Gettable::pendingfromJSON(String _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);
  
  return jString.valueFor("transactions");
};
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
  /*  ==========================================  */
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
/*  ==========================================================================  */
/*  ==========================================================================  */

#endif
