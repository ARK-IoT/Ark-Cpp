

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
    Address address;
    Balance unconfirmedBalance;
    Balance balance;
    Publickey publicKey;
    int unconfirmedSignature;
    int secondSignature;
    Publickey secondPublicKey;
    Signature multisignatures;
    Signature u_multisignatures;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Account
**************************************************/
struct Account :
		public account_t, Printable
{
	public:

		Account(
			const char* const newAddress,
			const char* const newUnconfirmedBalance,
			const char* const newBalance,
			const char* const newPublickey,
			int newUnconfirmedSignature,
			int newSecondSignature,
			const char* const newSecondPublickey,
			const char* const newMultisignatures,
			const char* const newU_Multisignatures
		)
		{
			address = Address(newAddress);
			unconfirmedBalance = Balance(newUnconfirmedBalance);
			balance = Balance(newBalance);
			publicKey = Publickey(newPublickey);
			unconfirmedSignature = newUnconfirmedSignature;
			secondSignature = newSecondSignature;
			secondPublicKey = Publickey(newSecondPublickey);
			multisignatures = Signature(newMultisignatures);
			u_multisignatures = Signature(newU_Multisignatures);
		}

		/*************************************************
		* 
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;

			size += p.print("address: ");
			size += p.print(address);

			size += p.print("\nunconfirmedBalance: ");
			size += p.print(this->unconfirmedBalance.ark());

			size += p.print("\nbalance: ");
			size += p.print(this->balance.ark());

			size += p.print("\npublicKey: ");
			size += p.print(this->publicKey);

			size += p.print("\nunconfirmedSignature: ");
			size += p.print(this->unconfirmedSignature);

			size += p.print("\nsecondSignature: ");
			size += p.print(this->secondSignature);

			size += p.print("\nsecondPublicKey: ");
			size += p.print(this->secondPublicKey);

			size += p.print("\nmultisignatures: ");
			size += p.print(this->multisignatures);

			size += p.print("\nu_multisignatures: ");
			size += p.print(this->u_multisignatures);

			return size;
		}
		/*************************************************/

};

};

#endif
