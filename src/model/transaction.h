

#ifndef transaction_h
#define transaction_h

namespace ARK
{

static const auto TRANSACTION_MAX_SIZE = 600;
    

	/*************************************************
	*   ARK::transaction_t
	**************************************************/
  struct transaction_t
	{
    public:
      Hash id;
      char blockid[32];
      char height[32];
      int type;
      char timestamp[32];
      Balance amount;
      Balance fee;
      char vendorField[64];
      Address senderId;
      Address recipientId;
      Publickey senderPublicKey;
      Signature signature;
      char confirmations[64];
  };
  /*************************************************/

/**************************************************************************************************/

	/*************************************************
	*   ARK::Transaction
	**************************************************/
  struct Transaction :
			public transaction_t
	{
		Transaction(){};

		Transaction(
				const char* const newID,
				const char* const newBlockID,
				const char* const newHeight,
				int newType,
				const char* const newTimestamp,
				const char* const newAmount,
				const char* const newFee,
				const char* const newVendorField,
				const char* const newSenderID,
				const char* const newRecipientID,
				const char* const newSenderPublickey,
				const char* const newSignature,
				const char* const newConfirmations
		)
		{
			id = Hash(newID);
			strncpy(blockid, newBlockID, sizeof(blockid) / sizeof(blockid[0]));
			strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
			type = newType;
			strncpy(timestamp, newTimestamp, sizeof(timestamp) / sizeof(timestamp[0]));
			amount = Balance(newAmount);
			fee = Balance(newFee);
			strncpy(vendorField, newVendorField, sizeof(vendorField) / sizeof(vendorField[0]));
			senderId = Address(newSenderID);
			recipientId = Address(newRecipientID);
			senderPublicKey = Publickey(newSenderPublickey);
			signature = Signature(newSignature);
			strncpy(confirmations, newConfirmations, sizeof(confirmations) / sizeof(confirmations[0]));
		}

		void printTo(HardwareSerial &serial);
  };
  /*************************************************/

};



/*************************************************
*	ARK::Transaction
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints Transaction Model information to Serial
*
**************************************************/
void ARK::Transaction::Transaction::printTo(HardwareSerial &serial)
{
	serial.print("\nid: ");
		serial.print(this->id.getValue());
	serial.print("\nblockid: ");
		serial.print(this->blockid);
	serial.print("\nheight: ");
		serial.print(this->height);
	serial.print("\ntype: ");
		serial.print(this->type);
	serial.print("\ntimestamp: ");
		serial.print(this->timestamp);
	serial.print("\namount: ");
		serial.print(this->amount.ark());
	serial.print("\nfee: ");
		serial.print(this->fee.ark());
	serial.print("\nvendorField: ");
		serial.print(this->vendorField);
	serial.print("\nsenderId: ");
		serial.print(this->senderId.getValue());
	serial.print("\nrecipientId: ");
		serial.print(this->recipientId.getValue());
	serial.print("\nsenderPublicKey: ");
		serial.print(this->senderPublicKey.getValue());
	serial.print("\nsignature: ");
		serial.print(this->signature.getValue());
	// serial.print("\nasset: ");
	// serial.print(this->asset);
	serial.print("\nconfirmations: ");
		serial.print(this->confirmations);
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif
 