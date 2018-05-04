

#ifndef BLOCK_H
#define BLOCK_H

#include "utilities/platform.h"
#include "types/balance.h"
#include "types/hash.h"
#include "types/publickey.h"
#include "types/address.h"
#include "types/signature.h"
#include <cstring>
#include <cstdio>

/********************************************************************************
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
********************************************************************************/

#define MAX_UINT128_CHARS 40

namespace ARK
{
/*************************************************
*	ARK::Block 
**************************************************/
struct Block :
		public Printable
{
	protected:
		char 			id_[MAX_UINT128_CHARS];
		int 			version_;
		char 			timestamp_[MAX_UINT128_CHARS];
		char 			height_[64];
		char 			previousBlock_[MAX_UINT128_CHARS];
		char 			numberOfTransactions_[64];
		Balance		totalAmount_;
		Balance 	totalFee_;
		Balance 	reward_;
		char 			payloadLength_[64];
		Hash 			payloadHash_;
		Publickey generatorPublicKey_;
		Address 	generatorId_;
		Signature blockSignature_;
		char 			confirmations_[64];
		Balance 	totalForged_;
		
	public:
		/*************************************************
		*	ARK::Block 
		**************************************************/
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
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
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
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

};

#endif
