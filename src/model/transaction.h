

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
        String asset;
        long int confirmations;

        Transaction(  String _id,
                      long int _blockid,
                      int _type,
                      long int _timestamp,
                      long double _amount,
                      long double _fee,
                      String _senderId,
                      String _recipientId,
                      String _senderPublicKey,
                      String _signature,
                      String _asset,
                      long int _confirmations ) {
          this->id = _id;
          this->blockid = _blockid;
          this->type = _type;
          this->timestamp = _timestamp;
          this->amount = _amount;
          this->fee = _fee;
          this->senderId = _senderId;
          this->recipientId = _recipientId;
          this->senderPublicKey = _senderPublicKey;
          this->signature = _signature;
          this->asset = _asset;
          this->confirmations = _confirmations;
        };
    };

  };
};

#endif
 