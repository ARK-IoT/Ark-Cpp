

#ifndef signature_gettable_h
#define signature_gettable_h

namespace ARK {
  namespace API {

    /*  ======================================  */
    /*  PROTECTED: ARK::API::SignatureGettable  */
    class SignatureGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/signatures/fee  */
        Balance fee(ARK::Utilities::Network::Manager _netManager);
        Balance feefromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  ======================================  */
  };

};

/*  ==========================================================================  */

/*  ================================  */
/*  ARK::API::SignatureGettable::fee  */

/*  /api/signatures/fee  */
Balance ARK::API::SignatureGettable::fee(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Signatures::fee_s;
  String callback = _netManager.cb(uri);
  return ARK::API::SignatureGettable::feefromJSON(callback);
}

/*
{
  "success":true,
  "fee":500000000
}
*/
Balance ARK::API::SignatureGettable::feefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return jString.valueFor("fee"); 
}
/*  ================================  */


#endif