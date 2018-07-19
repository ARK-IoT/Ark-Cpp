#include "models/transaction.h"
#include "types/signature.h"
#include "utilities/slots.h"
#include "utilities/json.h"
#include "crypto/util.h"
#include "crypto/ark_crypto.h"
#include "bcl/Sha256.hpp"
#include "bcl/Base58Check.hpp"

#include <memory>

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
	const char *const newSignSignature,
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
	sign_signature_(newSignSignature),
	confirmations_(),
	buffer_(new uint8_t[TRANSACTION_MAX_SIZE])
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
	const char *const newRecipientID,
	const char *const newVendorField /* = nullptr */
) : 
	blockid_(),
	height_(),
	type_(newType),
	timestamp_(static_cast<uint32_t>(ARK::Utilities::slots::get_time())),
	amount_(newAmount),
	fee_(newFee),
	vendorField_(),
	senderId_(),
	recipientId_(newRecipientID),
	senderPublicKey_(),
	signature_(),
	sign_signature_(),
	confirmations_(),
	buffer_(new uint8_t[TRANSACTION_MAX_SIZE])
{
	if (newVendorField != nullptr) {
		strncpy(vendorField_, newVendorField, sizeof(vendorField_) / sizeof(vendorField_[0]));
	}
}
/*************************************************/

void Transaction::sign(uint8_t network, uint8_t secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
	std::vector<uint8_t> pub_key(ARK::Crypto::COMPRESSED_PUBLIC_KEY_SIZE);
	ARK::Crypto::get_public_key(secret, pub_key);
	senderPublicKey_ = Publickey(HexStr(pub_key).c_str());
	senderId_ = Address(ARK::Crypto::get_address(network, pub_key).c_str());

	auto hash = get_hash(true, true);
	std::vector<uint8_t> signature;
	ARK::Crypto::sign(hash, secret, signature);
	signature_ = Signature(HexStr(signature).c_str());
}

void Transaction::second_sign(uint8_t second_secret[ARK::Crypto::PRIVATE_KEY_SIZE]) {
}

size_t Transaction::get_transaction_bytes(bool skip_signature /* = false */, bool skip_second_signature /* = false */, uint8_t** buffer /* = nullptr */) {
	auto asset_size = 0;

	switch (type_) {
	case TransactionType::NORMAL:
		// Do Nothing
		break;
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
	size_t bb_index = 0;

	buffer_[bb_index++] = static_cast<TransactionTypeIntType>(type_);
	std::memcpy(buffer_.get() + bb_index, &timestamp_, sizeof(timestamp_));
	bb_index += sizeof(uint32_t);
	const auto sender_public_key_buffer = ParseHex(senderPublicKey_.getValue());
	std::memcpy(buffer_.get() + bb_index, &sender_public_key_buffer[0], sender_public_key_buffer.size());
	bb_index += sender_public_key_buffer.size();

	if (recipientId_) {
		uint8_t pub_key_hash[Ripemd160::HASH_LEN] = {};
		uint8_t version = 0;
		Base58Check::pubkeyHashFromBase58Check(recipientId_.getValue(), pub_key_hash, &version);
		buffer_[bb_index++] = version;
		std::memcpy(buffer_.get() + bb_index, pub_key_hash, sizeof(pub_key_hash));
		bb_index += sizeof(pub_key_hash);
	}
	else {
		std::memset(buffer_.get() + bb_index, 0, Ripemd160::HASH_LEN + 1);
		bb_index += Ripemd160::HASH_LEN + 1;
	}

	if (vendorField_[0] != '\0') {
		std::memcpy(buffer_.get() + bb_index, vendorField_, sizeof(vendorField_));
		bb_index += sizeof(vendorField_);
	}
	else {
		std::memset(buffer_.get() + bb_index, 0, 64);
		bb_index += 64;
	}

	uint64_t arktoshi = convert_to_uint64(amount_.arktoshi());
	std::memcpy(buffer_.get() + bb_index, &arktoshi, sizeof(arktoshi));
	bb_index += sizeof(uint64_t);

	arktoshi = convert_to_uint64(fee_.arktoshi());
	std::memcpy(buffer_.get() + bb_index, &arktoshi, sizeof(arktoshi));
	bb_index += sizeof(uint64_t);

	if (asset_size > 0) {
		/*for (var i = 0; i < assetSize; i++) {
			bb.writeByte(assetBytes[i]);
		}*/
	}

	if (!skip_signature && signature_) {
		const auto& s = ParseHex(signature_.getValue());
		std::memcpy(buffer_.get() + bb_index, &s[0], s.size());
		bb_index += s.size();
	}

	if (!skip_second_signature && sign_signature_) {
		const auto& s = ParseHex(sign_signature_.getValue());
		std::memcpy(buffer_.get() + bb_index, &s[0], s.size());
		bb_index += s.size();
	}

	if (buffer != nullptr) {
		*buffer = buffer_.get();
	}

	return bb_index;
}

Sha256Hash Transaction::get_hash(bool skip_signature /* = false */, bool skip_second_signature /* = false */) {
	const auto length = get_transaction_bytes(skip_signature, skip_second_signature);
	return Sha256::getHash(buffer_.get(), length);
}

void Transaction::generate_id() {
	const auto length = get_transaction_bytes();
	auto hash = Sha256::getHash(buffer_.get(), length);
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

std::unique_ptr<ARK::Transaction> make_transaction(
	uint8_t network,
	const char* const address,
	uint32_t amount_in_arktoshi,
	const std::string& vendor_field,
	const char* const passphrase,
	uint8_t* second_secret /* = nullptr */,
	uint32_t version /* = 1 */,
	uint32_t fee_override /* = ARK::send_fee */
) {
	uint8_t secret[ARK::Crypto::PRIVATE_KEY_SIZE] = {};
	ARK::Crypto::get_private_key(passphrase, secret);
	return ARK::Crypto::create_transaction(network, address, amount_in_arktoshi, vendor_field, secret, second_secret, version, fee_override);
}

};
