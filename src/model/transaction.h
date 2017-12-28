

#ifndef transaction_h
#define transaction_h

namespace ARK {
  namespace Model {
    
    struct asset_t {};
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
        asset_t asset;
        long int confirmations;

        Transaction();
    };

  };
};

#endif
 