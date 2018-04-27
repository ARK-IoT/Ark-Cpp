

#include "types.h"

Hash::Hash() : value_() {}

Hash::Hash(const char* const hashStr) : value_()
{
  if (strlen(hashStr) * HASH_CHARACTER_WIDTH == HASH_SIZE)
  {
    strncpy(value_, hashStr, HASH_CHARACTER_LENGTH);
  }
};