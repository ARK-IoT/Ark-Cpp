

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "types/address.h"
#include "types/balance.h"
#include "types/publickey.h"
#include "types/signature.h"
#include "utilities/platform.h"

#include <cstring>
#include <cstdio>

/********************************************************************************
*
* account: 
*    {  
*      "success":true,
*      "account":{  
*         "address":  Address,
*         "unconfirmedBalance": Balance,
*         "balance":  Balance,
*         "publicKey":  Publickey,
*         "unconfirmedSignature": int,
*         "secondSignature":  int,
*         "secondPublicKey":  Publickey,
*         "multisignatures":  [ Signature ],
*         "u_multisignatures":  [ Signature ]
*      }
*    }
*
********************************************************************************/
namespace ARK
{
/*************************************************
*   ARK::account_t
**************************************************/
struct account_t
{
	protected:
		Address		address_;
		Balance		unconfirmedBalance_;
		Balance		balance_;
		Publickey	publicKey_;
		int				unconfirmedSignature_;
		int				secondSignature_;
		Publickey	secondPublicKey_;
		Signature	multisignatures_;
		Signature	u_multisignatures_;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Account
**************************************************/
struct Account :
		public account_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Account(
				const char *const newAddress,
				const char *const newUnconfirmedBalance,
				const char *const newBalance,
				const char *const newPublickey,
				int 							newUnconfirmedSignature,
				int 							newSecondSignature,
				const char *const newSecondPublickey,
				const char *const newMultisignatures,
				const char *const newU_Multisignatures
		);
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		const Address& address() const noexcept { return address_; }
		const Balance& unconfirmed_balance() const noexcept { return unconfirmedBalance_; }
		const Balance& balance() const noexcept { return balance_; }
		const Publickey& public_key() const noexcept { return publicKey_; }
		int unconfirmed_signature() const noexcept { return unconfirmedSignature_; }
		int second_signature() const noexcept { return secondSignature_; }
		const Publickey& second_public_key() const noexcept { return secondPublicKey_; }
		const Signature& multi_signatures() const noexcept { return multisignatures_; }
		const Signature& u_multi_signatures() const noexcept { return u_multisignatures_; }
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
