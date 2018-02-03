

#ifndef HASH_H
#define HASH_H
#pragma once

/********************************************************************************
*
* hash: 
*   "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*   
*   64 Characters | HEX-encoded
*
********************************************************************************/

#define HASH_SIZE 64

struct Hash
{
private:
  static const auto HASH_LEN = HASH_SIZE / sizeof(byte);

  char value_[HASH_LEN] = { '\0' };

public:
  Hash() { }

  /*  =====  */

  Hash(const char* const hashStr)
  {
    strncpy(value_, hashStr, HASH_LEN);
    value_[HASH_LEN - 1] = '\0';
  }

  /*  =====  */

  const char* const description() const { return value_; }
};

#endif