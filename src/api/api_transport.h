

#ifndef api_transport_h
#define api_transport_h

namespace ARK {
  namespace API {
    namespace Transport {


        // const String list_s = "/peer/list";
        // const String common_s = "/peer/blocks/common";
        // const String block_s = "/peer/block";
        // const String blocks_s = "/peer/blocks";
        // const String transactions_s = "/peer/transactions";
        // const String transactionsPost_s = "/peer/transactions"; // post
        // const String transactionsFromIds_s = "/peer/transactionsFromIds";
        // const String height_s = "/peer/height";
        // const String status_s = "/peer/status";

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

      namespace transport_cb {

        struct statusResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int height;
            bool forgingAllowed;
            int currentSlot;
            ARK::TransportPeerHeader header;
        };
        
        struct listBroadcastPeersResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Peer peers[];
        };
        
        struct commonBlockResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getBlockResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getBlocksResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getTransactionsResponse : virtual ARK::API::Helpers::Successable {};
        
        struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
        
        struct transactionsFromIdsResponse : virtual ARK::API::Helpers::Successable {};
        
        struct heightResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int height;
            ARK::TransportPeerHeader header;
        };

      };
      
      
    };
  };
};

#endif
