

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

#include "types/balance.h"
#include "utilities/platform.h"

namespace ARK
{
namespace API
{
namespace Account
{
namespace Respondable
{
/**************************************************************************************************/

/*************************************************
*	ARK::API::Account::Respondable::Balances
*
*	@brief: Constructed API Balances Response Object
**************************************************/
class Balances : public Printable
{
private:
	Balance confirmed_;
	Balance unconfirmed_;

public:
	/*************************************************
	*	ARK::API::Account::Respondable::Balances
	*
	*	@brief: Empty Initialization
	**************************************************/
	Balances() = default;
	/*************************************************/

	/*************************************************
	*	ARK::API::Account::Respondable::Balances(double, double)
	*
	*	@brief: Constructed API Balances Response Object
	**************************************************/
	Balances(
			double newConfirmed,
			double newUnconfirmed
	);
	/*************************************************/

	/*************************************************
	*	ARK::API::Account::Respondable::Balances(const Balance& c, const Balance& u)
	*
	*	@brief: Constructed API Balances Response Object from Balances
	**************************************************/
	Balances(
			const Balance& newConfirmed,
			const Balance& newUnconfirmed
	);
	/*************************************************/

	/*************************************************
	*	Accessors
	**************************************************/
	const Balance& confirmed() const noexcept { return confirmed_; }
	const Balance& unconfirmed() const noexcept { return unconfirmed_; }
	/*************************************************/

	/*************************************************
	*	@brief: Prints balances_t items
	**************************************************/
	virtual size_t printTo(Print &p) const;
	/*************************************************/
};

};
};
};
};

#endif
