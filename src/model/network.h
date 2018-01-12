

#ifndef network_h
#define network_h

namespace ARK {
    
  enum NetworkType { DEV, MAIN, CUSTOM };

  struct Network {
    public:
      String nethash;
      String token;
      String symbol;
      String explorer;
      int version;

      Network() {
        this->nethash = "";
        this->token = "";
        this->symbol = "";
        this->explorer = "";
        this->version = 0;
      };

      Network(String _nethash, String _token, String _symbol, String _explorer, int _version) {
        this->nethash = _nethash;
        this->token = _token;
        this->symbol = _symbol;
        this->explorer = _explorer;
        this->version = _version;
      };

      String description() {
        String resp;
          resp += "nethash: ";
            resp += this->nethash; resp += "\n";           
          resp += "token: ";
            resp += this->token; resp += "\n";
          resp += "symbol: ";
            resp += this->symbol; resp += "\n";
          resp += "explorer: ";
            resp += this->explorer; resp += "\n";
          resp += "version: ";
            resp += this->version; resp += "\n";
        return resp;
      };

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

#endif
