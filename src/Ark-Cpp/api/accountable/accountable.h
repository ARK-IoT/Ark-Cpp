

#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

#include "account_respondable.h"
#include "account_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  =============================  */
/*  PUBLIC: ARK::API::Accountable  */
class Accountable : public API::Account::Gettable, virtual ARK::Utilities::Network::Connectable
{
	
	public:

/*  ==========================================================================  */
		/*  /api/accounts/getBalance?address=arkAddress */
		ARK::API::Account::Respondable::Balances accountBalance(const Address& _arkAddress)
		{
						return ARK::API::Account::Gettable::balance(this->netConnector, _arkAddress);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/accounts/getPublickey?address=arkAddress */
		Publickey accountPublickey(const Address& _arkAddress)
		{
						return ARK::API::Account::Gettable::publickey(this->netConnector, _arkAddress);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/accounts/delegates/fee?address=arkAddress  */
		Balance accountDelegatesFee(const Address& _arkAddress)
		{
						return ARK::API::Account::Gettable::delegatesFee(this->netConnector, _arkAddress);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/accounts/delegates?address=arkAddress  */
		ARK::Delegate accountDelegates(const Address& _arkAddress)
		{
						return ARK::API::Account::Gettable::delegates(this->netConnector, _arkAddress);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/accounts?address=arkAddress  */
		ARK::Account account(const Address& _arkAddress)
		{
						return ARK::API::Account::Gettable::account(this->netConnector, _arkAddress);
		};
/*  ==========================================================================  */

};
/*  =============================  */
/*  ==========================================================================  */
};
};

#endif
