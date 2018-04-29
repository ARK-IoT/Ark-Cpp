

#ifndef VALUEABLE_H
#define VALUEABLE_H

/*************************************************
* Valueable
**************************************************/
class Valuable
{
protected:
	char value_[];

public:
	// Valuable();

	// Valuable(Valuable&& other);
	// Valuable & operator=(Valuable &&other);
	// Valuable &operator=(const Valuable &other);

	const char *getValue() const;
};
/*************************************************/

#endif
