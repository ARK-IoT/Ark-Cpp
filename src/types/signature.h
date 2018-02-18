

#ifndef SIGNATURE_H
#define SIGNATURE_H
#pragma once

/********************************************************************************
*
* signature: 
*   "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*   
*   142 Characters | ?-encoded
*
********************************************************************************/

#define SIGNATURE_SIZE 143



struct signature_t
{
	private:
		static const auto SIGNATURE_LENGTH = SIGNATURE_SIZE / sizeof(char);

	public:

    char value[SIGNATURE_LENGTH];

    signature_t() : value() {};

    signature_t(const char* const signatureString)
    {
      if ( signatureString == NULL )
      {        
        value[0] = { '\0' };
      }
      else
      {
        strncpy( value, signatureString, sizeof(value) / sizeof(value[0]) );
      }
    };

    signature_t& operator=(const signature_t& other) {
			if (this != &other) {
				strcpy(value, other.value);
			}
			return *this;
		};

};

typedef signature_t Signature;


#endif