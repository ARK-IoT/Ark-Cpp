

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

#include "address.h"
#include "publickey.h"
#include "balance.h"
#include "voter.h"

#include <array>
#include <memory>

namespace ARK {
namespace API {
namespace Delegate {
namespace Respondable {


/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Delegate::Respondable::Search  */
class Search {
private:
	char username_[64]; //TODO review sizes
	Address address_;
	Publickey publicKey_;
	Balance vote_;
	int producedblocks_;
	int missedblocks_;

public:
	Search(
		const char* const u, 
		const char* const a, 
		const char* const pk, 
		const char* const v, 
		int pb, 
		int mb
	) : username_(), address_(a), publicKey_(pk), vote_(v), producedblocks_(pb), missedblocks_(mb) {
		strncpy(username_, u, sizeof(username_) / sizeof(username_[0]));
	}

	const char* username() const noexcept { return username_; }
	const Address& address() const noexcept { return address_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	const Balance& vote() const noexcept { return vote_; }
	int produced_blocks() const noexcept { return producedblocks_; }
	int missed_blocks() const noexcept { return missedblocks_; }

	void description(char* const buf, size_t size);
};
/*  =======================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  =========================================  */
  /*  ARK::API::Delegate::Respondable::Voters  */
class Voters {
private:
    size_t count_;
    std::unique_ptr<ARK::Voter> voters_;

public:
    Voters(size_t c) : count_(c), voters_(new ARK::Voter[c]) { }

    const Voter& operator[](size_t index) const { return voters_.get()[index]; }
    Voter& operator[](size_t index) { return voters_.get()[index]; }

    void description(char* const buf, size_t size);
};
/*  =========================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==================================================  */
  /*  ARK::API::Delegate::Respondable::ForgedByAccount  */
class ForgedByAccount {
private:
	Balance fees_;
	Balance rewards_;
	Balance forged_;

public:
	ForgedByAccount(
		const char* const f, 
		const char* const r, 
		const char* const fg
	) : fees_(f), rewards_(r), forged_(fg) { }

	const Balance& fees() const noexcept { return fees_; }
	const Balance& rewards() const noexcept { return rewards_; }
	const Balance& forged() const noexcept { return forged_; }

	void description(char* const buf, size_t size);
};
/*  ==================================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==============================================  */
  /*  ARK::API::Delegate::Respondable::NextForgers  */
class NextForgers {
public:
	char currentBlock_[64];
	char currentSlot_[64];
	std::array<Publickey, 10> delegates_;

	NextForgers(const char* const _currentBlock, const char* const _currentSlot, const Publickey* const _delegates);

	const char* current_block() const noexcept { return currentBlock_; }
	const char* current_slot() const noexcept { return currentSlot_; }
	const std::array<Publickey, 10>& delegates() const noexcept { return delegates_; }

	void description(char* const buf, size_t size);
};
/*  ==============================================  */
/*  ==========================================================================  */

}
}
}
}

#endif
