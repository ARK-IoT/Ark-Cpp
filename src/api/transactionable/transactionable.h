

#ifndef TRANSACTIONABLE_H
#define TRANSACTIONABLE_H

#include "transaction_respondable.h"
#include "transaction_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  =================================  */
/*  PUBLIC: ARK::API::Transactionable  */
class Transactionable :
		public Transaction::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
  public:
/*  ==========================================================================  */
		/*  /api/transactions/get?id=  */
		ARK::Transaction transaction(Hash _id)
		{
			return ARK::API::Transaction::Gettable::transaction(this->netConnector, _id);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
		/*    BROKEN: fix for large callbacks  */
		/*    Peers callback is ~28,908 bytes  */
		/*  /api/transactions  */
		// String transactions()
		// { return ARK::API::Transaction::Gettable::transactions(this->netConnector); };
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/transactions/unconfirmed/get?id=  */
		String transactionUnconfirmed(Hash _id)
		{
			return ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, _id);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/transactions/unconfirmed/  */
		String transactionsUnconfirmed()
		{
			return ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector);
		};
/*  ==========================================================================  */

};
/*  =================================  */
/*  ==========================================================================  */

// namespace transaction_cb {
//   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};

#endif
