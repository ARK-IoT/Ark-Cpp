

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
public:
  char value[HASH_SIZE / sizeof(byte)]; // = { '\0' };

  Hash()
  {
    for (int i = 0; i < HASH_SIZE; i++)
    {
      this->value[i] = '0';
    };
  };

  /*  =====  */

  Hash(String hashStr)
  {
    for (int i = 0; i < HASH_SIZE; i++)
    {
      this->value[i] = hashStr[i];
    };
  };

  /*  =====  */

  String description()
  {
    String resp;
    for (int i = 0; i < HASH_SIZE; i++)
    {
      resp += value[i];
    };
    return resp;
  };
};

#endif