

#ifndef multisignaturable_h
#define multisignaturable_h

namespace ARK {
  namespace API {



    class MultiSignatureGettable {
      protected:

        /*  /api/multisignatures/pending?publicKey=  */
        String pending(ARK::Utilities::Network::Manager _netManager, String _publicKey);
        String pendingfromJSON(String _jsonStr);


    /*  Only on Mainnet?  */
        // /*  /api/multisignatures/accounts?publicKey=  */
        // String accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey);
        // /*  ???  */
        // String accountsfromJSON(String _jsonStr);


    };


    class MultiSignaturable : public MultiSignatureGettable, virtual ARK::Utilities::Network::Managable {
      public: 

        /*  /api/multisignatures/pending?publicKey=  */
        String multisignaturesPending(String _publicKey)
        { return ARK::API::MultiSignatureGettable::pending(this->netManager, _publicKey); };


    // /*  Only on Mainnet?  */
    //     /*  /api/multisignatures/accounts?publicKey=  */
    //     String multisignaturesAccounts(String _publicKey)
    //     { return ARK::API::MultiSignatureGettable::accounts(this->netManager, _publicKey); };


    };


    namespace multisignature_cb {
      struct signResponse : virtual ARK::API::Helpers::Successable {};
      struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
    };

  };
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

/*  /api/multisignatures/pending?publicKey=  */
String ARK::API::MultiSignatureGettable::pending(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
  String uri = ARK::API::Endpoints::MultiSignatures::pending_s;
    uri += "?publicKey=";
    uri += _publicKey;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::MultiSignatureGettable::pendingfromJSON(callback);
};


/*  Only on Mainnet?  */
// String ARK::API::MultiSignatureGettable::accountsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   return jString.valueFor("??");
// };
// /*  /api/multisignatures/accounts?publicKey=  */
// String ARK::API::MultiSignatureGettable::accounts(ARK::Utilities::Network::Manager _netManager, String _publicKey) {
//   String uri = ARK::API::Endpoints::MultiSignatures::accounts_s;
//     uri += "?publicKey=";
//     uri += _publicKey;
//   String callback = _netManager.cb(uri);
//   if (callback.indexOf("false") > 0) { return callback; }
//   return ARK::API::MultiSignatureGettable::accountsfromJSON(callback);
// };


#endif
