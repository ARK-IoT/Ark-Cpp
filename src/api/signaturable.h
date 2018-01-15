

#ifndef signaturable_h
#define signaturable_h

namespace ARK {
  namespace API {


    class SignatureGettable {
      protected:

        /*  /api/signatures/fee  */
        String fee(ARK::Utilities::Network::Manager _netManager);
        String feefromJSON(String _jsonStr);

    };


    class Signaturable : public SignatureGettable, virtual ARK::Utilities::Network::Managable {
      public: 

        /*  /api/signatures/fee  */
        String signaturesFee()
        { return ARK::API::SignatureGettable::fee(this->netManager); };

    };


    // namespace signature_cb {
    //   struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};
    // };


  };
};




/*
{
  "success":true,
  "fee":500000000
}
*/
String ARK::API::SignatureGettable::feefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("fee"); 
}

/*  /api/signatures/fee  */
String ARK::API::SignatureGettable::fee(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Signatures::fee_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  return ARK::API::SignatureGettable::feefromJSON(callback);
};


#endif
