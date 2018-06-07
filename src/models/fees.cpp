

#include "models/fees.h"

namespace ARK
{
/*************************************************
*	Constructor
**************************************************/
Fees::Fees(
		double newSend,
		double newVote,
		double newDelegate,
		double newSS,
		double newMS
)	:
		send_(Balance(newSend)),
		vote_(Balance(newVote)),
		delegate_(Balance(newDelegate)),
		secondsignature_(Balance(newSS)),
		multisignature_(Balance(newMS)) {}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Fees::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nsend: ");
		size += p.print(this->send_.getValue());

		size += p.print("\nvote: ");
		size += p.print(this->vote_.getValue());

		size += p.print("\ndelegate: ");
		size += p.print(this->delegate_.getValue());

		size += p.print("\nsecondsignature: ");
		size += p.print(this->secondsignature_.getValue());

		size += p.print("\nmultisignature: ");
		size += p.print(this->multisignature_.getValue());
	return size;
}
/*************************************************/

};
