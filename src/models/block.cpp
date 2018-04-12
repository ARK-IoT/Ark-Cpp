#include "models/block.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
Block::Block(
		const char *const newID,
		int 							newVersion,
		const char *const newTimestamp,
		const char *const newHeight,
		const char *const newPreviousBlock,
		const char *const newNumberOfTransactions,
		const char *const newTotalAmount,
		const char *const newTotalFee,
		const char *const newReward,
		const char *const newPayloadLength,
		const char *const newPayloadHash,
		const char *const newGeneratorPublickey,
		const char *const newGeneratorID,
		const char *const newBlockSignature,
		const char *const newConfirmations,
		const char *const newTotalForged
)
{
	strncpy(this->id_, newID, sizeof(id_) / sizeof(id_[0]));
	this->version_ = newVersion;
	strncpy(this->timestamp_, newTimestamp, sizeof(timestamp_) / sizeof(timestamp_[0]));
	strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(this->previousBlock_, newPreviousBlock, sizeof(previousBlock_) / sizeof(previousBlock_[0]));
	strncpy(this->numberOfTransactions_, newNumberOfTransactions, sizeof(numberOfTransactions_) / sizeof(numberOfTransactions_[0]));
	this->totalAmount_ = Balance(newTotalAmount);
	this->totalFee_ = Balance(newTotalFee);
	this->reward_ = Balance(newReward);
	strncpy(this->payloadLength_, newPayloadLength, sizeof(payloadLength_) / sizeof(payloadLength_[0]));
	this->payloadHash_ = Hash(newPayloadHash);
	this->generatorPublicKey_ = Publickey(newGeneratorPublickey);
	this->generatorId_ = Address(newGeneratorID);
	this->blockSignature_ = Signature(newBlockSignature);
	strncpy(this->confirmations_, newConfirmations, sizeof(confirmations_) / sizeof(confirmations_[0]));
	this->totalForged_ = Balance(newTotalForged);
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Block::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("id: ");
		size += p.print(this->id_);

		size += p.print("\nversion: ");
		size += p.print(this->version_);

		size += p.print("\ntimestamp: ");
		size += p.print(this->timestamp_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\npreviousBlock: ");
		size += p.print(this->previousBlock_);

		size += p.print("\nnumberOfTransactions: ");
		size += p.print(this->numberOfTransactions_);

		size += p.print("\ntotalAmount: ");
		size += p.print(this->totalAmount_.ark());

		size += p.print("\ntotalFee: ");
		size += p.print(this->totalFee_.ark());

		size += p.print("\nreward: ");
		size += p.print(this->reward_.ark());

		size += p.print("\npayloadLength: ");
		size += p.print(this->payloadLength_);

		size += p.print("\npayloadHash: ");
		size += p.print(this->payloadHash_);

		size += p.print("\ngeneratorPublicKey: ");
		size += p.print(this->generatorPublicKey_);

		size += p.print("\ngeneratorId: ");
		size += p.print(this->generatorId_);

		size += p.print("\nblockSignature: ");
		size += p.print(this->blockSignature_);

		size += p.print("\nconfirmations: ");
		size += p.print(this->confirmations_);

		size += p.print("\ntotalForged: ");
		size += p.print(this->totalForged_.ark());
	return size;
}
/*************************************************/

};
