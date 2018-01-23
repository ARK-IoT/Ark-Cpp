

#ifndef multisignature_gettable_h
#define multisignature_gettable_h

namespace ARK {
  namespace API {

    /*  ===========================================  */
    /*  PROTECTED: ARK::API::MultiSignatureGettable  */
    class MultiSignatureGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/multisignatures/pending?publicKey=  */
        String pending(ARK::Utilities::Network::Manager _netManager, Hash _publicKey);
        String pendingfromJSON(String _jsonStr);

/*  ==========================================================================  */
    /*  Only on Mainnet?  */
        // /*  /api/multisignatures/accounts?publicKey=  */
        // String accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey);
        // /*  ???  */
        // String accountsfromJSON(String _jsonStr);
/*  ==========================================================================  */

    };
    /*  ===========================================  */

  };
};

/*  ==========================================================================  */

/*  =========================================  */
/*  ARK::API::MultiSignatureGettable::pending  */

/*  /api/multisignatures/pending?publicKey=  */
String ARK::API::MultiSignatureGettable::pending(ARK::Utilities::Network::Manager _netManager, Hash _publicKey) {
  String uri = ARK::API::Endpoints::MultiSignatures::pending_s;
    uri += "?publicKey=";
    uri += _publicKey.description();
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::MultiSignatureGettable::pendingfromJSON(callback);
};

/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::MultiSignatureGettable::pendingfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("transactions");
};
/*  =========================================  */

/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================  */
/*  ARK::API::MultiSignatureGettable::accounts  */
// /*  /api/multisignatures/accounts?publicKey=  */
// String ARK::API::MultiSignatureGettable::accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
//   String uri = ARK::API::Endpoints::MultiSignatures::accounts_s;
//     uri += "?publicKey=";
//     uri += _publicKey;
//   String callback = _netManager.cb(uri);
//   return ARK::API::MultiSignatureGettable::accountsfromJSON(callback);
// };

/*  Only on Mainnet?  */
// String ARK::API::MultiSignatureGettable::accountsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   return jString.valueFor("??");
// };
/*  ==========================================  */
/*  ==========================================================================  */


#endif
