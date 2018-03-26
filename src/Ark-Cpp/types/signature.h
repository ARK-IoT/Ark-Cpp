

#ifndef SIGNATURE_H
#define SIGNATURE_H

/********************************************************************************
* Signature: 
*   "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*   142 Characters | ?-encoded
********************************************************************************/

#define SIGNATURE_CHARACTER_WIDTH 8
#define SIGNATURE_LENGTH 142		/* Actual Length of Signature */
#define SIGNATURE_SIZE (SIGNATURE_LENGTH * SIGNATURE_CHARACTER_WIDTH)		/* Size: (Length of Signature * character width) */

struct signature_t :
		public Describable
{
	private:
		char value_[SIGNATURE_LENGTH + 1] = "\0";		/* (+ 1) for "\0"(null terminator) */

	public:

		signature_t();
		signature_t(const char* const signatureStr);

};

typedef signature_t Signature;

#endif
