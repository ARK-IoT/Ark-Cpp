

#ifndef delegate_h
#define delegate_h

namespace ARK {
  namespace Model {
    
    struct Delegate {
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

        // Delegate();
    };

  };
};

#endif
