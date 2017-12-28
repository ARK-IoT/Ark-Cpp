

#ifndef peer_h
#define peer_h

namespace ARK {
  namespace Model {
    
    struct Peer {
      public:
        String ip;
        int port;
        String version;
        int errors;
        String os;
        String height;
        String status;
        double delay;

        Peer();
    };

    struct Seed {
      const char* nethash;
      byte peers;
      int port;

      Seed();
    };

  };
};

#endif
