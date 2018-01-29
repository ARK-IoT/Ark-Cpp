

#ifndef SIGNATURE_H
#define SIGNATURE_H
#pragma once


/********************************************************************************
*
* signature: 
*   "3044022019ace92e5b91eb70ca13ff63d834aea38b7629c48876094f7abb97b39b28d2c6022012d5df269621473575ee364d5e86a6ca1ea7abedf27c98d2adce103939f45aaa"
*   
*   143 Characters | ?-encoded
*
********************************************************************************/

#define SIGNATURE_SIZE 143

struct signature_t {
  public:
    char value[SIGNATURE_SIZE / sizeof(char)] = { '\0' };    ;

    signature_t();

    signature_t(String _signatureString) {      
      for (int i = 0; i < SIGNATURE_SIZE; i++) {
        this->value[i] = _signatureString[i];
      };
    };

    String description() {
      String resp;
      for (int i = 0; i < SIGNATURE_SIZE; i++) {
        resp += value[i];
      };
      return resp;
    };      
};


typedef signature_t Signature;

#endif