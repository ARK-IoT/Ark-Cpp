

#include "api/delegatable/delegate_respondable.h"

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{
/*************************************************
*	Constructor
**************************************************/
Search::Search(
	const char *const newUsername,
	const char *const newAddress,
	const char *const newPublickey,
	double newVote,
	int newProducedBlocks,
	int newMissedBlocks
) : 
	address_(Address(newAddress)),
	publicKey_(Publickey(newPublickey)),
	vote_(Balance(newVote)),
	producedblocks_(newProducedBlocks),
	missedblocks_(newMissedBlocks)
{
	strncpy(this->username_, newUsername, sizeof(username_) / sizeof(username_[0]));
}

/*************************************************
*
**************************************************/
size_t Search::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nusername: ");
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
	return size;
};
/*************************************************/

/**************************************************************************************************/

// /*************************************************
// *	Deconstructor
// **************************************************/
// Voters::~Voters() { delete[] voters_; }
// /*************************************************/


/*************************************************
*
**************************************************/
const Voter &Voters::operator[](size_t index) const { return voters_[index]; }
/*************************************************/

/*************************************************
*
**************************************************/
Voter &Voters::operator[](size_t index) { return voters_[index]; }
/*************************************************/

/*************************************************
*	
**************************************************/
size_t Voters::printTo(Print &p) const
{
	size_t size = 0;
	if (this->count_ > 0)
	{
		size += p.print("\n\0");

		for (int i = 0; i < static_cast<int>(this->count_); i++)
		{
			size += p.print("\nvoter ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += p.print(voters_[i].printTo(p));
			size += p.print("\n");
		};
	};
	return size;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	Constructor
**************************************************/
ForgedByAccount::ForgedByAccount(
		double newFees,
		double newRewards,
		double newForged
)
{
	this->fees_ = Balance(newFees);
	this->rewards_ = Balance(newRewards);
	this->forged_ = Balance(newForged);
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t ForgedByAccount::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("fees: ");
		size += p.print(this->fees_.getValue());
		size += p.print("\nrewards: ");
		size += p.print(this->rewards_.getValue());
		size += p.print("\nforged: ");
		size += p.print(this->forged_.getValue());
	return size;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	Constructor
**************************************************/
NextForgers::NextForgers(
		int newCB,
		int newCS,
		const Publickey *const newDelegateKeys
)
{
	this->currentBlock_ = newCB;
	this->currentSlot_ = newCS;
	for (auto i = 0; i < 10; ++i)
	{
		this->delegate_keys_[i] = newDelegateKeys[i];
	};
}
/*************************************************/

/*************************************************
*	Constructor
**************************************************/
size_t NextForgers::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("currentBlock: ");
	size += p.print(this->currentBlock_);
	size += p.print("\ncurrentSlot: ");
	size += p.print(this->currentSlot_);

	for (int i = 0; i < 9; i++)
	{
		size += p.print("\ndelegate #");
		size += p.print(i + 1);
		size += p.print(" publicKey: ");
		size += p.print(delegate_keys_[i].printTo(p));
	};
	return size;
};
/*************************************************/

};
};
};
};
