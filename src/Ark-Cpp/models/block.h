

#ifndef BLOCK_H
#define BLOCK_H

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

#endif
