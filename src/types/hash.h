

#ifndef HASH_H
#define HASH_H

#include "utilities/platform.h"
#include <cstring>

/********************************************************************************
* hash: 
*	"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*	64 Characters | HEX-encoded
*	Size 256
********************************************************************************/

#define HASH_BIT_WIDTH 8
#define HASH_BIT_LENGTH 32
#define HASH_CHARACTER_WIDTH 4
#define HASH_CHARACTER_LENGTH 64	/* Actual Length of Address */
#define HASH_SIZE (HASH_CHARACTER_LENGTH * HASH_CHARACTER_WIDTH)	/* Size: 256 (Length of sha256 Hash * sha256 character width) */

struct Hash :
		public Printable
{
  private:
    char value_[HASH_CHARACTER_LENGTH + 1] = "\0";	/* (+ 1) for "\0"(null terminator) */

  public:
  	/*************************************************
		*	Constructor: Empty Default
		**************************************************/
    Hash() : value_() {}
    /*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
    Hash(const char* const hashStr) : value_()
    {
      if (strlen(hashStr) * HASH_CHARACTER_WIDTH == HASH_SIZE)
      {
				strncpy(value_, hashStr, HASH_CHARACTER_LENGTH);
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