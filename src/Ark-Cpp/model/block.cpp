#include "block.h"

#include <cstring>
#include <cstdio>

/*  ================================================  */
/*  ===========  */
/*  Description  */
void ARK::Block::Block::description(char* const buf, size_t /*size*/)
{
	//TODO:  check len for sufficient size  
	strcpy(buf, "id: ");
	strcat(buf, this->id_);
	strcat(buf, "\nversion: ");
	sprintf(buf + strlen(buf), "%d", this->version_);
	strcat(buf, "\ntimestamp: ");
	strcat(buf, this->timestamp_);
	strcat(buf, "\nheight: ");
	strcat(buf, this->height_);
	strcat(buf, "\npreviousBlock: ");
	strcat(buf, this->previousBlock_);
	strcat(buf, "\nnumberOfTransactions: ");
	strcat(buf, this->numberOfTransactions_);
	strcat(buf, "\ntotalAmount.ark: ");
	strcat(buf, this->totalAmount_.ark());
	strcat(buf, "\ntotalFee.ark: ");
	strcat(buf, this->totalFee_.ark());
	strcat(buf, "\nreward.ark: ");
	strcat(buf, this->reward_.ark());
	strcat(buf, "\npayloadLength: ");
	strcat(buf, this->payloadLength_);
	strcat(buf, "\npayloadHash.description: ");
	strcat(buf, this->payloadHash_.description());
	strcat(buf, "\ngeneratorPublicKey.description: ");
	strcat(buf, this->generatorPublicKey_.description());
	strcat(buf, "\ngeneratorId.description: ");
	strcat(buf, this->generatorId_.description());
	strcat(buf, "\nblockSignature.description: ");
	strcat(buf, this->blockSignature_.description());
	strcat(buf, "\nconfirmations: ");
	strcat(buf, this->confirmations_);
	strcat(buf, "\ntotalForged.ark: ");
	strcat(buf, this->totalForged_.ark());
}
/*  ==========  */
/*  ================================================  */

