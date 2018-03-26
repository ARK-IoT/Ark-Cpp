

#ifndef PUBLICKEY_H
#define PUBLICKEY_H

/********************************************************************************
*	Publickey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   66 Characters | Base64-encoded
********************************************************************************/

#define PUBLICKEY_CHARACTER_WIDTH 8
#define PUBLICKEY_LENGTH 66		/* Actual Length of Address */
#define PUBLICKEY_SIZE (PUBLICKEY_LENGTH * PUBLICKEY_CHARACTER_WIDTH)		/* Size: 528 (Length of Publickey * character width) */

/*************************************************
*
**************************************************/
struct Publickey :
		public Describable
{
	private:
		char value_[PUBLICKEY_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

	public:

		Publickey();

		Publickey(const char* const pubkeyStr);

};
/*************************************************/

#endif
