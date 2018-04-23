<<<<<<< HEAD
#include "fees.h"

#include <cstring>

namespace ARK {

size_t Fees::printTo(Print& p) const
{
    size_t size = 0;

    size += p.print("\nsend: ");
    size += p.print(this->send_.ark());

    size += p.print("\nvote: ");
    size += p.print(this->vote_.ark());

    size += p.print("\ndelegate: ");
    size += p.print(this->delegate_.ark());

    size += p.print("\nsecondsignature: ");
    size += p.print(this->secondsignature_.ark());

    size += p.print("\nmultisignature: ");
    size += p.print(this->multisignature_.ark());
    
    return size;
}


}
=======


#include "models.h"

ARK::Fees::Fees(
		const char *const newSend,
		const char *const newVote,
		const char *const newDelegate,
		const char *const newSS,
		const char *const newMS
)
{
	this->send = Balance(newSend);
	this->vote = Balance(newVote);
	this->delegate = Balance(newDelegate);
	this->secondsignature = Balance(newSS);
	this->multisignature = Balance(newMS);
};

/*************************************************
*
**************************************************/
size_t ARK::Fees::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nsend: ");
		size += p.print(this->send.ark());

		size += p.print("\nvote: ");
		size += p.print(this->vote.ark());

		size += p.print("\ndelegate: ");
		size += p.print(this->delegate.ark());

		size += p.print("\nsecondsignature: ");
		size += p.print(this->secondsignature.ark());

		size += p.print("\nmultisignature: ");
		size += p.print(this->multisignature.ark());
	return size;
}
/*************************************************/
>>>>>>> master
