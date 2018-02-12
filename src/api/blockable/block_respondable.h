

#ifndef BLOCK_RESPONDABLE_H
#define BLOCK_RESPONDABLE_H

#include "balance.h"
#include "hash.h"

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


#endif