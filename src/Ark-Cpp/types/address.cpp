

#include "types.h"

Address::Address() : value_() {};

Address::Address(const char* const addressStr) : value_()
{
  if (strlen(addressStr) * ADDRESS_CHARACTER_WIDTH == ADDRESS_SIZE)
  {
    strncpy(value_, addressStr, ADDRESS_LENGTH);
  }
};