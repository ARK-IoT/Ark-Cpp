

#include "types.h"

Publickey::Publickey() : value_() {};

Publickey::Publickey(const char* const pubkeyStr) : value_()
{
  if (strlen(pubkeyStr) * PUBLICKEY_CHARACTER_WIDTH == PUBLICKEY_SIZE)
  {
    strncpy(value_, pubkeyStr, PUBLICKEY_LENGTH);

  }
};