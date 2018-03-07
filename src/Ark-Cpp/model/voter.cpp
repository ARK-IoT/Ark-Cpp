#include "voter.h"

/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Voter::Voter::description(char* const buf, size_t /*size*/) {
    strcpy(buf, "username: ");
    strcat(buf, this->username_);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address_.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey_.description());
    strcat(buf, "\nbalance.ark: ");
    strcat(buf, this->balance_.ark());
}
/*  =====  */
/*  ================================================  */
