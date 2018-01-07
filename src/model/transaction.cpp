

#include "transaction.h"

ARK::Transaction() {
  id("");
  blockid(0);
  type(0);
  timestamp(0);
  amount(0.0);
  fee(0.0);
  senderId("");
  recipientId("");
  senderPublicKey("");
  signature("");
  asset("");
  confirmations(0);
}

ARK::Transaction() :
  id(_id)
  blockid(_blockid)
  type(_type)
  timestamp(_timestamp)
  amount(_amount)
  fee(_fee)
  senderId(_senderId)
  recipientId(_recipientId)
  senderPublicKey(_senderPublicKey)
  signature(_signature)
  asset(_asset)
  confirmations(_confirmations) {}


// Transaction(  String _id,
//               long int _blockid,
//               int _type,
//               long int _timestamp,
//               long double _amount,
//               long double _fee,
//               String _senderId,
//               String _recipientId,
//               String _senderPublicKey,
//               String _signature,
//               String _asset,
//               long int _confirmations ) {
//   this->id = _id;
//   this->blockid = _blockid;
//   this->type = _type;
//   this->timestamp = _timestamp;
//   this->amount = _amount;
//   this->fee = _fee;
//   this->senderId = _senderId;
//   this->recipientId = _recipientId;
//   this->senderPublicKey = _senderPublicKey;
//   this->signature = _signature;
//   this->asset = _asset;
//   this->confirmations = _confirmations;
// };

