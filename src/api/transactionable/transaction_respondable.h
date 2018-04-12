

#ifndef TRANSACTION_RESPONDABLE_H
#define TRANSACTION_RESPONDABLE_H

#include "utilities/platform.h"
#include "models/transaction.h"

#include <array>
#include <cassert>

namespace ARK
{
namespace API
{
namespace Transaction
{
namespace Respondable
{
/*************************************************
*	ARK::API::Transaction::Respondable::Unconfirmed
*
*	@param: bool loaded
*	@param:	int now
*	@param:	char blocksCont[64]
*
*	@brief: Model for Loader Status API Response
**************************************************/
struct Unconfirmed :
		public Printable
{
	private:
		size_t count_;
		std::array<ARK::Transaction, 5> transactions_;

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Unconfirmed(
				const ARK::Transaction *const newTX,
				size_t newCount
		);
		/*************************************************/

		// /*************************************************
		// *	Deconstructor
		// **************************************************/
		// ~Unconfirmed();
		// /*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const std::array<ARK::Transaction, 5>& transactions() const noexcept { return transactions_; }
		size_t count() const noexcept { return count_; }
		/*************************************************/

		/*************************************************
		*	ARK::API::Transaction::Respondable::Unconfirmed 
		*
		*	@param:	Print &p
		*
		*	@brief: Prints API Transaction Unconfirmed Response to Serial
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

};
};
};
};

#endif
