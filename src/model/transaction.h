

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

      Transaction();
      Transaction(String, long int, int, long int, long double, long double, String, String, String, String, String, long int);

  };

};


ARK::Transaction::Transaction() {
  id = "";
  blockid = 0;
  type = 0;
  timestamp = 0;
  amount = 0.0;
  fee = 0.0;
  senderId = "";
  recipientId = "";
  senderPublicKey ="";
  signature = "";
  asset = "";
  confirmations = 0;
}

ARK::Transaction::Transaction(
  String _id,
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
  long int _confirmations) :
    id(_id),
    blockid(_blockid),
    type(_type),
    timestamp(_timestamp),
    amount(_amount),
    fee(_fee),
    senderId(_senderId),
    recipientId(_recipientId),
    senderPublicKey(_senderPublicKey),
    signature(_signature),
    asset(_asset),
    confirmations(_confirmations) {}


#endif
 