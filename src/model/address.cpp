

#include "address.h"

ARK::Address(String _address) {
  if (this->isValid(_address))
    this->description = _address;
};
      
bool ARK:Address::isValid(String _address) {      
  bool is_valid = (_address.length() == ADDRESS_LENGTH);
  for (int i = 0; i < ADDRESS_LENGTH; i++) {
    if (!isAlphaNumeric(_address[i]) || isWhitespace(_address[i]))
      is_valid = false;
  };
  return is_valid;
};

