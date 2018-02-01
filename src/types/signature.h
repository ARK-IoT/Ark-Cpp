

#ifndef SIGNATURE_H
#define SIGNATURE_H
#pragma once


/********************************************************************************
*
* signature: 
*   "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*   
*   142 Characters | ?-encoded
*
********************************************************************************/


#define SIGNATURE_SIZE 143

struct signature_t {
  public:
    char value[SIGNATURE_SIZE / sizeof(char)] = { '\0' };    ;

    signature_t(){};

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

const  Signature SIGNATURE_EMPTY();

#endif