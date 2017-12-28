

#ifndef api_transport_h
#define api_transport_h

namespace ARK {
  namespace API {
    namespace Transport {


      namespace transport_cb {

        struct statusResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int height;
            bool forgingAllowed;
            int currentSlot;
            ARK::Model::TransportPeerHeader header;
        };
        
        struct listBroadcastPeersResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Peer peers[];
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
            ARK::Model::TransportPeerHeader header;
        };

      };
      
      
    };
  };
};

#endif
