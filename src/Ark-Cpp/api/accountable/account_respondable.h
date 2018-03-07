

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

#include "balance.h"

namespace ARK {
namespace API {
namespace Account {
namespace Respondable {

/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Respondable::Balance  */
class Balances {
private:
	Balance confirmed_;
	Balance unconfirmed_;

public:
	Balances() = default;
	Balances(const Balance& c, const Balance& u) : confirmed_(c), unconfirmed_(u) { }
	
	const Balance& confirmed() const noexcept { return confirmed_; }
	const Balance& unconfirmed() const noexcept { return unconfirmed_; }

	void description(char* const buf, size_t size);
};
/*  ======================================  */
/*  ==========================================================================  */

}
}
}
}

#endif