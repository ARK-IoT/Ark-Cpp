#include "models/voter.h"


ARK::Voter::Voter(
		const char* const u, 
		const char* const a, 
		const char* const pk,
		double b
) : username_(), address_(a), publicKey_(pk), balance_(b)
{
	strncpy(username_, u, sizeof(username_) / sizeof(username_[0]));
}

size_t ARK::Voter::printTo(Print& p) const 
{
	size_t size = 0;

	size += p.print("\nusername: ");
	size += p.print(this->username_);

	size += p.print("\naddress: ");
	size += p.print(this->address_.getValue());

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey_.getValue());

	size += p.print("\nbalance.ark: ");
	size += p.print(this->balance_.getValue());

	return size;
}