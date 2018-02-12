#include "block_respondable.h"

#include <cstring>
#include <cstdio>

/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Status  */
/*  Description  */
void ARK::API::Block::Respondable::Status::description(char* const buf, size_t size)
{
    strcpy(buf, "epoch: ");
    strcat(buf, this->epoch);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\nfee.ark: ");
    strcat(buf, this->fee.ark());
    strcat(buf, "\nmilestone: ");
    const auto len = strlen(buf);
    sprintf(buf + len, "%d", this->milestone);
    strcat(buf, "\nnethash.description: ");
    strcat(buf, this->nethash.description());
    strcat(buf, "\nreward.ark: ");
    strcat(buf, this->reward.ark());
    strcat(buf, "\nsupply.ark: ");
    strcat(buf, this->supply.ark());
}
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Description  */
void ARK::API::Block::Respondable::Height::description(char* const buf, size_t size)
{
    strcpy(buf, "height: ");
    strcat(buf, this->height);
    strcat(buf, "\nid: ");
    strcat(buf, this->id);
}
/*  ====================================  */
/*  ==========================================================================  */
