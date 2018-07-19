

#ifndef PUBLICKEY_H
#define PUBLICKEY_H

#include "utilities/platform.h"
#include <cstring>
#include <cassert>

/********************************************************************************
*	Publickey: 
*	"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*	66 Characters | Base64-encoded
********************************************************************************/

#define PUBLICKEY_CHARACTER_WIDTH 8
#define PUBLICKEY_LENGTH 66		/* Actual Length of Address */
#define PUBLICKEY_SIZE (PUBLICKEY_LENGTH * PUBLICKEY_CHARACTER_WIDTH)		/* Size: 528 (Length of Publickey * character width) */

/*************************************************
*
**************************************************/
struct Publickey :
		public Printable
{
	private:
		char value_[PUBLICKEY_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

	public:
		/*************************************************
		*	Constructor: Empty Default
		**************************************************/
		Publickey() : value_() {};
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		Publickey(const char* const pubkeyStr) : value_()
		{
			assert(std::strlen(pubkeyStr) <= sizeof(value_));
			//if (strlen(pubkeyStr) * PUBLICKEY_CHARACTER_WIDTH == PUBLICKEY_SIZE)
			//{
				strncpy(value_, pubkeyStr, PUBLICKEY_LENGTH + 1);
			//}
		};
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		const char* getValue() const noexcept { return this->value_; }
		/*************************************************/

		operator bool() const noexcept { return value_[0] == '\0'; }

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
