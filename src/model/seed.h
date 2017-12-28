

#ifndef seed_h
#define seed_h

namespace ARK {
  namespace Model {


    struct Seed {
      public:
        const char* nethash;
        byte peers;
        int port;
    };


  };
};

#endif
