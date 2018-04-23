

#ifndef transaction_h
#define transaction_h

<<<<<<< HEAD
#include "balance.h"
#include "address.h"
#include "publickey.h"
#include "platform.h"

namespace ARK {

//static const auto TRANSACTION_MAX_SIZE = 600;
    
/*  ==========================================================================  */
  /*  ================  */
  /*  ARK::Transaction  */
  class Transaction : public Printable {

    private:
      char id_[65];  //TODO: review array sizes
      char blockid_[65];
      char height_[65];
      int type_;
      char timestamp_[65];
      Balance amount_;
      Balance fee_;
      char vendorField_[65];
      Address senderId_;
      Address recipientId_;
      Publickey senderPublicKey_;
      char signature_[144];
      char confirmations_[65];

  public:
	  Transaction() = default;

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
	  );

	  const char* id() const noexcept { return id_; }
	  const char* block_id() const noexcept { return blockid_; }
	  const char* height() const noexcept { return height_; }
	  int type() const noexcept { return type_; }
	  const char* timestamp() const noexcept { return timestamp_; }
	  const Balance& amount() const noexcept { return amount_; }
	  const Balance& fee() const noexcept { return fee_; }
	  const char* vendor_field() const noexcept { return vendorField_; }
	  const Address& sender_id() const noexcept { return senderId_; }
	  const Address& recipient_id() const noexcept { return recipientId_; }
	  const Publickey& sender_publickey() const noexcept { return senderPublicKey_; }
	  const char* signature() const noexcept { return signature_; }
	  const char* confirmations() const noexcept { return confirmations_; }

      size_t printTo(Print& p) const override;
  };
  /*  ================  */
/*  ==========================================================================  */

};

#endif
 
=======
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
>>>>>>> master
