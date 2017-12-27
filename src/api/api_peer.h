

#ifndef api_peer_h
#define api_peer_h
    
#include "../model/peer.h"

namespace ARK {
  namespace API {
    namespace Peer {

      namespace peer_cb {
    
        struct getPeerResponse {
          public:
            bool success;
            ARK::Model::Peer peer;
        };
        
        struct getPeersResponse {
          public:
            bool success;
            ARK::Model::Peer peers[];
        };
        
        struct versionResponse {
          public:
            bool success;
            String version;
            String build;
        };    

      };
        
    };
  };
};

#endif
