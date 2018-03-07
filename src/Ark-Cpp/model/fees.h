

#ifndef fees_h
#define fees_h

#include "balance.h"

namespace ARK
{

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  /api/blocks/getFees */
struct Fees
{
    Balance send_;
    Balance vote_;
    Balance delegate_;
    Balance secondsignature_;
    Balance multisignature_;

    Fees(
        const char* const s,
        const char* const v,
        const char* const d,
        const char* const ss,
        const char* const ms
    ) : send_(s), vote_(v), delegate_(d), secondsignature_(ss), multisignature_(ms) { }

	const Balance& send() const noexcept { return send_; }
	const Balance& vote() const noexcept { return vote_; }
	const Balance& delegate() const noexcept { return delegate_; }
	const Balance& second_signature() const noexcept { return secondsignature_; }
	const Balance& multi_signature() const noexcept { return multisignature_; }

    void description(char* const buf, size_t size);
};
/*  =========  */
/*  ================================================  */

};

#endif
