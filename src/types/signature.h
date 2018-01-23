

#ifndef signature_h
#define signature_h
#pragma once

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