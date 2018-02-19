

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
    char value_[HASH_LENGTH];

  public:

    Hash() : value_() { }

    Hash(const char* const hashStr) : value_()
    {
      if (strlen(hashStr) < HASH_LENGTH - 1) {
        value_[0] = '\0';
      }
      else {
        strncpy(value_, hashStr, sizeof(value_) / sizeof(value_[0]));
      };
    };

    const char* getValue() const { return value_; };
};


#endif