

#ifndef network_h
#define network_h

namespace ARK {
  namespace Model {
    
    struct Network {
      public:
        String nethash;
        String token;
        String symbol;
        String explorer;
        String version;
        // Network();
    };

  };
};

#endif


/*
    bool operator==(ARK::Model::Network& a, const ARK::Model::Network& b) {
      if (
          !a.nethash || !b.nethash
          || !a.token || !b.token
          || !a.symbol || !b.symbol
          || !a.explorer || !b.explorer
          || !a.version || !b.version
          
          || !a.nethash != !b.nethash
          || !a.token != !b.token
          || !a.symbol != !b.symbol
          || !a.explorer != !b.explorer
          || !a.version != !b.version
        ) { return false; }
      return true;
    };

    bool operator!=(ARK::Model::Network& a, const ARK::Model::Network& b) { return !(a == b); };

    bool isValid(Network& a) {
      if (a.nethash != ARK::Constants::Peers::Devnet().nethash || a.nethash != ARK::Constants::Peers::Mainnet::nethash) {
        return false;
      }
      return true;
    };
*/

/*
namespace Network_ADV {
	struct bip32_t {
		long pub; // base58 will have a prefix 'apub'
		long priv; // base58Priv will have a prefix 'apriv'
	};
	struct network_t {
		const char* messagePrefix;
		bip32_t bip32;
		long pubKeyHash; // Addresses will begin with 'A'
		long wif; // Network prefix for wif generation
	};
};
*/
