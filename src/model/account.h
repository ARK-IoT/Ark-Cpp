

#ifndef account_h
#define account_h

namespace ARK {
  namespace Model {
  
    struct Account {
      public:
        String username;
        String address;
        String publicKey;
        String vote;
        long int producedblocks;
        long int missedblocks;
        long int rate;
        double approval;
        double productivity;
    };

  };
};

#endif
