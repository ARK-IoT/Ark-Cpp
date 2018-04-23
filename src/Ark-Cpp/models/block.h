

#ifndef BLOCK_H
#define BLOCK_H

<<<<<<< HEAD
#include "balance.h"
#include "hash.h"
#include "publickey.h"
#include "address.h"
#include "signature.h"
#include "platform.h"

#include <cstring>
#include <cstdio>

namespace ARK {

=======
>>>>>>> master
/********************************************************************************
*
* block: 
*		{  
*			"id":	String(lluint),
*			"version":	int,
*			"timestamp":	String(lluint),
*			"height":	uint,
*			"previousBlock":	String(lluint),
*			"numberOfTransactions": int,
*			"totalAmount": Balance,
*			"totalFee":	Balance::arktoshi,
*			"reward":	Balance::arktoshi,
*			"payloadLength": int,
*			"payloadHash":	Hash,
*			"generatorPublicKey":	Publickey,
*			"generatorId": Address,
*			"blockSignature": Signature,
*			"confirmations":	int,
*			"totalForged":	Balance
*		}
*
********************************************************************************/

<<<<<<< HEAD
/*  ================================================  */
/*  ==========  */
/*  ARK::Block  */
class Block : public Printable {
private:
    static const auto MAX_UINT128_CHARS = 40;

public:
	char id_[MAX_UINT128_CHARS];
	int version_;
	char timestamp_[MAX_UINT128_CHARS];
	char height_[64];
	char previousBlock_[MAX_UINT128_CHARS];
	char numberOfTransactions_[64];
	Balance totalAmount_;
	Balance totalFee_;
	Balance reward_;
	char payloadLength_[64];
	Hash payloadHash_;
	Publickey generatorPublicKey_;
	Address generatorId_;
	Signature blockSignature_;
	char confirmations_[64];
	Balance totalForged_;

    Block(
        const char* const _id,
        int v,
        const char* const t,
        const char* const h,
        const char* const pb,
        const char* const nt,
        const char* const ta,
        const char* const tf,
        const char* const r,
        const char* const pl,
        const char* const ph,
        const char* const gpk,
        const char* const gid,
        const char* const bs,
        const char* const c,
        const char* const tfg
    ) : 
		id_(), 
		version_(v), 
		timestamp_(), 
		height_(), 
		previousBlock_(), 
		numberOfTransactions_(), 
		totalAmount_(ta), 
		totalFee_(tf), 
		reward_(r), 
		payloadLength_(), 
		payloadHash_(ph), 
		generatorPublicKey_(gpk), 
		generatorId_(gid), 
		blockSignature_(bs), 
		confirmations_(), 
		totalForged_(tfg)
    { 
        strncpy(id_, _id, sizeof(id_) / sizeof(id_[0]));
        strncpy(timestamp_, t, sizeof(timestamp_) / sizeof(timestamp_[0]));
        strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
        strncpy(previousBlock_, pb, sizeof(previousBlock_) / sizeof(previousBlock_[0]));
        strncpy(numberOfTransactions_, nt, sizeof(numberOfTransactions_) / sizeof(numberOfTransactions_[0]));
        strncpy(payloadLength_, pl, sizeof(payloadLength_) / sizeof(payloadLength_[0]));
        strncpy(confirmations_, c, sizeof(confirmations_) / sizeof(confirmations_[0]));
    }

	const char* id() const noexcept { return id_; }
	int version() const noexcept { return version_; }
	const char* timestamp() const noexcept { return timestamp_; }
	const char* height() const noexcept { return height_; }
	const char* previous_block() const noexcept { return previousBlock_; }
	const char* number_of_transactions() const noexcept { return numberOfTransactions_; }
	const Balance& total_amount() const noexcept { return totalAmount_; }
	const Balance& total_fee() const noexcept { return totalFee_; }
	const Balance& reward() const noexcept { return reward_; }
	const char* payload_length() const noexcept { return payloadLength_; }
	const Hash& payload_hash() const noexcept { return payloadHash_; }
	const Publickey& generator_public_key() const noexcept { return generatorPublicKey_; }
	const Address& generator_id() const noexcept { return generatorId_; }
	const Signature& block_signature() const noexcept { return blockSignature_; }
	const char* confirmations() const noexcept { return confirmations_; }
	const Balance& total_forged() const noexcept { return totalForged_; }

	size_t printTo(Print& p) const override;
};
/*  ==========  */
/*  ================================================  */

};


/**********************************
blockEpoch: 
2017-03-21T13:00:00.000Z
***********************************/


/*  ================================================  */
/*  ===========  */
/*  ARK::Blocks  */
// struct Blocks
// {
// public:
// 	Block blocks[] = {};
// 	int count;
// 	Blocks()
// 	{	this->count = 0; };
// };
// /*  ===========  */
// };
/*  ================================================  */

=======
#define MAX_UINT128_CHARS 40

namespace ARK
{
/*************************************************
*   ARK::block_t 
*
**************************************************/
struct block_t
{
public:
	char id[MAX_UINT128_CHARS];
	int version;
	char timestamp[MAX_UINT128_CHARS];
	char height[64];
	char previousBlock[MAX_UINT128_CHARS];
	char numberOfTransactions[64];
	Balance totalAmount;
	Balance totalFee;
	Balance reward;
	char payloadLength[64];
	Hash payloadHash;
	Publickey generatorPublicKey;
	Address generatorId;
	Signature blockSignature;
	char confirmations[64];
	Balance totalForged;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Block 
*
**************************************************/
struct Block : public block_t, Printable
{
public:
	Block(
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
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
};

>>>>>>> master
#endif
