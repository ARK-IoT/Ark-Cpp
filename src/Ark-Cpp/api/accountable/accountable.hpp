

#ifndef ACCOUNTABLE_HPP
#define ACCOUNTABLE_HPP

#include "account_respondable.hpp"
#include "account_gettable.hpp"

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
**************************************************/
class Accountable : public Account::Gettable,
										virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*		/api/accounts/getBalance?address=arkAddress
	*		@return:	ARK::API::Account::Respondable::Balances
	*   accountBalance(const Address &arkAddress)
	*   @param:	Address arkAddress
	*   calls:	ARK::API::Account::Gettable::balance(this->netConnector, arkAddress)
	*
	*   @brief:	Uses Ark Address to get an Accounts Confirmed	and Unconfirmed Balances from a Node via API.
	**************************************************/
	ARK::API::Account::Respondable::Balances accountBalance(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::balance(this->netConnector, arkAddress);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		api/accounts/getPublickey?address=arkAddress
	*		@return:	Publickey
	*   accountPublickey(const Address &arkAddress)
	*   @param:	Address arkAddress
	*   calls:	ARK::API::Account::Gettable::publickey(this->netConnector, arkAddress)
	*
	*   @brief:	Uses Ark Address to get an Accounts Publickey from a Node via API.
	**************************************************/
	Publickey accountPublickey(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::publickey(this->netConnector, arkAddress);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/accounts/delegates/fee?address=arkAddress
	*		@return:	Balance
	*   accountDelegatesFee(const Address &arkAddress)
	*   @param:	Address arkAddress
	*   calls:	ARK::API::Account::Gettable::delegatesFee(this->netConnector, arkAddress)
	*
	*   @brief:	Uses Ark Address to get Delegate Registration Fee from a Node via API.
	**************************************************/
	Balance accountDelegatesFee(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::delegatesFee(this->netConnector, arkAddress);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/accounts/delegates?address=arkAddress
	*		@return:	ARK::Delegate
	*   ARK::Delegate accountDelegates(const Address &arkAddress)
	*   @param:	Address arkAddress
	*   calls:	ARK::API::Account::Gettable::delegates(this->netConnector, arkAddress)
	*
	*   @brief:	Uses Ark Address to get Delegate Object from a Node via API.
	**************************************************/
	ARK::Delegate accountDelegates(const Address &arkAddress)
	{
		return ARK::API::Account::Gettable::delegates(this->netConnector, arkAddress);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/accounts?address=arkAddress
	*		@return:	ARK::Account
	*   ARK::Account account(const Address &arkAddress)
	*   @param:	Address arkAddress
	*   calls:	ARK::API::Account::Gettable::account(this->netConnector, arkAddress)
	*
	*   @brief:	Uses Ark Address to get Account Object from a Node via API.
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
