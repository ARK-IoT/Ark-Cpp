
namespace ARK {
  namespace Network {
    
    typedef struct {
      long pub; // base58 will have a prefix 'apub'
      long priv; // base58Priv will have a prefix 'apriv'
    } bip32_t;
    
    typedef struct {
      const char* messagePrefix;
      bip32_t bip32;
      long pubKeyHash; // Addresses will begin with 'A'
      long wif; // Network prefix for wif generation
    } network_t;


    network_t main {
      "\x18\Ark Signed Message:\n",
      {
        0x2bf4968, // base58 will have a prefix 'apub'
        0x2bf4530 // base58Priv will have a prefix 'apriv'
      },
      0x17, // Addresses will begin with 'A'
      0xaa // Network prefix for wif generation
    };

    network_t devnet {
      "\x18\Ark Devnet Signed message:\n",
      {
        0x43587CF, //<-hex dec: 70617039,
        0x4358394 //<-hex dec: 70615956
      },
      0x1E, //<-hex dec: 30,
      0xBB //<-hex dec: 187
    };

    network_t testnet {
      "\x18\Ark Testnet Signed Message:\n",
      {
          0x043587cf,
          0x04358394
      },
      0x52, // Addresses will begin with 'a'
      0xba // Network prefix for wif generation
    };
    
    network_t bitcoin {
      "\x18\Bitcoin Signed Message:\n",
      {
        0x0488b21e,
        0x0488ade4
      },
      0x00,
      0x80
    };

  };
};