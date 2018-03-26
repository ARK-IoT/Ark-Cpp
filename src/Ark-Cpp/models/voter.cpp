

#include "models.h"

ARK::Voter::Voter()
{
	strncpy(this->username, "", sizeof(this->username) / sizeof(this->username[0]));
	this->address = Address("");
	this->publicKey = Publickey("");
	this->balance = Balance("0");
};

ARK::Voter::Voter(
		const char *const newUsername,
		const char *const newAddress,
		const char *const newPublickey,
		const char *const newBalance
)
{
	strncpy(this->username, newUsername, sizeof(this->username) / sizeof(this->username[0]));
	this->address = Address(newAddress);
	this->publicKey = Publickey(newPublickey);
	this->balance = Balance(newBalance);
};

/*************************************************
*
**************************************************/
size_t ARK::Voter::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("\nusername: ");
	size += p.print(this->username);

	size += p.print("\naddress: ");
	size += p.print(this->address);

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey);

	size += p.print("\nbalance.ark: ");
	size += p.print(this->balance.ark());
	return size;
}
/*************************************************/
