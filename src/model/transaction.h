

#ifndef transaction_h
#define transaction_h

namespace ARK {

#define TRANSACTION_MAX_SIZE 600
    
/*  ================================================  */
  /*  ================  */
  /*  ARK::Transaction  */
  struct Transaction {

    public:
      String id;
      String blockid;
      String height;
      int type;
      String timestamp;
      Balance amount;
      Balance fee;
      String vendorField;
      Address senderId;
      String recipientId;
      String senderPublicKey;
      String signature;
      String confirmations;

      // Transaction();
      // Transaction(String, String, String, int, String, Balance, Balance, String, Address, String, String, String, String);

      String description();
  };
  /*  ================  */
/*  ================================================  */

};



/*  ================================================  */
/*  ================  */
/*  ARK::Transaction  */

// /*  Constructor  */
// ARK::Transaction::Transaction() {
//   id = "";
//   blockid = "";
//   height = "";
//   type = 0;
//   timestamp = "";
//   amount = { "0" };
//   fee = { "0" };
//   vendorField = "";
//   senderId = { "" };
//   recipientId = "";
//   senderPublicKey ="";
//   signature = "";
//   confirmations = "";
// }

/*  =====  */

// /*  Constructor  */
// ARK::Transaction::Transaction(
//   String _id,
//   String _blockid,
//   String _height,
//   int _type,
//   String _timestamp,
//   Balance _amount,
//   Balance _fee,
//   String _vendorField,
//   Address _senderId,
//   String _recipientId,
//   String _senderPublicKey,
//   String _signature,
//   String _confirmations) :
//     id(_id),
//     blockid(_blockid),
//     height(_height),
//     type(_type),
//     timestamp(_timestamp),
//     amount( { _amount } ),
//     fee( { _fee } ),
//     vendorField(_vendorField),
//     senderId( { _senderId }),
//     recipientId(_recipientId),
//     senderPublicKey(_senderPublicKey),
//     signature(_signature),
//     confirmations(_confirmations) {}

/*  =====  */

/*  Description  */
String ARK::Transaction::Transaction::description() {
  String resp;
    resp += "id: ";
      resp += this->id; resp += "\n";
    resp += "blockid: ";
      resp += this->blockid; resp += "\n";
    resp += "height: ";
      resp += this->height; resp += "\n";
    resp += "type: ";
      resp += this->type; resp += "\n";
    resp += "timestamp: ";
      resp += this->timestamp; resp += "\n";
    resp += "amount.ark: ";
      resp += this->amount.ark; resp += "\n";
    resp += "fee.ark: ";
      resp += this->fee.ark; resp += "\n";
    resp += "vendorField: ";
      resp += this->vendorField; resp += "\n";      
    resp += "senderId.description: ";
      resp += this->senderId.description(); resp += "\n";
    resp += "recipientId: ";
      resp += this->recipientId; resp += "\n";
    resp += "senderPublicKey: ";
      resp += this->senderPublicKey; resp += "\n";
    resp += "signature: ";
      resp += this->signature; resp += "\n";
    // resp += "asset: ";
    //   resp += this->asset; resp += "\n";
    resp += "confirmations: ";
      resp += this->confirmations;
  return resp;
}
/*  ================  */
/*  ================================================  */

#endif
 