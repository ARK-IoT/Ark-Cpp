#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "constants/constants.h"
#include "utilities/platform.h"
#include "types/balance.h"
#include "types/address.h"
#include "types/hash.h"
#include "types/publickey.h"
#include "types/signature.h"

#include "Sha256Hash.hpp"

#include <cstring>
#include <cstdio>

static const auto TRANSACTION_MAX_SIZE = 600;

namespace ARK
{

enum class TransactionType : uint8_t {
	NORMAL = 0,
	SIGNATURE = 1,
	DELEGATE = 2,
	VOTE = 3,
	MULTI_SIGNATURE = 4
};

typedef typename std::underlying_type<TransactionType>::type TransactionTypeIntType;

/*************************************************
*	ARK::Transaction
**************************************************/
class Transaction : public Printable {
private:
	Hash id_;
	char blockid_[32];
	char height_[32];
	TransactionType type_;
	uint32_t timestamp_;
	Balance amount_;
	Balance fee_;
	char vendorField_[64];
	Address senderId_;
	Address recipientId_;
	Publickey senderPublicKey_;
	Signature signature_;
	Signature sign_signature_;
	char confirmations_[64];
	
	uint8_t buffer_[270];

public:
	/*************************************************
	*	Default: Empty Constructor
	**************************************************/
	Transaction() = default;
	/*************************************************/

	/*************************************************
	*	Constructor
	**************************************************/
	Transaction(
		const char *const newID,
		const char *const newBlockID,
		const char *const newHeight,
		TransactionType newType,
		uint32_t newTimestamp,
		const char *const newAmount,
		const char *const newFee,
		const char *const newVendorField,
		const char *const newSenderID,
		const char *const newRecipientID,
		const char *const newSenderPublickey,
		const char *const newSignature,
		const char *const newSignSignature,
		const char *const newConfirmations
	);

	Transaction(
		TransactionType newType,
		const char *const newAmount,
		const char *const newFee,
		const char *const newRecipientID,
		const char *const newVendorField = nullptr
	);

	/*************************************************/

	/*************************************************
	*	Accessors
	**************************************************/
	const char* id() const noexcept { return id_.getValue(); }
	const char* block_id() const noexcept { return blockid_; }
	const char* height() const noexcept { return height_; }
	TransactionType type() const noexcept { return type_; }
	uint32_t timestamp() const noexcept { return timestamp_; }
	const Balance& amount() const noexcept { return amount_; }
	const Balance& fee() const noexcept { return fee_; }
	const char* vendor_field() const noexcept { return vendorField_; }
	const Address& sender_id() const noexcept { return senderId_; }
	const Address& recipient_id() const noexcept { return recipientId_; }
	const Publickey& sender_publickey() const noexcept { return senderPublicKey_; }
	const Signature& signature() const noexcept { return signature_; }
	const Signature& sign_signature() const noexcept { return sign_signature_; }
	const char* confirmations() const noexcept { return confirmations_; }
	/*************************************************/

	/*************************************************
	*
	**************************************************/
	void sign(uint8_t network, uint8_t secret[ARK::Crypto::PRIVATE_KEY_SIZE]);
	void second_sign(uint8_t second_secret[ARK::Crypto::PRIVATE_KEY_SIZE]);
	size_t get_transaction_bytes(bool skip_signature = false, bool skip_second_signature = false);
	Sha256Hash get_hash(bool skip_signature = false, bool skip_second_signature = false);
	void generate_id();
	/*************************************************/

	/*************************************************/
	std::string json() const;
	virtual size_t printTo(Print &p) const;
	/*************************************************/

};
/*************************************************/

ARK::Transaction make_transaction(
	uint8_t network,
	const char* const address,
	uint64_t amount_in_arktoshi,
	const std::string& vendor_field,
	const char* const passphrase,
	uint8_t* second_secret = nullptr,
	uint32_t version = 1,
	uint64_t fee_override = ARK::send_fee
);

};

#endif
