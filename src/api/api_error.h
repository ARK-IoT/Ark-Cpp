

#ifndef api_error_h
#define api_error_h

namespace ARK {
  namespace API {

    struct Error : virtual ARK::API::Helpers::Successable {
      public:
        bool success;
        String error;
    };
    
  };
};

#endif
