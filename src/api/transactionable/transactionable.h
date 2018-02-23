

#ifndef TRANSACTIONABLE_H
#define TRANSACTIONABLE_H

#include "transaction_respondable.h"
#include "transaction_gettable.h"

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
* 
**************************************************/
class Transactionable :
		public Transaction::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
  public:
	/*************************************************
		*		/api/transactions/get?id=
		*
		*		@uri:	/api/transactions/get?id=
		*		@returnType:	ARK::Transaction
		*
		*   @method:	transaction(Hash id)
    *   @parameters:
    *     Hash id
		*
		*   @outs:	eturn ARK::API::Transaction::Gettable::transaction(this->netConnector, id)
		*
		*   @description:
		*			Gets Transaction by Hash ID from a Node via API.
		* 
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
		*
		*		@uri:	/api/transactions/unconfirmed/get?id=
		*		@returnType:	const char*
		*
		*   @method:	transactionUnconfirmed(Hash id)
    *   @parameters:
    *     Hash id
		*
		*   @outs:	ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id)
		*
		*   @description:
		*			Gets Unconfirmed Transaction by Hash ID from a Node via API.
		* 
		**************************************************/
		ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(const Hash& id)
		{
			return ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/transactions/unconfirmed
		*
		*		@uri:	/api/transactions/unconfirmed
		*		@returnType:	const char*
		*
		*   @method:	transactionsUnconfirmed()
		*
		*   @outs:	ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector, id)
		*
		*   @description:
		*			Gets Unconfirmed Transactions from a Node via API.
		* 
		**************************************************/
		ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed()
		{
			return ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector);
		};
    /*************************************************/

};
    /*************************************************/

// namespace transaction_cb {
//   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};

#endif
