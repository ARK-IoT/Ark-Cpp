

#ifndef BLOCK_H
#define BLOCK_H

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
    ) : id(), version(v), timestamp(), height(), previousBlock(), numberOfTransactions(), totalAmount(ta), totalFee(tf), reward(r), payloadLength(), payloadHash(ph), generatorPublicKey(gpk), generatorId(gid), blockSignature(bs), confirmations(), totalForged(tfg)
    { 
        strncpy(id, _id, sizeof(id) / sizeof(id[0]));
        strncpy(timestamp, t, sizeof(timestamp) / sizeof(timestamp[0]));
        strncpy(height, h, sizeof(height) / sizeof(height[0]));
        strncpy(previousBlock, pb, sizeof(previousBlock) / sizeof(previousBlock[0]));
        strncpy(numberOfTransactions, nt, sizeof(numberOfTransactions) / sizeof(numberOfTransactions[0]));
        strncpy(payloadLength, pl, sizeof(payloadLength) / sizeof(payloadLength[0]));
        strncpy(confirmations, c, sizeof(confirmations) / sizeof(confirmations[0]));
    }

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
    strcat(buf, this->payloadLength);
    strcat(buf, "\npayloadHash.description: ");
    strcat(buf, this->payloadHash.description());
    strcat(buf, "\ngeneratorPublicKey.description: ");
    strcat(buf, this->generatorPublicKey.description());
    strcat(buf, "\ngeneratorId.description: ");
    strcat(buf, this->generatorId.description());
    strcat(buf, "\nblockSignature.description: ");
    strcat(buf, this->blockSignature.description());
    strcat(buf, "\nconfirmations: ");
    strcat(buf, this->confirmations);
    strcat(buf, "\ntotalForged.ark: ");
    strcat(buf, this->totalForged.ark());
}
/*  ==========  */
/*  ================================================  */


#endif
