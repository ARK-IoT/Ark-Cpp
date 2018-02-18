

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

#define HASH_SIZE 65

struct Hash
{
  private:
    static const auto HASH_LENGTH = HASH_SIZE / sizeof(char);

  public:
    char value[HASH_LENGTH];

    Hash() : value() { }

    Hash(const char* const hashStr) : value()
    {
      if (strlen(hashStr) < HASH_LENGTH - 1) {
        value[0] = '\0';
      }
      else {
        strncpy(value, hashStr, sizeof(value) / sizeof(value[0]));
      };
    };

};


#endif