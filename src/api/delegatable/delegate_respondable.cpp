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
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote.ark());
    strcat(buf, "\nproducedblocks: ");
    auto len = strlen(buf);
    sprintf(buf + len, "%d", this->producedblocks);
    strcat(buf, "\nmissedblocks: ");
    len = strlen(buf);
    sprintf(buf + len, "%d", this->missedblocks);
}
/*  =======================================  */
/*  ==========================================================================  */



/*  =========================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::Voters::description(char* const buf, size_t size) {
  if (this->count > 0) {
      buf[0] = '\0';
    for (auto i = 0u; i < this->count; ++i) {
        strcat(buf, "\nvoter ");
        auto len = strlen(buf);
        sprintf(buf + len, "%d", i + 1);
        strcat(buf, ":\n");
        len = strlen(buf);
        (*this)[i].description(buf + len, size - len);
        strcat(buf, "\n");
    };
  };
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
    strcat(buf, this->fees.ark());
    strcat(buf, "\nrewards.ark: ");
    strcat(buf, this->rewards.ark());
    strcat(buf, "\nforged.ark: ");
    strcat(buf, this->forged.ark());
}
/*  ==================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Delegate::Respondable::NextForgers  */
/*  Constructor  */
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
    const char* const _currentBlock, const char* const _currentSlot,
    const Publickey* const _delegates) : currentBlock(), currentSlot()
{
    //TODO:  wish i had std::array for _delegates.  pointer decay sucks.
    strncpy(this->currentBlock, _currentBlock, sizeof(this->currentBlock));
    strncpy(this->currentSlot, _currentSlot, sizeof(this->currentSlot));
	for (auto i = 0; i < 10; ++i)
	{
		this->delegates[i] = _delegates[i];
	};
}
/*  ============================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::NextForgers::description(char* const buf, size_t size)
{
    strcpy(buf, "currentBlock: ");
    strcat(buf, this->currentBlock);
    strcat(buf, "\ncurrentSlot: ");
    strcat(buf, this->currentSlot);
    strcat(buf, "\n");

	for (auto i = 0; i < 10; ++i)
	{
        strcat(buf, "delegate ");
        const auto len = strlen(buf);
        sprintf(buf + len, "%d", i + 1);
        strcat(buf, ": \n publicKey: ");
        strcat(buf, delegates[i].description());
        strcat(buf, "\n");
	};
}
/*  ============================================  */
/*  ==========================================================================  */

