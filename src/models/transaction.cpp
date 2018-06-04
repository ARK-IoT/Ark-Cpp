#include "models/transaction.h"
#include "utilities/time.h"
#include "crypto/util.h"
#include "Sha256.hpp"

#include <cstdio>

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
Transaction::Transaction(
		const char *const newID,
		const char *const newBlockID,
		const char *const newHeight,
		int newType,
		const char *const newTimestamp,
		const char *const newAmount,
		const char *const newFee,
		const char *const newVendorField,
		const char *const newSenderID,
		const char *const newRecipientID,
		const char *const newSenderPublickey,
		const char *const newSignature,
		const char *const newConfirmations
) :
	id_(newID),
	blockid_(),
	height_(),
	type_(newType),
	timestamp_(),
	amount_(newAmount),
	fee_(newFee),
	vendorField_(),
	senderId_(newSenderID),
	recipientId_(newRecipientID),
	senderPublicKey_(newSenderPublickey),
	signature_(newSignature),
	confirmations_()
{
	strncpy(blockid_, newBlockID, sizeof(blockid_) / sizeof(blockid_[0]));
	strncpy(height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(timestamp_, newTimestamp, sizeof(timestamp_) / sizeof(timestamp_[0]));
	strncpy(vendorField_, newVendorField, sizeof(vendorField_) / sizeof(vendorField_[0]));
	strncpy(confirmations_, newConfirmations, sizeof(confirmations_) / sizeof(confirmations_[0]));
}

Transaction::Transaction(
	int newType,
	const char *const newAmount,
	const char *const newFee,
	const char *const newSenderID,
	const char *const newRecipientID,
	const char *const newSenderPublickey,
	const char *const newVendorField /* = nullptr */
) : 
	blockid_(),
	height_(),
	type_(newType),
	timestamp_(),
	amount_(newAmount),
	fee_(newFee),
	vendorField_(),
	senderId_(newSenderID),
	recipientId_(newRecipientID),
	senderPublicKey_(newSenderPublickey),
	confirmations_()
{
	// generate transaction timestamp
	auto now = ARK::Utilities::get_time();
	std::snprintf(timestamp_, sizeof(timestamp_), "%lld", now);
}
/*************************************************/

void Transaction::sign(uint8_t secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
	/*
	var hash = getHash(transaction, true, true);

	var signature = keys.sign(hash).toDER().toString("hex");

	if (!transaction.signature) {
		transaction.signature = signature;
	}
	return signature;
	*/
}

void Transaction::second_sign(uint8_t second_secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
}

void Transaction::get_transaction_bytes(uint8_t buffer[512]) {

}

void Transaction::get_hash(uint8_t buffer[Sha256Hash::HASH_LEN], bool skip_signature /* = false */, bool skip_second_signature /* = false */) {

}

void Transaction::generate_id() {
	uint8_t buf[512] = {};
	get_transaction_bytes(buf);
	auto hash = Sha256::getHash(buf, sizeof(buf));
	id_ = Hash(HexStr(hash.value, hash.value + Sha256Hash::HASH_LEN).c_str());
}

/*************************************************
*
**************************************************/
size_t Transaction::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nid: ");
		size += p.print(this->id_.getValue());

		size += p.print("\nblockid: ");
		size += p.print(this->blockid_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\ntype: ");
		size += p.print(this->type_);

		size += p.print("\ntimestamp: ");
		size += p.print(this->timestamp_);

		size += p.print("\namount: ");
		size += p.print(this->amount_.ark());

		size += p.print("\nfee: ");
		size += p.print(this->fee_.ark());

		size += p.print("\nvendorField: ");
		size += p.print(this->vendorField_);

		size += p.print("\nsenderId: ");
		size += p.print(this->senderId_.getValue());

		size += p.print("\nrecipientId: ");
		size += p.print(this->recipientId_.getValue());

		size += p.print("\nsenderPublicKey: ");
		size += p.print(this->senderPublicKey_.getValue());

		size += p.print("\nsignature: ");
		size += p.print(this->signature_.getValue());

		size += p.print("\nconfirmations: ");
		size += p.print(this->confirmations_);
	return size;
}
/*************************************************/

};
