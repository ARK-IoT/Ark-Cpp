

#ifndef voter_h
#define voter_h

namespace ARK {
  namespace Model {
    
    struct Voter {
      public:
        String username;
        String address;
        String publicKey;
        long double balance;
    };

  };
};

#endif
