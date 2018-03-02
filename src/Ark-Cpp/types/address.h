

#ifndef ADDRESS_H
#define ADDRESS_H

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
struct address_t :
		public ValuePrintable
{
	private:

		static const auto ADDRESS_LENGTH = ADDRESS_SIZE / sizeof(char);
		char value_[ADDRESS_LENGTH];

	public:

		address_t() : value_() {};

		address_t(const char* const addressString) : value_()
		{
			if (strlen(addressString) < ADDRESS_LENGTH - 1)
			{
        value_[0] = '\0';
      }
      else
			{
        strncpy(value_, addressString, sizeof(value_) / sizeof(value_[0]));
      };
		};

	const char* getValue() const { return value_; };

};
/*************************************************/

/*************************************************
*   Address
**************************************************/
typedef address_t Address;

#endif