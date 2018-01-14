

#ifndef api_multisignatures_h
#define api_multisignatures_h

namespace ARK {
  namespace API {
    namespace MultiSignatures {


      namespace Get {

        /*  /api/multisignatures/pending?publicKey=  */
        String pending(ARK::Utilities::Network::Manager _netManager, String _publicKey);
        String pendingfromJSON(String _jsonStr);

    /*  Only on Mainnet?  */
        // /*  /api/multisignatures/accounts?publicKey=  */
        // String accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey);
        // /*  ???  */
        // String accountsfromJSON(String _jsonStr);
        
      };

      namespace multisignature_cb {
        struct signResponse : virtual ARK::API::Helpers::Successable {};
        struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
      };


    };
  };
};


/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::MultiSignatures::Get::pendingfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("transactions");
};

/*  /api/multisignatures/pending?publicKey=  */
String ARK::API::MultiSignatures::Get::pending(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
  String uri = ARK::API::Endpoints::MultiSignatures::pending_s;
    uri += "?publicKey=";
    uri += _publicKey;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::MultiSignatures::Get::pendingfromJSON(callback);
};


/*  Only on Mainnet?  */
// String ARK::API::MultiSignatures::Get::accountsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   return jString.valueFor("??");
// };
// /*  /api/multisignatures/accounts?publicKey=  */
// String ARK::API::MultiSignatures::Get::accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
//   String uri = ARK::API::Endpoints::MultiSignatures::accounts_s;
//     uri += "?publicKey=";
//     uri += _publicKey;
//   String callback = _netManager.cb(uri);
//   if (callback.indexOf("true") <= 0)
//     return callback;
//   return ARK::API::MultiSignatures::Get::accountsfromJSON(callback);
// };

#endif
