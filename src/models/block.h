

#ifndef block_h
#define block_h

namespace ARK {
  namespace Model {
  
    struct Block {
      public:
        long int id;
        double version;
        long int timestamp;
        long int heigh;
        long int previousBlock;
        long int numberOfTransactions;
        long double totalAmount;
        long double totalFee;
        long int reward;
        long intpayloadLength;
        String payloadHash;
        String generatorPublicKey;
        String generatorId;
        String blockSignature;
        long int confirmations;
        long int totalForged;
    };

  };
};

#endif
