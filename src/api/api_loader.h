

#ifndef api_loader_h
#define api_loader_h

namespace ARK {
  namespace API {
    namespace Loader {

      namespace loader_cb {

        struct statusResponse {
          public:
            bool success;
            bool loaded;
            long int now;
            long int blocksCount;
        };
        
        struct syncResponse {
          public:
            bool success;
            bool syncing;
            long int blocks;
            long int height;
            long int id;
        };

        struct autoconfigureResponse {
          public:
            bool success;
            ARK::Model::Network network;
        };

      };
      
    };
  };
};

#endif


// Network{
// nethash	string
// token	string
// symbol	string
// explorer	string
// version	integer
// }