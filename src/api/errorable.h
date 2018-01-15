

#ifndef errorable_h
#define errorable_h

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
