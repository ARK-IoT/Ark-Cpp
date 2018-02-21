

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
class Status
{
private:
    char epoch_[64];  //TODO: check sizes
    char height_[64];
    Balance fee_;
    int milestone_;
    Hash nethash_;
    Balance reward_;
    Balance supply_;

public:
    Status(
        const char* const e, 
        const char* const h,
        const char* const f,
        int m,
        const char* const nh,
        const char* const r,
        const char* const s
    ) : epoch_(), height_(), fee_(f), milestone_(m), nethash_(nh), reward_(r), supply_(s)
    {
        strncpy(epoch_, e, sizeof(epoch_) / sizeof(epoch_[0]));
        strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
    }

	const char* epoch() const noexcept { return epoch_; }
	const char* height() const noexcept { return height_; }
	const Balance& fee() const noexcept { return fee_; }
	int milestone() const noexcept { return milestone_; }
	const Hash& nethash() const noexcept { return netnash_; }
	const Balance& reward() const noexcept { return reward_; }
	const Balance& supply() const noexcept { return supply_; }

    void description(char* const buf, size_t size);
};
/*  ====================================  */
/*  ================================================  */


/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Definition  */
class Height {
private:
    char height_[64]; // TODO: check sizes 
    char id_[64];

public:
    Height(const char* const h, const char* const i) : height_(), id_() { 
        strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
        strncpy(id_, i, sizeof(id_) / sizeof(id_[0]));
    }

	const char* height() const noexcept { return height_; }
	const char* id() const noexcept { return id_; }

    void description(char* const buf, size_t size);
};

}
}
}
}


#endif