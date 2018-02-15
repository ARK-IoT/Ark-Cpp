#include "fees.h"

#include <cstring>

namespace ARK {

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  Description  */
void ARK::Fees::Fees::description(char* const buf, size_t /*size*/)
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "send.ark: ");
    strcat(buf, this->send_.ark());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote_.ark());
    strcat(buf, "\ndelegate.ark: ");
    strcat(buf, this->delegate_.ark());
    strcat(buf, "\nsecondsignature.ark: ");
    strcat(buf, this->secondsignature_.ark());
    strcat(buf, "\nmultisignature.ark: ");
    strcat(buf, this->multisignature_.ark());
}
/*  =========  */
/*  ================================================  */


}