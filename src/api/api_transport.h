

#ifndef api_transport_h
#define api_transport_h

#include "../model/transport.h"

namespace ARK {
  namespace API {
    namespace Transport {

      namespace transport_cb {

        struct TransportStatusResponse {
          public:
            bool success;  
            long int height;
            bool forgingAllowed;
            int currentSlot;
            ARK::Model::TransportPeerHeader header;
        };
        
        struct TransportListBroadcastPeersResponse {
          public:
            bool success;
            ARK::Model::Peer peers[];
        };
        
        struct TransportCommonBlockResponse{
          public:
            bool success;
        };
        
        struct TransportGetBlockResponse{
          public:
            bool success;
        };
        
        struct TransportGetBlocksResponse{
          public:
            bool success;
        };
        
        struct TransportGetTransactionsResponse{
          public:
            bool success;
        };
        
        struct TransportAddTransactionsResponse{
          public:
            bool success;
        };
        
        struct TransportTransactionsFromIdsResponse {
          public:
            bool success;
        };
        
        struct TransportHeightResponse{
          public:
            bool success; 
            long int height;
            ARK::Model::TransportPeerHeader header;
        };

      };
      
    };
  };
};

#endif
