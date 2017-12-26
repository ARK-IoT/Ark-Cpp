

#ifndef transport_h
#define transport_h

namespace ARK {
  namespace Model {
    
    struct TransportPeerHeader {
      public:
        long int id;
        long int height;
        long double version;
        long double totalAmount;
        long double totalFee;
        long double reward;
        String payloadHash;
        int payloadLength;
        long int timestamp;
        long int numberOfTransactions;
        long int previousBlock;
        String generatorPublicKey;
        String blockSignature;
    }; 

  };
};

#endif
