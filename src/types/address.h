

#ifndef ADDRESS_H
#define ADDRESS_H
#pragma once

/*******************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

#define ADDRESS_SIZE 35

/*************************************************
*   address_t
**************************************************/
struct address_t
{
	private:
		static const auto ADDRESS_LENGTH = ADDRESS_SIZE / sizeof(char);

	public:
		char value[ADDRESS_LENGTH];

		address_t() : value() { };

		address_t(const char* const addressString) : value()
		{
			strcpy(value, addressString);
		}

};
/*************************************************/


/*************************************************
*   Address
**************************************************/
typedef address_t Address;


#endif