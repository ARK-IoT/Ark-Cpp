

#ifndef DESCRIBABLE_H
#define DESCRIBABLE_H

#include "valuable.h"

/*************************************************
* Describable
**************************************************/
class Describable : public Valuable, public Printable
{
  public:
		virtual size_t printTo(Print& p) const;
};
/*************************************************/

#endif
