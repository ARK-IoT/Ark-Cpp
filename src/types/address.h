

#ifndef ADDRESS_H
#define ADDRESS_H
#pragma once

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

#define ADDRESS_SIZE 34

struct address_t
{
private:
	static const auto ADDRESS_LENGTH = ADDRESS_SIZE / sizeof(char);
	char value_[ADDRESS_LENGTH] = {'\0'};

public:
    address_t() { };

	address_t(const char* const addressString) : value_()
	{
        strncpy(value_, addressString, ADDRESS_LENGTH);
	}

	const char* const description() const { return value_; }
};

typedef address_t Address;

#endif