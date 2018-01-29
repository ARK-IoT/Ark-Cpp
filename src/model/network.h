

#ifndef network_h
#define network_h

namespace ARK {

/*  ================================================  */
/*  ARK::NetworkType  */
  enum NetworkType { DEV, MAIN, CUSTOM };
/*  ================================================  */

/********************************************************************************
*
* Network: 
*  	578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
*		DARK
*		DѦ
*		https://dexplorer.ark.io/
*		30
*
********************************************************************************/

/*  ================================================  */
  /*  ============  */
  /*  ARK::Network  */
  struct Network {
    public:
      String nethash;
      String token;
      String symbol;
      String explorer;
      int version;

      String description();

      bool operator==(Network*& rhs) const;
      bool operator!=(Network*& rhs) const;
  };
  /*  ============  */
  /*  ================================================  */
  /*  ================  */
  /*  ARK::Network_ADV  */
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
/*  ================  */

};

/*  ================================================  */
/*  ============  */
/*  ARK::Delegate  */
/*  Description  */
String ARK::Network::Network::description() {
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
      resp += this->version;
  return resp;
};
/*  =====  */
/*  Operator  */
/*  ARK::Network == ARK::Network  */
bool ARK::Network::Network::operator==(Network*& rhs) const {
  if (this->nethash==rhs->nethash
      && this->token==rhs->token
      && this->symbol==rhs->symbol
      && this->explorer==rhs->explorer
      && this->version==rhs->version)
    return true;
  return false;
};
/*  =====  */
/*  Operator  */
/*  ARK::Network != ARK::Network  */
bool ARK::Network::Network::operator!=(Network*& rhs) const { return !(this == rhs); };
/*  ============  */
/*  ================================================  */


#endif
