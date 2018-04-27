

#ifndef HASH_H
#define HASH_H

/********************************************************************************
* hash: 
*   "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*   64 Characters | HEX-encoded
*   Size 256
********************************************************************************/

#define HASH_BIT_WIDTH 8
#define HASH_BIT_LENGTH 32
#define HASH_CHARACTER_WIDTH 4
#define HASH_CHARACTER_LENGTH 64		/* Actual Length of Address */
#define HASH_SIZE (HASH_CHARACTER_LENGTH * HASH_CHARACTER_WIDTH)		/* Size: 256 (Length of sha256 Hash * sha256 character width) */

struct Hash :
		public Describable
{
  private:
    char value_[HASH_CHARACTER_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

  public:

    Hash();
    Hash(const char* const hashStr);

};

#endif