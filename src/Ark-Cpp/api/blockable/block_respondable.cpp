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
    strcat(buf, this->epoch_);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height_);
    strcat(buf, "\nfee.ark: ");
    strcat(buf, this->fee_.ark());
    strcat(buf, "\nmilestone: ");
    sprintf(buf + strlen(buf), "%d", this->milestone_);
    strcat(buf, "\nnethash.description: ");
    strcat(buf, this->nethash_.description());
    strcat(buf, "\nreward.ark: ");
    strcat(buf, this->reward_.ark());
    strcat(buf, "\nsupply.ark: ");
    strcat(buf, this->supply_.ark());
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
    strcat(buf, this->height_);
    strcat(buf, "\nid: ");
    strcat(buf, this->id_);
}
/*  ====================================  */
/*  ==========================================================================  */
