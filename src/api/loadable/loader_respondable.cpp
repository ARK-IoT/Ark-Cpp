#include "loader_respondable.h"

#include <cstring>
#include <cstdio>

/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Status  */
/*  Description  */
void ARK::API::Loader::Respondable::Status::description(char* const buf, size_t size)
{
    //TODO validate size
    strcpy(buf, "loaded: ");
    strcat(buf, this->loaded_ ? "true" : "false");
    strcat(buf, "\nnow: ");
    sprintf(buf + strlen(buf), "%d", this->now_);
    strcat(buf, "\nblocksCount: ");
    strcat(buf, this->blocksCount_);
}
/*  ============  */
/*  ================================================  */




/*  ================================================  */
/*  ============  */
/*  ARK::Loader::Loader::Sync  */
/*  Description  */
void ARK::API::Loader::Respondable::Sync::description(char* const buf, size_t size)
{
    strcpy(buf, "syncing: ");
    strcat(buf, this->syncing_ ? "true" : "false");
    strcat(buf, "\nblocks: ");
    sprintf(buf + strlen(buf), "%d", this->blocks_);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height_);
    strcat(buf, "\nid: ");
    strcat(buf, this->id_);
}
/*  ============  */
/*  ================================================  */
