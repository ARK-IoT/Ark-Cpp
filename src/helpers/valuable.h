

#ifndef VALUABLE_H
#define VALUABLE_H

#ifdef ARDUINO
#include "describable.h"
#endif

/*************************************************
*	Valuable
**************************************************/
struct Valuable
{
  protected:
    char value_[];

  public:
    const char *getValue() const { return this->value_; };

};
/*************************************************/

#endif
