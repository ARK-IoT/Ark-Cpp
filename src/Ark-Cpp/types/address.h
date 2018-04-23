

#ifndef ADDRESS_H
#define ADDRESS_H

/*******************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*		Size 272
*		160-bit base58Encoded hash from a RIPEME160 hash
********************************************************************************/

#define ADDRESS_CHARACTER_WIDTH 8
#define ADDRESS_LENGTH 34		/* Actual Length of Address */
#define ADDRESS_SIZE (ADDRESS_LENGTH * ADDRESS_CHARACTER_WIDTH)		/* Size: 272 (Length of Address * character width) */

/*************************************************
*   Address
**************************************************/
struct Address
		:  public Describable
{
	protected:
		char value_[ADDRESS_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

	public:

		Address();
		explicit Address(const char* const addressStr);

};
/*************************************************/

#endif
