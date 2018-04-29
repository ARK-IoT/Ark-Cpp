

#include "helpers.h"

/*************************************************
* Describable
**************************************************/
size_t Describable::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print(this->value_);
	return size;
}
/*************************************************/
