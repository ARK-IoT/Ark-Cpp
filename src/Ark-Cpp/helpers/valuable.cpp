

#include "helpers.h"

	// Valuable::Valuable(){};

	// Valuable::Valuable(Valuable&& other)
	// {
	// 	strcpy(this->value_, other.value_);
	// };
	
	// Valuable & Valuable::operator=(Valuable &&other)
	// {
	// 	if (this != &other)
	// 		strcpy(this->value_, other.value_);
	// 	return *this;
	// };

	// Valuable &Valuable::operator=(const Valuable &other)
	// {
	// 	if (this != &other)
	// 		strcpy(this->value_, other.value_);
	// 	return *this;
	// };

	const char *Valuable::getValue() const { return this->value_; };
