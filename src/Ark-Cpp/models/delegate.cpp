

#include "models.h"

ARK::Delegate::Delegate(
		const char *const newUsername,
		const char *const newAddress,
		const char *const newPublicKey,
		const char *const newVote,
		int 							newProducedblocks,
		int 							newMissedblocks,
		int 							newRate,
		double 						newApproval,
		double 						newProductivity
)
{
	strncpy(username, newUsername, sizeof(username) / sizeof(username[0]));
	address = Address(newAddress);
	publicKey = Publickey(newPublicKey);
	vote = Balance(newVote);
	producedblocks = newProducedblocks;
	missedblocks = newMissedblocks;
	rate = newRate;
	approval = newApproval;
	productivity = newProductivity;
}

/*************************************************
*
**************************************************/
size_t ARK::Delegate::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("username: ");
	size += p.print(this->username);

	size += p.print("\naddress: ");
	size += p.print(this->address);

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey);

	size += p.print("\nvote: ");
	size += p.print(this->vote.ark());

	size += p.print("\nproducedblocks: ");
	size += p.print(this->producedblocks);

	size += p.print("\nmissedblocks: ");
	size += p.print(this->missedblocks);

	size += p.print("\nrate: ");
	size += p.print(this->rate);

	size += p.print("\napproval: ");
	size += p.print(this->approval);

	size += p.print("%\nproductivity: ");
	size += p.print(this->productivity);
	size += p.print("%");
	return size;
}
/*************************************************/