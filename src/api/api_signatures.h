

#ifndef api_signatures_h
#define api_signatures_h

namespace ARK {
  namespace API {
    namespace Signatures {

      namespace Get {

        /*  {"success":true,"fee":500000000}  */
        String feefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          return jString.valueFor("fee");
        };
        /*  /api/signatures/fee  */
        String fee(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Signatures::fee_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Signatures::Get::feefromJSON(callback);
        };

      };


      namespace signature_cb {

        struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};

      };
      
      
    };
  };
};

#endif
