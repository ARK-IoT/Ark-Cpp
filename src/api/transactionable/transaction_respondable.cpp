

#include "api/transactionable/transaction_respondable.h"

namespace ARK
{
namespace API
{
namespace Transaction
{
namespace Respondable 
{

/*************************************************
*	Constructor
**************************************************/
Unconfirmed::Unconfirmed(
		const ARK::Transaction* const newTx,
		size_t newCount
)
{
	this->count_ = newCount;
	assert(this->count_ <= transactions_.size());
	for (unsigned int i = 0u; i < this->count_; ++i)
	{
		this->transactions_[i] = newTx[i];
	}
}
/*************************************************/

// /*************************************************
// *	  Deconstructor
// **************************************************/
// Unconfirmed::~Unconfirmed() { delete[] transactions_; }
// /*************************************************/

/*************************************************
*
**************************************************/
size_t Unconfirmed::printTo(Print &p) const
{
	size_t size = 0;

	if (this->count_ == 0)
	{
		size += p.print("There are currently no Unconfirmed Transactions");
	}
	else
	{
		for (unsigned int i = 0; i < this->count_; i++)
		{
			size += p.print("\ntransaction ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += p.print(this->transactions_[i]);
		};
	};
	return size;
};
/*************************************************/

};
};
};
};
