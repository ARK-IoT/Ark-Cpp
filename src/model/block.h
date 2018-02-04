

#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>

namespace ARK
{

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

/*  ================================================  */
/*  ==========  */
/*  ARK::Block  */
struct Block
{
private:
    static const auto MAX_UINT128_CHARS = 40;

public:
	char id[MAX_UINT128_CHARS];
	int version;
	char timestamp[MAX_UINT128_CHARS];
	uint32_t height;
	char previousBlock[MAX_UINT128_CHARS];
	uint32_t numberOfTransactions;
	Balance totalAmount;
	Balance totalFee;
	Balance reward;
	uint32_t payloadLength;
	Hash payloadHash;
	Publickey generatorPublicKey;
	Address generatorId;
	Signature blockSignature;
	uint32_t confirmations;
	Balance totalForged;

	void description(char* const buf, size_t size);
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


/*  ================================================  */
/*  ===========  */
/*  Description  */
void ARK::Block::Block::description(char* const buf, size_t size)
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "id: ");
    strcat(buf, this->id);
    strcat(buf, "\nversion: ");
    sprintf(buf + strlen(buf), "%d", this->version);
    strcat(buf, "\ntimestamp: ");
    strcat(buf, this->timestamp);
    strcat(buf, "\nheight: ");
    sprintf(buf + strlen(buf), "%d", this->height);
    strcat(buf, "\npreviousBlock: ");
    strcat(buf, this->previousBlock);
    strcat(buf, "\nnumberOfTransactions: ");
    sprintf(buf + strlen(buf), "%d", this->numberOfTransactions);
    strcat(buf, "\ntotalAmount.ark: ");
    strcat(buf, this->totalAmount.ark());
    strcat(buf, "\ntotalFee.ark: ");
    strcat(buf, this->totalFee.ark());
    strcat(buf, "\nreward.ark: ");
    strcat(buf, this->reward.ark());
    strcat(buf, "\npayloadLength: ");
    sprintf(buf + strlen(buf), "%d", this->payloadLength);
    strcat(buf, "\npayloadHash.description: ");
    strcat(buf, this->payloadHash.description());
    strcat(buf, "\ngeneratorPublicKey.description: ");
    strcat(buf, this->generatorPublicKey.description());
    strcat(buf, "\ngeneratorId.description: ");
    strcat(buf, this->generatorId.description());
    strcat(buf, "\nblockSignature.description: ");
    strcat(buf, this->blockSignature.description());
    strcat(buf, "\nconfirmations: ");
    sprintf(buf + strlen(buf), "%d", this->confirmations);
    strcat(buf, "\ntotalForged.ark: ");
    strcat(buf, this->totalForged.ark());
}
/*  ==========  */
/*  ================================================  */


#endif
