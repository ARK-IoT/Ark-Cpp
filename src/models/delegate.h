

#ifndef DELEGATE_H
#define DELEGATE_H

#include "types/address.h"
#include "types/balance.h"
#include "types/publickey.h"
#include "utilities/platform.h"
#include <cstring>
#include <cstdio>

/********************************************************************************
* delegate: 
*		{  
*			"username": String,
*			"address":	Address,
*			"publicKey":	Publickey,
*			"vote":	Balance,
*			"producedblocks": uint,
*			"missedblocks":	uint,
*			"rate":	int,
*			"approval": double,
*			"productivity":	double
*		}
********************************************************************************/

namespace ARK
{
/*************************************************
*	ARK::Delegate
**************************************************/
struct Delegate :
		public Printable
{
	protected:
		char 			username_[20];
		Address 	address_;
		Publickey publicKey_;
		Balance 	vote_;
		int 			producedblocks_;
		int 			missedblocks_;
		int 			rate_;
		double 		approval_;
		double 		productivity_;

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Delegate(
				const char *const newUsername,
				const char *const newAddress,
				const char *const newPublicKey,
				const char *const newVote,
				int 							newProducedblocks,
				int 							newMissedblocks,
				int 							newRate,
				double 						newApproval,
				double 						newProductivity
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
		int rate() const noexcept { return rate_; }
		double approval() const noexcept { return approval_; }
		double productivity() const noexcept { return productivity_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

};

#endif
