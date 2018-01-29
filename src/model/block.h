

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
public:
	String id;
	int version;
	String timestamp;
	String height;
	String previousBlock;
	String numberOfTransactions;
	Balance totalAmount;
	Balance totalFee;
	Balance reward;
	String payloadLength;
	Hash payloadHash;
	Publickey generatorPublicKey;
	Address generatorId;
	Signature blockSignature;
	String confirmations;
	Balance totalForged;

	String description();
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
String ARK::Block::Block::description()
{
	String resp;
	resp += "id: ";
	resp += this->id;
	resp += "\n";
	resp += "version: ";
	resp += this->version;
	resp += "\n";
	resp += "timestamp: ";
	resp += this->timestamp;
	resp += "\n";
	resp += "height: ";
	resp += this->height;
	resp += "\n";
	resp += "previousBlock: ";
	resp += this->previousBlock;
	resp += "\n";
	resp += "numberOfTransactions: ";
	resp += this->numberOfTransactions;
	resp += "\n";
	resp += "totalAmount.ark: ";
	resp += this->totalAmount.ark;
	resp += "\n";
	resp += "totalFee.ark: ";
	resp += this->totalFee.ark;
	resp += "\n";
	resp += "reward.ark: ";
	resp += this->reward.ark;
	resp += "\n";
	resp += "payloadLength: ";
	resp += this->payloadLength;
	resp += "\n";
	resp += "payloadHash.description: ";
	resp += this->payloadHash.description();
	resp += "\n";
	resp += "generatorPublicKey.description: ";
	resp += this->generatorPublicKey.description();
	resp += "\n";
	resp += "generatorId.description: ";
	resp += this->generatorId.description();
	resp += "\n";
	resp += "blockSignature.description: ";
	resp += this->blockSignature.description();
	resp += "\n";
	resp += "confirmations: ";
	resp += this->confirmations;
	resp += "\n";
	resp += "totalForged.ark: ";
	resp += this->totalForged.ark;
	return resp;
}
/*  ==========  */
/*  ================================================  */


#endif
