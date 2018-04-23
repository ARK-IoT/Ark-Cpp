

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
struct Transaction : public transaction_t, Printable
{
public:
	Transaction();
	Transaction(
			const char *const newID,
			const char *const newBlockID,
			const char *const newHeight,
			int 							newType,
			const char *const newTimestamp,
			const char *const newAmount,
			const char *const newFee,
			const char *const newVendorField,
			const char *const newSenderID,
			const char *const newRecipientID,
			const char *const newSenderPublickey,
			const char *const newSignature,
			const char *const newConfirmations
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
};

#endif
