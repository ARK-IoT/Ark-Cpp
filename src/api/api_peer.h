

#ifndef api_peer_h
#define api_peer_h
    
namespace ARK {
  namespace API {
    namespace Peer {


      namespace peer_cb {
    
        struct getPeerResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Peer peer;
        };
        
        struct getPeersResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Peer peers[];
        };
        
        struct versionResponse : virtual ARK::API::Helpers::Successable {
          public:
            String version;
            String build;
        };    

      };
      
        
    };
  };
};

#endif
