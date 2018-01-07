

#ifndef api_loader_h
#define api_loader_h

namespace ARK {
  namespace API {
    namespace Loader {


      namespace loader_cb {

        struct statusResponse : virtual ARK::API::Helpers::Successable {
          public:
            bool loaded;
            long int now;
            long int blocksCount;
        };
        
        struct syncResponse : virtual ARK::API::Helpers::Successable {
          public:
            bool syncing;
            long int blocks;
            long int height;
            long int id;
        };

        struct autoconfigureResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Network network;
        };

      };
      

    };
  };
};

#endif
