

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


	#define MAX_UINT128_CHARS 40


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



	/*************************************************
	*   ARK::Block 
	*
	**************************************************/
	struct Block :
			public block_t
	{
		public:

			Block(
					const char* const newID,
					int newVersion,
					const char* const newTimestamp,
					const char* const newHeight,
					const char* const newPreviousBlock,
					const char* const newNumberOfTransactions,
					const char* const newTotalAmount,
					const char* const newTotalFee,
					const char* const newReward,
					const char* const newPayloadLength,
					const char* const newPayloadHash,
					const char* const newGeneratorPublickey,
					const char* const newGeneratorID,
					const char* const newBlockSignature,
					const char* const newConfirmations,
					const char* const newTotalForged
			)
			{
				strncpy(id, newID, sizeof(id) / sizeof(id[0]));
					version = newVersion;
				strncpy(timestamp, newTimestamp, sizeof(timestamp) / sizeof(timestamp[0]));
				strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
				strncpy(previousBlock, newPreviousBlock, sizeof(previousBlock) / sizeof(previousBlock[0]));
				strncpy(numberOfTransactions, newNumberOfTransactions, sizeof(numberOfTransactions) / sizeof(numberOfTransactions[0]));
					totalAmount = Balance(newTotalAmount);
					totalFee = Balance(newTotalFee);
					reward = Balance(newReward);
				strncpy(payloadLength, newPayloadLength, sizeof(payloadLength) / sizeof(payloadLength[0]));
					payloadHash = Hash(newPayloadHash);
					generatorPublicKey = Publickey(newGeneratorPublickey);
					generatorId = Address(newGeneratorID);
					blockSignature = Signature(newBlockSignature);
				strncpy(confirmations, newConfirmations, sizeof(confirmations) / sizeof(confirmations[0]));
					totalForged = Balance(newTotalForged);
			};

			void printTo(HardwareSerial &serial);
	};
	/*************************************************/


};



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
		serial.print(this->payloadHash.getValue());
	serial.print("\ngeneratorPublicKey: ");
		serial.print(this->generatorPublicKey.getValue());
	serial.print("\ngeneratorId: ");
		serial.print(this->generatorId.getValue());
	serial.print("\nblockSignature: ");
		serial.print(this->blockSignature.getValue());
	serial.print("\nconfirmations: ");
		serial.print(this->confirmations);
	serial.print("\ntotalForged: ");
		serial.print(this->totalForged.ark());
	serial.println();
	serial.flush();
}
/*************************************************/


#endif
