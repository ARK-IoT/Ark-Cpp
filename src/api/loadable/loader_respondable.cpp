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
    strcat(buf, this->loaded ? "true" : "false");
    strcat(buf, "\nnow: ");
    auto len = strlen(buf);
    sprintf(buf + len, "%d", this->now);
    strcat(buf, "\nblocksCount: ");
    strcat(buf, this->blocksCount);
};
/*  ============  */
/*  ================================================  */




/*  ================================================  */
/*  ============  */
/*  ARK::Loader::Loader::Sync  */
/*  Description  */
void ARK::API::Loader::Respondable::Sync::description(char* const buf, size_t size)
{
    strcpy(buf, "syncing: ");
    strcat(buf, this->syncing ? "true" : "false");
    strcat(buf, "\nblocks: ");
    auto len = strlen(buf);
    sprintf(buf, "%d", this->blocks);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\nid: ");
    strcat(buf, this->id);
};
/*  ============  */
/*  ================================================  */
