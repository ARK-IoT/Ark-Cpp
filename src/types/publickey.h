

#ifndef PUBLICKEY_H
#define PUBLICKEY_H
#pragma once

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/


/*************************************************
*
*
**************************************************/
struct publickey_t {

	private:

		static const auto PUBLICKEY_SIZE = 67;

	public:
		char value[PUBLICKEY_SIZE];

		publickey_t() : value() { };

		publickey_t(const char* const base64String) : value() {  
			strcpy(value, base64String);
		};

		publickey_t(const publickey_t& other) : value() {
			strcpy(value, other.value);
		}

		publickey_t& operator=(const publickey_t& other) {
			if (this != &other) {
				strcpy(value, other.value);
			}
			return *this;
		}

};
/*************************************************/

/*************************************************/
typedef publickey_t Publickey;
/*************************************************/


#endif
