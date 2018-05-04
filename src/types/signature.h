

#ifndef SIGNATURE_H
#define SIGNATURE_H

#include "utilities/platform.h"
#include <cstring>

/********************************************************************************
* Signature: 
*	"3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*	142 Characters | ?-encoded
********************************************************************************/

#define SIGNATURE_CHARACTER_WIDTH 8
#define SIGNATURE_LENGTH 142	/* Actual Length of Signature */
#define SIGNATURE_SIZE (SIGNATURE_LENGTH * SIGNATURE_CHARACTER_WIDTH)	/* Size: (Length of Signature * character width) */

struct Signature :
		public Printable
{
	private:
		char value_[SIGNATURE_LENGTH + 1];	/* (+ 1) for "\0"(null terminator) */

	public:
		/*************************************************
		*	Constructor: Empty Default
		**************************************************/
		Signature() : value_() {};
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		Signature(const char* const signatureStr) : value_()
		{
			if (strlen(signatureStr) == SIGNATURE_LENGTH)
			{
				strncpy(this->value_, signatureStr, SIGNATURE_LENGTH);
				strcat(this->value_, "\0");
			}
			else
			{
				this->value_[0] = '\0';
			}
		};
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		const char* getValue() const noexcept { return this->value_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			size += p.print(this->value_);
			return size;
		};
		/*************************************************/

};

#endif
