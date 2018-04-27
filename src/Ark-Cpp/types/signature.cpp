

#include "types.h"

signature_t::signature_t() : value_() {};

signature_t::signature_t(const char* const signatureStr) : value_()
{
  if ( (signatureStr != nullptr) && (strlen(signatureStr) * SIGNATURE_CHARACTER_WIDTH == SIGNATURE_SIZE) )
  {
    strncpy(value_, signatureStr, SIGNATURE_LENGTH);
  }
};
