

#ifndef DESCRIBABLE_H
#define DESCRIBABLE_H

#ifdef ARDUINO

#include <Arduino.h>
#include "valuable.h"
#endif

/*************************************************
* Describable
**************************************************/
class Describable : public Valuable, public Printable
{
  public:
    /*************************************************/
		virtual size_t printTo(Print& p) const
    {
      size_t size = 0;
      size += p.print(this->value_);
      return size;
    };
    /*************************************************/

};
/*************************************************/

#endif
