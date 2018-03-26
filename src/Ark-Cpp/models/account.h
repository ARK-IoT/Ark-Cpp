

#ifndef ACCOUNT_H
#define ACCOUNT_H

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
};

#endif
