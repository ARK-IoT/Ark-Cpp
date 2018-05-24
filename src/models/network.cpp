

#include "models/network.h"

/*************************************************
*	Constructor
**************************************************/
ARK::Network::Network(
		const char *const newNethash,
		const char *const newToken,
		const char *const newSymbol,
		const char *const newExplorer,
		int 							newVersion
)	:
	nethash_(newNethash),
	token_(),
	symbol_(),
	explorer_(),
	version_(newVersion)
{
	strcpy(this->token_, newToken);
	for (unsigned int i = 0; i < strlen(newSymbol); i++)
	{
		( sizeof(newSymbol[i]) == sizeof(char) )
				? ( this->symbol_[i] = newSymbol[i] )
				: ( sprintf(this->symbol_, "%2c", newSymbol[i]) );
	}
	strcpy(this->explorer_, newExplorer);
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Network::printTo(Print &p) const
{
	size_t size = 0;

	size += p.print("nethash: ");
	size += p.print(this->nethash_.getValue());

	size += p.print("\ntoken: ");
	size += p.print(this->token_);

	size += p.print("\nsymbol: ");
	size += p.print(this->symbol_);

	size += p.print("\nexplorer: ");
	size += p.print(this->explorer_);

	size += p.print("\nversion: ");
	size += p.print(this->version_);

	return size;
}
/*************************************************/

/*************************************************
*	ARK::Network::Network::operator==
*
*	@brief:	Comparison of two Network Models for equality.
**************************************************/
bool ARK::Network::Network::operator==(const Network &rhs) const
{
	return (
		strcmp(this->nethash_.getValue(), rhs.nethash().getValue()) == 0
			&& strcmp(this->token_, rhs.token()) == 0 && strcmp(this->symbol_, rhs.symbol()) == 0
			&& strcmp(this->explorer_, rhs.explorer()) == 0
			&& this->version_ == rhs.version()
	);
};
/*************************************************/

/*************************************************
*	ARK::Network::Network::operator!=
*
*	@brief:	Comparison of two Network Models for inequality.
**************************************************/
bool ARK::Network::Network::operator!=(const Network &rhs) const { return !(*this == rhs); };
/*************************************************/
