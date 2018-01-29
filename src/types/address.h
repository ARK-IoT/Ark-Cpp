

#ifndef ADDRESS_H
#define ADDRESS_H
#pragma once

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

#define ADDRESS_LENGTH 34

struct address_t
{

public:
  char value[ADDRESS_LENGTH / sizeof(char)] = {'\0'};

  address_t()
  {
    // for (int i = 0; i < ADDRESS_LENGTH; i++) {
    this->value[0] = 0;
    // };
  };

  address_t(String _addressString)
  {
    for (int i = 0; i < ADDRESS_LENGTH; i++)
    {
      this->value[i] = _addressString[i];
    };
  };

  address_t(const char *addressString)
  {
    for (int i = 0; i < ADDRESS_LENGTH; i++)
    {
      this->value[i] = addressString[i];
    };
  };

  String description()
  {
    String resp;
    for (int i = 0; i < ADDRESS_LENGTH; i++)
    {
      resp += value[i];
    };
    return resp;
  };
};

typedef address_t Address;

#endif