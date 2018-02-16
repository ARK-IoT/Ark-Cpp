

#ifndef transaction_h
#define transaction_h

namespace ARK
{

static const auto TRANSACTION_MAX_SIZE = 600;
    
	/*************************************************
	*   ARK::Transaction
	**************************************************/
  struct Transaction
	{
    public:
    	const char* id;
      const char* blockid;
      const char* height;
      int type;
      const char* timestamp;
      Balance amount;
      Balance fee;
      const char* vendorField;
      Address senderId;
      Address recipientId;
      Publickey senderPublicKey;
      const char* signature;
      const char* confirmations;

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
	serial.print(this->id);
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
	serial.print(this->senderId.value);
	serial.print("\nrecipientId: ");
	serial.print(this->recipientId.value);
	serial.print("\nsenderPublicKey: ");
	serial.print(this->senderPublicKey.value);
	serial.print("\nsignature: ");
	serial.print(this->signature);
	// serial.print("\nasset: ");
	// serial.print(this->asset);
	serial.print("\nconfirmations: ");
	serial.print(this->confirmations);
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif
 