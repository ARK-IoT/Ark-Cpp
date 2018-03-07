

#ifndef transaction_h
#define transaction_h

static const auto TRANSACTION_MAX_SIZE = 600;

namespace ARK
{    
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
		public transaction_t, Printable
{
	public:

		Transaction() {};

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
		
		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
				size += p.print("\nid: ");
				size += p.print(this->id);

				size += p.print("\nblockid: ");
				size += p.print(this->blockid);

				size += p.print("\nheight: ");
				size += p.print(this->height);

				size += p.print("\ntype: ");
				size += p.print(this->type);

				size += p.print("\ntimestamp: ");
				size += p.print(this->timestamp);

				size += p.print("\namount: ");
				size += p.print(this->amount.ark());

				size += p.print("\nfee: ");
				size += p.print(this->fee.ark());

				size += p.print("\nvendorField: ");
				size += p.print(this->vendorField);

				size += p.print("\nsenderId: ");
				size += p.print(this->senderId);

				size += p.print("\nrecipientId: ");
				size += p.print(this->recipientId);

				size += p.print("\nsenderPublicKey: ");
				size += p.print(this->senderPublicKey);

				size += p.print("\nsignature: ");
				size += p.print(this->signature);

				// serial.print("\nasset: ");
				// serial.print(this->asset);

				size += p.print("\nconfirmations: ");
				size += p.print(this->confirmations);
			return size;
		}
		/*************************************************/

};
/*************************************************/

};

#endif
 