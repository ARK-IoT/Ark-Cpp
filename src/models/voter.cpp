

#include "models/voter.h"

/*************************************************
*	Default Constructor
**************************************************/
ARK::Voter::Voter()
{
	strncpy(this->username_, "", sizeof(this->username_) / sizeof(this->username_[0]));
	this->address_ = Address("");
	this->publicKey_ = Publickey("");
	this->balance_ = Balance("0");
}
/*************************************************/

/*************************************************
*	Constructor
**************************************************/
ARK::Voter::Voter(
		const char *const newUsername,
		const char *const newAddress,
		const char *const newPublickey,
		const char *const newBalance
)
{
	strncpy(this->username_, newUsername, sizeof(this->username_) / sizeof(this->username_[0]));
	this->address_ = Address(newAddress);
	this->publicKey_ = Publickey(newPublickey);
	this->balance_ = Balance(newBalance);
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Voter::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nusername: ");
		size += p.print(this->username_);

		size += p.print("\naddress: ");
		size += p.print(this->address_);

		size += p.print("\npublicKey: ");
		size += p.print(this->publicKey_);

		size += p.print("\nbalance.ark: ");
		size += p.print(this->balance_.ark());
	return size;
}
/*************************************************/
