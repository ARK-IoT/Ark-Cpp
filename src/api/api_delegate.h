
#ifndef api_delegate_h
#define api_delegate_h

#include "../models/delegate.h"
    
namespace api_n {
  namespace delegate_n {

    namespace delegates_cb {
      
      struct countResponse {
        public:
          bool success;
          long int count;
      };
      
      struct DelegateSearchResult{
        public:
          String username;
          String address;
          String publicKey;
          long int vote;
          long int producedblocks;
          long int missedblocks;
      };
      
      struct searchResponse {
        public:
          bool success;
          DelegateSearchResult delegates[];
      };
      
      struct getVotersResponse{
        public:
          bool success;
          bool accounts;
      };
      
    };
    
    
  };
};

#endif
