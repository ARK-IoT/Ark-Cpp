

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
*	ARK::API::Account::Respondable::Balances(const char* const, const char* const)
*
*	@brief: Constructed API Balances Response Object
**************************************************/
Balances::Balances(
		double newConfirmed,
		double newUnconfirmed
) : confirmed_(newConfirmed), unconfirmed_(newUnconfirmed)
{
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
) : confirmed_(newConfirmed), unconfirmed_(newUnconfirmed)
{
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Balances::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("\nconfirmed balance.ark: ");
	size += p.print(confirmed_.getValue());
	size += p.print("\n\nunconfirmed balance.ark: ");
	size += p.print(unconfirmed_.getValue());
	return size;
};
/*************************************************/

};
};
};
};
