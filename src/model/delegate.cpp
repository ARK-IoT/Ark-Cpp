#include "delegate.h"

/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Delegate::Delegate::description(char* const buf, size_t /*size*/) const
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "username: ");
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote.ark());
    strcat(buf, "\nproducedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->producedblocks);
    strcat(buf, "\nmissedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->missedblocks);
    strcat(buf, "\nrate: ");
    sprintf(buf + strlen(buf), "%d", this->rate);
    strcat(buf, "\napproval: ");
    sprintf(buf + strlen(buf), "%f", this->approval);
    strcat(buf, "%\nproductivity: ");
    sprintf(buf + strlen(buf), "%f", this->productivity);
    strcat(buf, "%");
}
/*  =====  */
/*  ================================================  */
