

#ifndef BLOCK_RESPONDABLE_H
#define BLOCK_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{

/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Status  */
struct Status
{
public:
    char epoch[64];  //TODO: check sizes
    char height[64];
    Balance fee;
    int milestone;
    Hash nethash;
    Balance reward;
    Balance supply;

    Status(
        const char* const e, 
        const char* const h,
        const char* const f,
        int m,
        const char* const nh,
        const char* const r,
        const char* const s
    ) : epoch(), height(), fee(f), milestone(m), nethash(nh), reward(r), supply(s)
    {
        strncpy(epoch, e, sizeof(epoch) / sizeof(epoch[0]));
        strncpy(height, h, sizeof(height) / sizeof(height[0]));
    }

    void description(char* const buf, size_t size);
};
/*  ====================================  */
/*  ================================================  */


/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Definition  */
struct Height
{
public:
    char height[64]; // TODO: check sizes 
    char id[64];

    Height(const char* const h, const char* const _id) : height(), id() { 
        strncpy(height, h, sizeof(height) / sizeof(height[0]));
        strncpy(id, _id, sizeof(id) / sizeof(id[0]));
    }

    void description(char* const buf, size_t size);
};
/*  ====================================  */
/*  ==========================================================================  */

};
};
};
};




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Status  */
/*  Description  */
void ARK::API::Block::Respondable::Status::description(char* const buf, size_t /*size*/)
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
void ARK::API::Block::Respondable::Height::description(char* const buf, size_t /*size*/)
{
    strcpy(buf, "height: ");
    strcat(buf, this->height);
    strcat(buf, "\nid: ");
    strcat(buf, this->id);
}
/*  ====================================  */
/*  ==========================================================================  */


#endif