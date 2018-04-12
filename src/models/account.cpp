

#include "models/account.h"

/*************************************************
*	Constructor
**************************************************/
ARK::Account::Account(
		const char *const newAddress,
		const char *const newUnconfirmedBalance,
		const char *const newBalance,
		const char *const newPublickey,
		int 							newUnconfirmedSignature,
		int 							newSecondSignature,
		const char *const newSecondPublickey,
		const char *const newMultisignatures,
		const char *const newU_Multisignatures
)
{
	address_ = Address(newAddress);
	unconfirmedBalance_ = Balance(newUnconfirmedBalance);
	balance_ = Balance(newBalance);
	publicKey_ = Publickey(newPublickey);
	unconfirmedSignature_ = newUnconfirmedSignature;
	secondSignature_ = newSecondSignature;
	secondPublicKey_ = Publickey(newSecondPublickey);
	multisignatures_ = Signature(newMultisignatures);
	u_multisignatures_ = Signature(newU_Multisignatures);
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Account::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("address: ");
		size += p.print(address_.getValue());

		size += p.print("\nunconfirmedBalance: ");
		size += p.print(this->unconfirmedBalance_.ark());

		size += p.print("\nbalance: ");
		size += p.print(this->balance_.ark());

		size += p.print("\npublicKey: ");
		size += p.print(this->publicKey_.getValue());

		size += p.print("\nunconfirmedSignature: ");
		size += p.print(this->unconfirmedSignature_);

		size += p.print("\nsecondSignature: ");
		size += p.print(this->secondSignature_);

		size += p.print("\nsecondPublicKey: ");
		size += p.print(this->secondPublicKey_.getValue());

		size += p.print("\nmultisignatures: ");
		size += p.print(this->multisignatures_.getValue());

		size += p.print("\nu_multisignatures: ");
		size += p.print(this->u_multisignatures_.getValue());
	return size;
}
/*************************************************/
