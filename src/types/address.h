

#ifndef ADDRESS_H
#define ADDRESS_H

#include "utilities/platform.h"
#include <cstring>

/*******************************************************************************
* address: 
*	"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*	34 Characters | Base58-encoded
*	Size 272
*	160-bit base58Encoded hash from a RIPEME160 hash
********************************************************************************/

#define ADDRESS_CHARACTER_WIDTH 8
#define ADDRESS_LENGTH 34		/* Actual Length of Address */
#define ADDRESS_SIZE (ADDRESS_LENGTH * ADDRESS_CHARACTER_WIDTH)		/* Size: 272 (Length of Address * character width) */

/*************************************************
*	Address
**************************************************/
struct Address :
		public Printable
{
	protected:
		char value_[ADDRESS_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Address() : value_() {};
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		explicit Address(const char* const addressStr) : value_()
		{
			if (strlen(addressStr) * ADDRESS_CHARACTER_WIDTH == ADDRESS_SIZE)
			{
				strncpy(value_, addressStr, ADDRESS_LENGTH);
			}
		};
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		const char* getValue() const noexcept { return this->value_; }

		operator bool() const noexcept { return value_[0] != '\0'; }
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
/*************************************************/

#endif
