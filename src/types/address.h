

#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring>

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

class Address {
private:
	static const auto ADDRESS_SIZE = 34 + 1;  // +1 for nul terminiator
	static const auto ADDRESS_LENGTH = ADDRESS_SIZE / sizeof(char);
	char value_[ADDRESS_LENGTH];

public:
    Address() : value_() { };

	explicit Address(const char* const addressString) : value_()
	{
        strncpy(value_, addressString, ADDRESS_LENGTH);
	}

	const char* getValue() const { return value_; }
};

#endif