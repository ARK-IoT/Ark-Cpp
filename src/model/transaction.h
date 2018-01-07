

#ifndef transaction_h
#define transaction_h

namespace ARK {
    
  struct Transaction {

    public:
      String id;
      long int blockid;
      int type;
      long int timestamp;
      long double amount;
      long double fee;
      String senderId;
      String recipientId;
      String senderPublicKey;
      String signature;
      String asset;
      long int confirmations;
  };

};

#endif
 