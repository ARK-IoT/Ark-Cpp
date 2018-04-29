

#ifndef TRANSACTIONABLE_HPP
#define TRANSACTIONABLE_HPP

#include "transaction_respondable.hpp"
#include "transaction_gettable.hpp"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Transactionable
*   	public Transaction::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Peer Model
**************************************************/
class Transactionable : public Transaction::Gettable,
												virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*		/api/transactions/get?id=
	*		@return:	ARK::Transaction
	*   @method:	transaction(Hash id)
	*   @param:	Hash id
	*   calls:	eturn ARK::API::Transaction::Gettable::transaction(this->netConnector, id)
	*
	*   @brief: Gets Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::Transaction transaction(Hash id)
	{
		return ARK::API::Transaction::Gettable::transaction(this->netConnector, id);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************/
	/*************************************************/
	/*    BROKEN: fix for large callbacks  */
	/*    Peers callback is ~28,908 bytes  */
	/*  /api/transactions  */
	// String transactions()
	// { return ARK::API::Transaction::Gettable::transactions(this->netConnector); };
	/*************************************************/
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/transactions/unconfirmed/get?id=
	*		@return:	const char*
	*   @method:	transactionUnconfirmed(Hash id)
	*   @param:	Hash id
	*   calls:	ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id)
	*
	*   @brief: Gets Unconfirmed Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(const Hash &id)
	{
		return ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/transactions/unconfirmed
	*		@return:	const char*
	*   @method:	transactionsUnconfirmed()
	*   calls: ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector, id)
	*
	*   @brief:	Gets Unconfirmed Transactions from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed()
	{
		return ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/transactions/get?id=
	*   @method:	getVendorField(Hash txID)
	*   @param:	Hash txID
	*   calls:	eturn ARK::API::Transaction::Gettable::transaction(this->netConnector, id)
	*
	*   @brief: Gets vendorField for a given Transaction by  txID from a Node via API.
	**************************************************/
	const char* getVendorField(Hash txID)
	{
		return ARK::API::Transaction::Gettable::vendorField(this->netConnector, txID);
	};

};
/*************************************************/

// namespace transaction_cb {
//   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
// };
};
};

#endif
