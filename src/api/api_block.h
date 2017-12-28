

#ifndef api_block_h
#define api_block_h

namespace ARK {
  namespace API { 
    namespace Block {
    
    
      namespace block_cb {
        
        struct getBlockResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Block block;
        };
      
        struct getBlocksResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Block blocks[];
        };
      
        struct getEpochResponse : virtual ARK::API::Helpers::Successable {
          public:
            String epoch;
        };
      
        struct getHeightResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int height;
            long int id;
        };
      
        struct getNethashResponse : virtual ARK::API::Helpers::Successable {
          public:
            String nethash;
        };
      
        struct getFeeResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int fees;
        };
      
        struct getFeesResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double send;
            long double vote;
            long double secondsignature;
            long double delegate;
            long double multisignature;
        };
      
        struct getMilestoneResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int milestone;
        };
      
        struct getRewardResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double reward;
        };
      
        struct getSupplyResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int supply;
        };
      
        struct getStatusResponse : virtual ARK::API::Helpers::Successable {
          public:
            String epoch;
            long int height;
            long double fee;
            long int milestone;
            String nethash;
            long double reward;
            long int supply;
        };
      
      };
      
      
    };
  };
};

#endif
