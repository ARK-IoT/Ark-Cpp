
#ifndef api_delegate_h
#define api_delegate_h

#include "../model/delegate.h"
    
namespace ARK {
  namespace API {
    namespace Delegate {

      namespace delegates_cb {
        
        struct countResponse {
          public:
            bool success;
            long int count;
        };
        
        struct searchResult {
          public:
            bool success;
            ARK::Model::Delegate delegates[];
        };
        
        struct searchResponse {
          public:
            bool success;
            ARK::Model::Delegate delegates[];
        };
        
        struct getVotersResponse{
          public:
            bool success;
            bool accounts;
        };
        
        struct getDelegateResponse {
          public:
            bool success;
            ARK::Model::Delegate delegate;
        };
        
        struct getDelegatesResponse {
          public:
            bool success;
            ARK::Model::Delegate delegates[];
        };
        
        struct addDelegateResponse {
          public:
            bool success;
        };
        
        struct getFeeResponse {
          public:
            bool success;
            long double fee;
        };
        
        struct getForgedByAccountResponse {
          public:
            bool success;
            long double fees;
            long int rewards;
            long int forged;
        };
        
        struct getNextForgersResponse {
          public:
            bool success;
            long int currentBlock;
            int currentSlot;
            ARK::Model::Delegate delegates[];
        };
        
        struct enableForgingResponse {
          public:
            bool success;
        };
        

        struct disableForgingResponse {
          public:
            bool success;
        };
        
      };      
      
    };
  };
};

#endif
