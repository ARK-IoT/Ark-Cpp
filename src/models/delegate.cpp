

#include "models/delegate.h"

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
ARK::Delegate::Delegate(
		const char *const newUsername,
		const char *const newAddress,
		const char *const newPublicKey,
		double newVote,
		int 							newProducedblocks,
		int 							newMissedblocks,
		int 							newRate,
		double 						newApproval,
		double 						newProductivity
)	:
		address_(Address(newAddress)),
		publicKey_(Publickey(newPublicKey)),
		vote_(Balance(newVote)),
		producedblocks_(newProducedblocks),
		missedblocks_(newMissedblocks),
		rate_(newRate),
		approval_(newApproval),
		productivity_(newProductivity)
{
	strncpy(this->username_, newUsername, sizeof(username_) / sizeof(username_[0]));
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Delegate::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("username: ");
		size += p.print(this->username_);

		size += p.print("\naddress: ");
		size += p.print(this->address_.getValue());

		size += p.print("\npublicKey: ");
		size += p.print(this->publicKey_.getValue());

		size += p.print("\nvote: ");
		size += p.print(this->vote_.getValue());

		size += p.print("\nproducedblocks: ");
		size += p.print(this->producedblocks_);

		size += p.print("\nmissedblocks: ");
		size += p.print(this->missedblocks_);

		size += p.print("\nrate: ");
		size += p.print(this->rate_);

		size += p.print("\napproval: ");
		size += p.print(this->approval_);

		size += p.print("%\nproductivity: ");
		size += p.print(this->productivity_);
		size += p.print("%");
	return size;
}
/*************************************************/

};
