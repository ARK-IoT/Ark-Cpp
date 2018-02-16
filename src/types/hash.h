

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
  public:
    const char* value;
  
    Hash() : value() { }

    Hash(const char* const hashStr) : value()
    {
      this->value = hashStr;
    }

};


#endif