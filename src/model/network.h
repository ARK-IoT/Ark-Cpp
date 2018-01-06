

#ifndef network_h
#define network_h

namespace ARK {
  namespace Model {
    
    enum NetworkType { DEV, MAIN, CUSTOM };

    struct Network {
      public:
        const char* nethash;
        String token;
        String symbol;
        String explorer;
        String version;

        bool operator==(Network*& rhs) const {
          if (this->nethash==rhs->nethash
              && this->token==rhs->token
              && this->symbol==rhs->symbol
              && this->explorer==rhs->explorer
              && this->version==rhs->version)
            return true;
          return false;
        };
        bool operator!=(Network*& rhs) const { return !(this == rhs); };
    };

    namespace Network_ADV {
      
	    struct bip32_t {
		    long pub;         // base58 will have a prefix 'apub'
		    long priv;        // base58Priv will have a prefix 'apriv'
	    };
      struct network_t {
        const char* messagePrefix;
        bip32_t bip32;
        long pubKeyHash;  // Addresses will begin with 'A'
        long wif;         // Network prefix for wif generation
      };

    };


  };
};


#endif
