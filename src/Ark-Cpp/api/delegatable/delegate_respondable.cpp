#include "delegate_respondable.h"
#include "json.h"

#include <cstring>
#include <cstdio>

/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Delegate::Respondable::Search  */
/*  Description  */
void ARK::API::Delegate::Respondable::Search::description(char* const buf, size_t size)
{
    strcpy(buf, "username: ");
    strcat(buf, this->username_);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address_.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey_.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote_.ark());
    strcat(buf, "\nproducedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->producedblocks_);
    strcat(buf, "\nmissedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->missedblocks_);
}
/*  =======================================  */
/*  ==========================================================================  */



/*  =========================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::Voters::description(char* const buf, size_t size) {
	if (this->count_ > 0) {
		buf[0] = '\0';
		for (auto i = 0u; i < this->count_; ++i) {
			strcat(buf, "\nvoter ");
			sprintf(buf + strlen(buf), "%d", i + 1);
			strcat(buf, ":\n");
			const auto len = strlen(buf);
			(*this)[i].description(buf + len, size - len);
			strcat(buf, "\n");
		}
	}
}
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==================================================  */
/*  ARK::API::Delegate::Respondable::ForgedByAccount  */
/*  Description  */
void ARK::API::Delegate::Respondable::ForgedByAccount::description(char* const buf, size_t size)
{
	strcpy(buf, "fees.ark: ");
	strcat(buf, this->fees_.ark());
	strcat(buf, "\nrewards.ark: ");
	strcat(buf, this->rewards_.ark());
	strcat(buf, "\nforged.ark: ");
	strcat(buf, this->forged_.ark());
}
/*  ==================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Delegate::Respondable::NextForgers  */
/*  Constructor  */
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
    const char* const currentBlock, const char* const currentSlot,
    const Publickey* const delegates) : currentBlock_(), currentSlot_()
{
    //TODO:  wish i had std::array for _delegates.  pointer decay sucks.
    strncpy(this->currentBlock_, currentBlock, sizeof(this->currentBlock_));
    strncpy(this->currentSlot_, currentSlot, sizeof(this->currentSlot_));
	for (auto i = 0; i < 10; ++i)
	{
		this->delegates_[i] = delegates[i];
	};
}
/*  ============================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::NextForgers::description(char* const buf, size_t size)
{
	strcpy(buf, "currentBlock: ");
	strcat(buf, this->currentBlock_);
	strcat(buf, "\ncurrentSlot: ");
	strcat(buf, this->currentSlot_);
	strcat(buf, "\n");

	for (auto i = 0; i < 10; ++i)
	{
		strcat(buf, "delegate ");
		sprintf(buf + strlen(buf), "%d", i + 1);
		strcat(buf, ": \n publicKey: ");
		strcat(buf, delegates_[i].description());
		strcat(buf, "\n");
	}
}
/*  ============================================  */
/*  ==========================================================================  */

