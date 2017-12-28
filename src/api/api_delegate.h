
#ifndef api_delegate_h
#define api_delegate_h
    
namespace ARK {
  namespace API {
    namespace Delegate {


      namespace delegates_cb {
        
        struct countResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int count;
        };
        
        struct searchResult : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Delegate delegates[];
        };
        
        struct searchResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Delegate delegates[];
        };
        
        struct getVotersResponse : virtual ARK::API::Helpers::Successable {
          public:
            bool accounts;
        };
        
        struct getDelegateResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Delegate delegate;
        };
        
        struct getDelegatesResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Model::Delegate delegates[];
        };
        
        struct addDelegateResponse : virtual ARK::API::Helpers::Successable {};
        
        struct getFeeResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double fee;
        };
        
        struct getForgedByAccountResponse : virtual ARK::API::Helpers::Successable {
          public:
            long double fees;
            long int rewards;
            long int forged;
        };
        
        struct getNextForgersResponse : virtual ARK::API::Helpers::Successable {
          public:
            long int currentBlock;
            int currentSlot;
            ARK::Model::Delegate delegates[];
        };
        
        struct enableForgingResponse : virtual ARK::API::Helpers::Successable {};
        
        struct disableForgingResponse : virtual ARK::API::Helpers::Successable {};
        
      };      
      
      
    };
  };
};

#endif
