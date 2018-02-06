

#ifndef transaction_h
#define transaction_h

namespace ARK {

static const auto TRANSACTION_MAX_SIZE = 600;
    
/*  ==========================================================================  */
  /*  ================  */
  /*  ARK::Transaction  */
  struct Transaction {

    public:
      char id[64];  //TODO: review array sizes
      char blockid[64];
      char height[64];
      int type;
      char timestamp[64];
      Balance amount;
      Balance fee;
      char vendorField[64];
      Address senderId;
      Address recipientId;
      Publickey senderPublicKey;
      char signature[64];
      char confirmations[64];

      void description(char* const buf, size_t size);
  };
  /*  ================  */
/*  ==========================================================================  */

};



/*  ==========================================================================  */
/*  ================  */
/*  ARK::Transaction  */
/*  Description  */
void ARK::Transaction::Transaction::description(char* const buf, size_t size) {
    strcpy(buf, "id: ");
    strcat(buf, this->id);
    strcat(buf, "\nblockid: ");
    strcat(buf, this->blockid);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\ntype: ");
    sprintf(buf, "%d", this->type);
    strcat(buf, "\ntimestamp: ");
    strcat(buf, this->timestamp);
    strcat(buf, "\namount.ark: ");
    strcat(buf, this->amount.ark());
    strcat(buf, "\nfee.ark: ");
    strcat(buf, this->fee.ark());
    strcat(buf, "\nvendorField: ");
    strcat(buf, this->vendorField);
    strcat(buf, "\nsenderId.description: ");
    strcat(buf, this->senderId.description());
    strcat(buf, "\nrecipientId.description: ");
    strcat(buf, this->recipientId.description());
    strcat(buf, "\nsenderPublicKey.description: ");
    strcat(buf, this->senderPublicKey.description());
    strcat(buf, "\nsignature: ");
    strcat(buf, this->signature);
    //strcat(buf, "\nasset: ");
    //strcat(buf, this->asset);
    strcat(buf, "\nconfirmations: ");
    strcat(buf, this->confirmations);
}
/*  ================  */
/*  ==========================================================================  */

#endif
 