

#ifndef VOTER_H
#define VOTER_H

#include "types/address.h"
#include "types/balance.h"
#include "types/publickey.h"
#include "utilities/platform.h"

#include <cstring>

namespace ARK
{
/*************************************************
*	ARK::voter_t
**************************************************/
struct voter_t
{
	protected:
		char 			username_[20];
		Address 	address_;
		Publickey publicKey_;
		Balance 	balance_;
};
/*************************************************/

/*************************************************
*	ARK::Voter
**************************************************/
struct Voter :
		public voter_t,
		Printable
{
	public:
		/*************************************************
		*	Default: Empty Constructor
		**************************************************/
		Voter();
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		Voter(
				const char *const newUsername,
				const char *const newAddress,
				const char *const newPublickey,
				const char *const newBalance
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const char *username() const noexcept { return username_; }
		const Address& address() const noexcept { return address_; }
		const Publickey& public_key() const noexcept { return publicKey_; }
		const Balance& balance() const noexcept { return balance_; }
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
