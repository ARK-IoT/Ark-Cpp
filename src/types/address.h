


#ifndef address_h
#define address_h
#pragma once


#define ADDRESS_SIZE 34

struct address_t {
  public:
    char value[ADDRESS_SIZE / sizeof(char)] = { '\0' };

    address_t(){
      for (int i = 0; i < ADDRESS_SIZE; i++) {
        this->value[i] = 0;
      };
    };

    address_t(String _addressString) {      
      for (int i = 0; i < ADDRESS_SIZE; i++) {
        this->value[i] = _addressString[i];
      };
    };

    String description() {
      String resp;
      for (int i = 0; i < ADDRESS_SIZE; i++) {
        resp += value[i];
      };
      return resp;
    };      
};


typedef address_t Address;

// namespace ARK {  
// #define ADDRESS_SIZE 35
// struct Address {
//   String description[ADDRESS_SIZE]; 
//   Address() {}; 
//   Address(String _str) {
//     if (sizeof(_str) != ADDRESS_SIZE) {
//       this->description[ADDRESS_SIZE] = "malformed";
//     } else {
//       this->description[ADDRESS_SIZE] = _str[ADDRESS_SIZE];
//     }
//   };
// };
  //  class Address {
  //     public:
  //       String description;
  //       Address(String _address);
  //     private:
  //       bool isValid(String _address);
  //   };
// };
// ARK::Address::Address(String _address) {
//   if (this->isValid(_address))
//     this->description = _address;
// }; 
// bool ARK::Address::isValid(String _address) {      
//   bool is_valid = (_address.length() == ADDRESS_LENGTH);
//   for (int i = 0; i < ADDRESS_LENGTH; i++) {
//     if (!isAlphaNumeric(_address[i]) || isWhitespace(_address[i]))
//       is_valid = false;
//   };
//   return is_valid;
// };

#endif