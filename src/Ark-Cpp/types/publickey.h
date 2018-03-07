

#ifndef PUBLICKEY_H
#define PUBLICKEY_H

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/

typedef char PUBLIC_KEY_VALUE[66];

/*************************************************
*
**************************************************/
struct publickey_t :
		public ValuePrintable
{

	private:

		static const auto PUBLICKEY_SIZE = 67;
		char value_[PUBLICKEY_SIZE];

	public:

		publickey_t() : value_() {};

		publickey_t(const char* const base64String) : value_()
		{  
			if (strlen(base64String) < PUBLICKEY_SIZE - 1)
			{
				value_[0] = '\0';
			}
			else
			{
				strncpy(value_, base64String, sizeof(value_) / sizeof(value_[0]));
			}
		};

		publickey_t(const publickey_t& other) : value_()
		{
			strcpy(value_, other.value_);
		};

		publickey_t& operator=(const publickey_t& other)
		{
			if (this != &other)
			{
				strcpy(value_, other.value_);
			}
			return *this;
		};

    const char* getValue() const { return value_; };

};
/*************************************************/

/*************************************************/
typedef publickey_t Publickey;
/*************************************************/

#endif
