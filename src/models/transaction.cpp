#include "models/transaction.h"
#include "types/signature.h"
#include "utilities/time.h"
#include "utilities/json.h"
#include "crypto/util.h"
#include "crypto/ark_crypto.h"
#include "Sha256.hpp"
#include "Base58Check.hpp"

#include <memory>
#include <cassert>

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
Transaction::Transaction(
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
		const char *const newConfirmations
) :
	id_(newID),
	blockid_(),
	height_(),
	type_(newType),
	timestamp_(newTimestamp),
	amount_(newAmount),
	fee_(newFee),
	vendorField_(),
	senderId_(newSenderID),
	recipientId_(newRecipientID),
	senderPublicKey_(newSenderPublickey),
	signature_(newSignature),
	sign_signature_(),
	confirmations_()
{
	strncpy(blockid_, newBlockID, sizeof(blockid_) / sizeof(blockid_[0]));
	strncpy(height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(vendorField_, newVendorField, sizeof(vendorField_) / sizeof(vendorField_[0]));
	strncpy(confirmations_, newConfirmations, sizeof(confirmations_) / sizeof(confirmations_[0]));
}

Transaction::Transaction(
	TransactionType newType,
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
	timestamp_(static_cast<uint32_t>(ARK::Utilities::get_time())),
	amount_(newAmount),
	fee_(newFee),
	vendorField_(),
	senderId_(newSenderID),
	recipientId_(newRecipientID),
	senderPublicKey_(newSenderPublickey),
	signature_(),
	sign_signature_(),
	confirmations_()
{
}
/*************************************************/

void Transaction::sign(uint8_t secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
	auto hash = get_hash(true, true);
	std::vector<uint8_t> signature;
	ARK::Crypto::sign(hash, secret, signature);
	signature_ = Signature(HexStr(signature).c_str());
}

void Transaction::second_sign(uint8_t second_secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
}

void Transaction::get_transaction_bytes(uint8_t buffer[512], bool skip_signature /* = false */, bool skip_second_signature /* = false */) {
	auto asset_size = 0;

	switch (type_) {
	case TransactionType::SIGNATURE:
		//assetBytes = getSignatureBytes(transaction.asset.signature);
		//assetSize = assetBytes.length;
		break;
	case TransactionType::DELEGATE:
		//assetBytes = new Buffer(transaction.asset.delegate.username, "utf8");
		//assetSize = assetBytes.length;
		break;
	case TransactionType::VOTE:
		//if (transaction.asset.votes !== null) {
		//assetBytes = new Buffer(transaction.asset.votes.join(""), "utf8");
		//assetSize = assetBytes.length;
		//}
		break;
	case TransactionType::MULTI_SIGNATURE:
		/*
		var keysgroupBuffer = new Buffer(transaction.asset.multisignature.keysgroup.join(""), "utf8");
		var bb = new ByteBuffer(1 + 1 + keysgroupBuffer.length, true);
		bb.writeByte(transaction.asset.multisignature.min);
		bb.writeByte(transaction.asset.multisignature.lifetime);
		for (var i = 0; i < keysgroupBuffer.length; i++) {
		bb.writeByte(keysgroupBuffer[i]);
		}
		bb.flip();
		assetBytes = bb.toBuffer();
		assetSize  = assetBytes.length;
		*/
		break;
	}
	std::unique_ptr<uint8_t[]> bb(new uint8_t[1 + 4 + 32 + 8 + 8 + 21 + 64 + 64 + 64 + asset_size]);
	size_t bb_index = 0;
	bb[bb_index++] = static_cast<TransactionTypeIntType>(type_);
	*reinterpret_cast<uint32_t* const>(bb.get() + bb_index) = timestamp_;
	bb_index += sizeof(uint32_t);
	for (auto b : ParseHex(senderPublicKey_.getValue())) {
		bb[bb_index++] = b;
	}
	if (recipientId_) {
		uint8_t pub_key_hash[Ripemd160::HASH_LEN] = {};
		uint8_t version = 0;
		Base58Check::pubkeyHashFromBase58Check(recipientId_.getValue(), pub_key_hash, &version);
		for (auto b : ParseHex(recipientId_.getValue())) {
			bb[bb_index++] = b;
		}
	}
	else {
		std::memset(bb.get() + bb_index, 0, Ripemd160::HASH_LEN + 1);
		bb_index += Ripemd160::HASH_LEN + 1;
	}

	if (vendorField_[0] != '\0') {
		auto vendor_field_bytes = ParseHex(vendorField_);
		for (auto b : vendor_field_bytes) {
			bb[bb_index++] = b;
		}
		auto byte_pad_length = 64 - vendor_field_bytes.size();
		if (byte_pad_length > 0) {
			std::memset(bb.get() + bb_index, 0, byte_pad_length);
			bb_index += byte_pad_length;
		}
	}

	*reinterpret_cast<uint64_t* const>(bb.get() + bb_index) = convert_to_uint64(amount_.arktoshi());
	bb_index += sizeof(uint64_t);

	*reinterpret_cast<uint64_t* const>(bb.get() + bb_index) = convert_to_uint64(fee_.arktoshi());
	bb_index += sizeof(uint64_t);

	if (asset_size > 0) {
		/*for (var i = 0; i < assetSize; i++) {
			bb.writeByte(assetBytes[i]);
		}*/
	}

	if (!skip_signature && signature_) {
		for (auto b : ParseHex(signature_.getValue())) {
			bb[bb_index++] = b;
		}
	}

	if (!skip_second_signature && sign_signature_) {
		for (auto b : ParseHex(sign_signature_.getValue())) {
			bb[bb_index++] = b;
		}
	}

	assert(bb_index < sizeof(buffer));

	std::memcpy(buffer, bb.get(), sizeof(buffer));
	/*
	bb.flip();
	var arrayBuffer = new Uint8Array(bb.toArrayBuffer());
	var buffer = [];
	for (var i = 0; i < arrayBuffer.length; i++) {
	buffer[i] = arrayBuffer[i];
	}
	return new Buffer(buffer);
	*/
}

Sha256Hash Transaction::get_hash(bool skip_signature /* = false */, bool skip_second_signature /* = false */) {
	//return crypto.createHash("sha256").update(getBytes(transaction, skipSignature, skipSecondSignature)).digest();
	uint8_t bytes[512] = {};
	get_transaction_bytes(bytes, skip_signature, skip_second_signature);
	return Sha256::getHash(bytes, sizeof(bytes));
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
std::string Transaction::json() const {
	auto json = ARK::Utilities::make_json_string();
	return json->transactionToJson(*this);
}

size_t Transaction::printTo(Print &p) const {
	size_t size = 0;
		size += p.print("\nid: ");
		size += p.print(this->id_.getValue());

		size += p.print("\nblockid: ");
		size += p.print(this->blockid_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\ntype: ");
		size += p.print(static_cast<TransactionTypeIntType>(this->type_));

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
