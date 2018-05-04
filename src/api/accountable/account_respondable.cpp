

#include "api/accountable/account_respondable.h"

namespace ARK
{
namespace API
{
namespace Account
{
namespace Respondable
{
/*************************************************
*	ARK::API::Account::Respondable::Balances
*
*	@brief: Empty Initialization
**************************************************/
Balances::Balances() {};
/*************************************************/

/*************************************************
*	ARK::API::Account::Respondable::Balances(const char* const, const char* const)
*
*	@brief: Constructed API Balances Response Object
**************************************************/
Balances::Balances(
		const char *const newConfirmed,
		const char *const newUnconfirmed
)
{
	this->confirmed_ = Balance(newConfirmed);
	this->unconfirmed_ = Balance(newUnconfirmed);
}
/*************************************************/

/*************************************************
*	ARK::API::Account::Respondable::Balances(const Balance& c, const Balance& u)
*
*	@brief: Constructed API Balances Response Object from Balances
**************************************************/
Balances::Balances(
		const Balance& newConfirmed,
		const Balance& newUnconfirmed
)
{
	this->confirmed_ = Balance(newConfirmed);
	this->unconfirmed_ = Balance(newUnconfirmed);
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Balances::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nconfirmed balance.ark: ");
		size += p.print(this->confirmed_.ark());
		size += p.print("\nconfirmed balance.arktoshi: ");
		size += p.print(this->confirmed_.arktoshi());
		size += p.print("\n\nunconfirmed balance.ark: ");
		size += p.print(this->unconfirmed_.ark());
		size += p.print("\nunconfirmed balance.arktoshi: ");
		size += p.print(this->unconfirmed_.arktoshi());
	return size;
};
/*************************************************/

};
};
};
};
