

#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

#include "account_respondable.h"
#include "account_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Accountable
*   	public API::Account::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Account Model
* 
**************************************************/
class Accountable :
		public Account::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*		/api/accounts/getBalance?address=arkAddress
		*
		*		@uri:	api/accounts/getBalance?address=arkAddress
		*		@returnType:	ARK::API::Account::Respondable::Balances
		*
		*   @method:	accountBalance(const Address &arkAddress)
		*   @parameter:		Address arkAddress
		*
		*   @outs:	ARK::API::Account::Gettable::balance(this->netConnector, arkAddress)
		*
		*   @description:
		*			Uses Ark Address to get an Accounts Confirmed
		*			and Unconfirmed Balances from a Node via API.
		* 
		**************************************************/
		ARK::API::Account::Respondable::Balances accountBalance(const Address &arkAddress)
		{
			return ARK::API::Account::Gettable::balance(this->netConnector, arkAddress);
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*
		*		@uri:	api/accounts/getPublickey?address=arkAddress
		*		@returnType:	Publickey
		*
		*   @method:	accountPublickey(const Address &arkAddress)
		*   @parameter:		Address arkAddress
		*
		*   @outs:	ARK::API::Account::Gettable::publickey(this->netConnector, arkAddress)
		*
		*   @description:
		*			Uses Ark Address to get an Accounts Publickey from a Node via API.
		* 
		**************************************************/
		Publickey accountPublickey(const Address &arkAddress)
		{
			return ARK::API::Account::Gettable::publickey(this->netConnector, arkAddress);
		};
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*
		*		@uri:	/api/accounts/delegates/fee?address=arkAddress
		*		@returnType:	Balance
		*
		*   @method:	accountDelegatesFee(const Address &arkAddress)
		*   @parameter:		Address arkAddress
		*
		*   @outs:	ARK::API::Account::Gettable::delegatesFee(this->netConnector, arkAddress)
		*
		*   @description:
		*			Uses Ark Address to get Delegate Registration Fee from a Node via API.
		* 
		**************************************************/
		Balance accountDelegatesFee(const Address &arkAddress)
		{
			return ARK::API::Account::Gettable::delegatesFee(this->netConnector, arkAddress);
		};
		/*************************************************/

/**************************************************************************************************/

	/*************************************************
	*
	*		@uri:	/api/accounts/delegates?address=arkAddress
	*		@returnType:	ARK::Delegate
	*
	*   @method:	ARK::Delegate accountDelegates(const Address &arkAddress)
	*   @parameter:		Address arkAddress
	*
	*   @outs:	ARK::API::Account::Gettable::delegates(this->netConnector, arkAddress)
	*
	*   @description:
	*			Uses Ark Address to get Delegate Object from a Node via API.
	* 
	**************************************************/
	ARK::Delegate accountDelegates(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::delegates(this->netConnector, arkAddress);
	};
	/*************************************************/

/**************************************************************************************************/

	/*************************************************
	*
	*		@uri:	/api/accounts?address=arkAddress
	*		@returnType:	ARK::Account
	*
	*   @method:	ARK::Account account(const Address &arkAddress)
	*   @parameter:	Address arkAddress
	*
	*   @outs:	ARK::API::Account::Gettable::account(this->netConnector, arkAddress)
	*
	*   @description:
	*			Uses Ark Address to get Account Object from a Node via API.
	* 
	**************************************************/
	ARK::Account account(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::account(this->netConnector, arkAddress);
	};
	/*************************************************/
};

/*************************************************/
};
};

#endif
