

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

      Transaction(
          const char* const i,
          const char* const b,
          const char* const h,
          int t,
          const char* const ts,
          const char* const a,
          const char* const f,
          const char* const vf,
          const char* const si,
          const char* const ri,
          const char* const spk,
          const char* const s,
          const char* const c
      ) :
          id(),
          blockid(),
          height(),
          type(t),
          timestamp(),
          amount(a),
          fee(f),
          vendorField(),
          senderId(si),
          recipientId(ri),
          senderPublicKey(spk),
          signature(),
          confirmations()
      {
          strncpy(id, i, sizeof(id) / sizeof(id[0]));
          strncpy(blockid, b, sizeof(blockid) / sizeof(blockid[0]));
          strncpy(height, h, sizeof(height) / sizeof(height[0]));
          strncpy(timestamp, ts, sizeof(timestamp) / sizeof(timestamp[0]));
          strncpy(vendorField, vf, sizeof(vendorField) / sizeof(vendorField[0]));
          strncpy(signature, s, sizeof(signature) / sizeof(signature[0]));
          strncpy(confirmations, c, sizeof(confirmations) / sizeof(confirmations[0]));
      }

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
 