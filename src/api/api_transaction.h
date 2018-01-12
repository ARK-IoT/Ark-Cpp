

#ifndef api_transaction_h
#define api_transaction_h

namespace ARK {
  namespace API {
    namespace Transaction {
        


        // const String getSingle_s = "/api/transactions/get";
        // const String transactions_s = "/api/transactions";
        // const String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get";
        // const String unconfirmed_s = "/api/transactions/unconfirmed";

             // jString.valueFor("")
      //  ARK::Utilities::JSONString jString(_jsonStr);

      //     ARK::Delegate delegate = {
      //       jString.valueFor("username"),
      //       jString.valueFor("address"),
      //       jString.valueFor("publicKey"),
      //       jString.valueFor("vote"),
      //       jString.valueFor("producedblocks").toInt(),
      //       jString.valueFor("missedblocks").toInt(),
      //       jString.valueFor("rate").toInt(),
      //       jString.valueFor("approval").toFloat(),
      //       jString.valueFor("productivity").toFloat()
      //     };

      //     return delegate.description();
      // return jString.valueFor("publicKey");

      namespace Get {


// http://167.114.29.55:4002/api/transactions/get?id=4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e


        // /*  {"success":true,"fee":500000000}  */
        // String feefromJSON(String _jsonStr) {
        //   ARK::Utilities::JSONString jString(_jsonStr);
        //   return jString.valueFor("fee");
        // };
        // /*  /api/signatures/fee  */
        // String fee(ARK::Utilities::Network::Manager _netManager) {
        //   String uri = ARK::API::Endpoints::Signatures::fee_s;
        //   String callback = _netManager.cb(uri);
        //   if (callback.indexOf("false") >= 0)
        //     return callback;
        //   return ARK::API::Signatures::Get::feefromJSON(callback);
        // };





      };

        
      namespace transaction_cb {
        
        struct getTransactionResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Transaction transaction;
        };
          
        struct getTransactionsResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Transaction transactions[];
        };
        
        struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getUnconfirmedTransactionResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getUnconfirmedTransactionsResponse : virtual ARK::API::Helpers::Successable {};
          
      };


    };
  };
};

#endif
