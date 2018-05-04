

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
		const char *const newSecondPublickey//,
		// Hash							newMultisignatures[],		//	FIXME
		// Hash							newU_Multisignatures[]	//	FIXME
) :
		address_(Address(newAddress)),
		unconfirmedBalance_(Balance(newUnconfirmedBalance)),
		balance_(Balance(newBalance)),
		publicKey_(Publickey(newPublickey)),
		unconfirmedSignature_(newUnconfirmedSignature),
		secondSignature_(newSecondSignature),
		secondPublicKey_(Publickey(newSecondPublickey)) {}
	// int msigSize = round(newMultisignatures.size() / sizeof(Hash));
	// this->multisignatures_ = new Hash[msigSize];
	// for (unsigned int i = 0; i <= msigSize; i++)
	// {
	// 	this->multisignatures_[i] = newMultisignatures[i];
	// }

	// int u_msigSize = round(newU_Multisignatures.size() / sizeof(Hash));
	// this->u_multisignatures_ = new Hash[u_msigSize];
	// for (unsigned int i = 0; i <= u_msigSize; i++)
	// {
	// 	this->u_multisignatures_[i] = newU_Multisignatures[i];
	// }
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

		// size += p.print("\nmultisignatures: ");
		// 	for (unsigned int i = 0; i <= (sizeof(this->u_multisignatures_) / sizeof(Hash)); i++)
		// 	{
		// 		size += p.print(this->multisignatures_[i].getValue());
		// 	}

		// size += p.print("\nu_multisignatures: ");
		// 	for (unsigned int i = 0; i <= (sizeof(this->u_multisignatures_) / sizeof(Hash)); i++)
		// 	{
		// 		size += p.print(this->u_multisignatures_[i].getValue());
		// 	}

	return size;
}
/*************************************************/
