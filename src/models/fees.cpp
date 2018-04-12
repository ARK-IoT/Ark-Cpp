

#include "models/fees.h"

#include <cstring>

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
Fees::Fees(
		const char *const newSend,
		const char *const newVote,
		const char *const newDelegate,
		const char *const newSS,
		const char *const newMS
)
{
	this->send_ = Balance(newSend);
	this->vote_ = Balance(newVote);
	this->delegate_ = Balance(newDelegate);
	this->secondsignature_ = Balance(newSS);
	this->multisignature_ = Balance(newMS);
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Fees::printTo(Print &p) const
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
/*************************************************/

};
