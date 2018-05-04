

#ifndef TRANSACTIONABLE_H
#define TRANSACTIONABLE_H

#include "api/transactionable/transaction_respondable.h"
#include "api/transactionable/transaction_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Transactionable
*	public Transaction::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Peer Model
**************************************************/
class Transactionable :
		public Transaction::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*	/api/transactions/get?id=
	*
	*	@method:	transaction(Hash id)
	*	@return:	ARK::Transaction
	*	@param:	Hash id
	*
	*	@brief: Gets Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::Transaction transaction(Hash id)
	{
		return ARK::API::Transaction::Gettable::transaction(this->netConnector, id);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************/
	/*************************************************/
	/*	BROKEN: fix for large callbacks  */
	/*	Peers callback is ~28,908 bytes  */
	/*  /api/transactions  */
	// String transactions()
	// { return ARK::API::Transaction::Gettable::transactions(this->netConnector); };
	/*************************************************/
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*	/api/transactions/unconfirmed/get?id=
	*
	*	@method:	transactionUnconfirmed(Hash id)
	*	@return:	const char*
	*	@param:	Hash id
	*
	*	@brief: Gets Unconfirmed Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(const Hash &id)
	{
		return ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*	/api/transactions/unconfirmed
	*
	*	@method:	transactionsUnconfirmed()
	*	@return:	const char*
	*
	*	@brief:	Gets Unconfirmed Transactions from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed()
	{
		return ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*	/api/transactions/get?id=
	*
	*	@method:	getVendorField(Hash txID)
	*	@param:	Hash txID
	*
	*	@brief: Gets vendorField for a given Transaction by  txID from a Node via API.
	**************************************************/
	const char *getVendorField(Hash txID)
	{
		return ARK::API::Transaction::Gettable::vendorField(this->netConnector, txID);
	};
	/*************************************************/

};
/*************************************************/

};
};

#endif
