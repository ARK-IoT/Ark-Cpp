

#ifndef transaction_h
#define transaction_h

namespace ARK {

#define TRANSACTION_MAX_SIZE 600
    
/*  ==========================================================================  */
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
      Address recipientId;
      Publickey senderPublicKey;
      String signature;
      String confirmations;

      String description();
  };
  /*  ================  */
/*  ==========================================================================  */

};



/*  ==========================================================================  */
/*  ================  */
/*  ARK::Transaction  */
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
    resp += "recipientId.description: ";
      resp += this->recipientId.description(); resp += "\n";
    resp += "senderPublicKey.description: ";
      resp += this->senderPublicKey.description(); resp += "\n";
    resp += "signature: ";
      resp += this->signature; resp += "\n";
    // resp += "asset: ";
    //   resp += this->asset; resp += "\n";
    resp += "confirmations: ";
      resp += this->confirmations;
  return resp;
}
/*  ================  */
/*  ==========================================================================  */

#endif
 