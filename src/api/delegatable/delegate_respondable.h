

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

#include "types/address.h"
#include "types/publickey.h"
#include "types/balance.h"
#include "models/voter.h"
#include "utilities/platform.h"

#include <array>
#include <memory>

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{
/*************************************************
*	ARK::API::Delegate::Respondable::search_t
*
*	@param: char[20]
*	@param: Address
*	@param: Publickey
*	@param: Balance
*	@param: int
*	@param: int
*
*	@brief:	Model for Delegate Search API Response
**************************************************/
struct search_t
{
	protected:
		char 			username_[20];
		Address 	address_;
		Publickey publicKey_;
		Balance 	vote_;
		int 			producedblocks_;
		int				missedblocks_;
};
/*************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::Search
*
*	@brief:	Model for Delegate Search API Response
**************************************************/
struct Search :
		public search_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Search(
				const char *const newUsername,
				const char *const newAddress,
				const char *const newPublickey,
				const char *const newVote,
				int								newProducedBlocks,
				int								newMissedBlocks
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const char* username() const noexcept { return username_; }
		const Address& address() const noexcept { return address_; }
		const Publickey& public_key() const noexcept { return publicKey_; }
		const Balance& vote() const noexcept { return vote_; }
		int produced_blocks() const noexcept { return producedblocks_; }
		int missed_blocks() const noexcept { return missedblocks_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/
	
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::Voters
*
*	@param:	size_t
*	@param:	ARK::Voter* const
*
*	@brief:	Model for Delegate Voters API Response
**************************************************/
struct Voters :
		public Printable
{

	private:
		size_t count_;
    std::unique_ptr<ARK::Voter[]> voters_;

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		explicit Voters(size_t c) : count_(c), voters_(new ARK::Voter[c]) {}
		/*************************************************/

		// /*************************************************
		// *	Deconstructor
		// **************************************************/
		// ~Voters();
		// /*************************************************/

		/*************************************************
		*
		**************************************************/
		const Voter &operator[](size_t index) const;
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		Voter &operator[](size_t index);
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::forged_by_account_t
*
*	@param:	const Balance
*	@param:	const Balance
*	@param:	const Balance
*
*	@brief:	Model for Delegate Forging Totals API Response
**************************************************/
struct forged_by_account_t
{
	protected:
		Balance fees_;
		Balance rewards_;
		Balance forged_;
};
/*************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::ForgedByAccount
*
*	@brief: Model for Delegate Forging Totals API Response
**************************************************/
struct ForgedByAccount :
		public forged_by_account_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		ForgedByAccount(
				const char *const newFees,
				const char *const newRewards,
				const char *const newForged
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const Balance& fees() const noexcept { return fees_; }
		const Balance& rewards() const noexcept { return rewards_; }
		const Balance& forged() const noexcept { return forged_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::next_forgers_t
*	@param: char currentBlock[64], char currentSlot[64], Publickey* const
*
*	@brief:	Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
struct next_forgers_t
{
	protected:
		int currentBlock_;
		int currentSlot_;
		std::array<Publickey, 10> delegate_keys_;
};
/*************************************************/

/*************************************************
*	ARK::API::Delegate::Respondable::NextForgers
*
*	@param: char[64]
*	@param: char[64]
*	@param:	Publickey* const
*
*	@brief:	Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
struct NextForgers :
		public next_forgers_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		NextForgers(
				int 	newCB,
				int 	newCS,
				const Publickey *const newDelegateKeys
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		int current_block() const noexcept { return currentBlock_; }
		int current_slot() const noexcept { return currentSlot_; }
		const std::array<Publickey, 10>& delegate_keys() const noexcept { return delegate_keys_; }
		/*************************************************/

		/*************************************************
		*
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
