

#ifndef ACCOUNT_H
#define ACCOUNT_H

<<<<<<< HEAD
#include "address.h"
#include "balance.h"
#include "publickey.h"
#include "signature.h"
#include "platform.h"

#include <cstring>
#include <cstdio>

=======
>>>>>>> master
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
<<<<<<< HEAD

namespace ARK
{

/*************************************************
*   ARK::Account
**************************************************/
class Account :	public Printable {
private:
    Address address_;
    Balance unconfirmedBalance_;
    Balance balance_;
    Publickey publicKey_;
    int unconfirmedSignature_;
    int secondSignature_;
    Publickey secondPublicKey_;
    Signature multisignatures_;
    Signature u_multisignatures_;
    
public:
    Account(
        const char* const a, 
        const char* const ub,
        const char* const b,
        const char* const pk,
        int us,
        int ss,
        const char* const spk,
        const char* const ms,
        const char* const ums
    ) : 
		address_(a), 
		unconfirmedBalance_(ub), 
		balance_(b), 
		publicKey_(pk), 
		unconfirmedSignature_(us), 
		secondSignature_(ss), 
		secondPublicKey_(spk), 
		multisignatures_(ms), 
		u_multisignatures_(ums)
    { }

	const Address& address() const noexcept { return address_; }
	const Balance& unconfirmed_balance() const noexcept { return unconfirmedBalance_; }
	const Balance& balance() const noexcept { return balance_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	int unconfirmed_signature() const noexcept { return unconfirmedSignature_; }
	int second_signature() const noexcept { return secondSignature_; }
	const Publickey& second_public_key() const noexcept { return secondPublicKey_; }
	const Signature& multi_signatures() const noexcept { return multisignatures_; }
	const Signature& u_multi_signatures() const noexcept { return u_multisignatures_; }
	

    size_t printTo(Print& p) const override;
};
/*  ============  */
/*  ================================================  */

=======
namespace ARK
{
/*************************************************
*   ARK::account_t
**************************************************/
struct account_t
{
public:
	Address		address;
	Balance		unconfirmedBalance;
	Balance		balance;
	Publickey publicKey;
	int 			unconfirmedSignature;
	int 			secondSignature;
	Publickey secondPublicKey;
	Signature multisignatures;
	Signature u_multisignatures;
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
*   ARK::Account
**************************************************/
struct Account : public account_t, Printable
{

public:
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

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
>>>>>>> master
};

#endif
