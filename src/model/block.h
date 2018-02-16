

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

/*************************************************
*   ARK::Block 
*
**************************************************/
struct Block
{
private:
    static const auto MAX_UINT128_CHARS = 40;

public:
    const char* id;
	int version;
    const char* timestamp;
	const char* height;
	const char* previousBlock;
	const char* numberOfTransactions;
	Balance totalAmount;
	Balance totalFee;
	Balance reward;
	const char* payloadLength;
	Hash payloadHash;
	Publickey generatorPublicKey;
	Address generatorId;
	Signature blockSignature;
	const char* confirmations;
	Balance totalForged;

	void printTo(HardwareSerial &serial);
};
/*************************************************/

};



/*************************************************/
/*************************************************/
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
/*************************************************/
/*************************************************/


/*************************************************
*   ARK::Block::printTo(Serial)
*
**************************************************/
void ARK::Block::Block::printTo(HardwareSerial &serial)
{
    serial.print("id: ");
    serial.print(this->id);
    serial.print("\nversion: ");
    serial.print(this->version);
    serial.print("\ntimestamp: ");
    serial.print(this->timestamp);
    serial.print("\nheight: ");
	serial.print(this->height);
    serial.print("\npreviousBlock: ");
    serial.print(this->previousBlock);
    serial.print("\nnumberOfTransactions: ");
	serial.print(this->numberOfTransactions);
    serial.print("\ntotalAmount: ");
    serial.print(this->totalAmount.ark());
    serial.print("\ntotalFee: ");
    serial.print(this->totalFee.ark());
    serial.print("\nreward: ");
    serial.print(this->reward.ark());
    serial.print("\npayloadLength: ");
    serial.print(this->payloadLength);
    serial.print("\npayloadHash: ");
    serial.print(this->payloadHash.value);
    serial.print("\ngeneratorPublicKey: ");
    serial.print(this->generatorPublicKey.value);
    serial.print("\ngeneratorId: ");
    serial.print(this->generatorId.value);
    serial.print("\nblockSignature: ");
    serial.print(this->blockSignature.value);
    serial.print("\nconfirmations: ");
    serial.print(this->confirmations);
    serial.print("\ntotalForged: ");
    serial.print(this->totalForged.ark());
    serial.println();
    serial.flush();
}
/*************************************************/


#endif
