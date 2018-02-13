#include "voter.h"

/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Voter::Voter::description(char* const buf, size_t /*size*/) {
    strcpy(buf, "username: ");
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nbalance.ark: ");
    strcat(buf, this->balance.ark());
}
/*  =====  */
/*  ================================================  */
