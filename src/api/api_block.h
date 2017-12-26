

#ifndef api_block_h
#define api_block_h

#include "../model/block.h"

namespace ARK {
  namespace API { 
    namespace Block {
    
      namespace block_cb {
        
        struct getBlockResponse{
          public:
            bool success;
            ARK::Model::Block block;
        };
      
        struct getBlocksResponse{
          public:
            bool success;
            ARK::Model::Block blocks[];
        };
      
        struct getEpochResponse {
          public:
            bool success;
            String epoch;
        };
      
        struct getHeightResponse{
          public:
            bool success;
            long int height;
            long int id;
        };
      
        struct getNethashResponse{
          public:
            bool success;
            String nethash;
        };
      
        struct getFeeResponse {
          public:
            bool success;
            long int fees;
        };
      
        struct getFeesResponse{
          public:
            bool success;
            long double send;
            long double vote;
            long double secondsignature;
            long double delegate;
            long double multisignature;
        };
      
        struct getMilestoneResponse {
          public:
            bool success;
            long int milestone;
        };
      
        struct getRewardResponse{
          public:
            bool success;
            long double reward;
        };
      
        struct getSupplyResponse{
          public:
            bool success;
            long int supply;
        };
      
        struct getStatusResponse{
          public:
            bool success;
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
