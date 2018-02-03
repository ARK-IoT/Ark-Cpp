

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
private:
    static const auto SIGNATURE_LEN = SIGNATURE_SIZE / sizeof(char);
    char value_[SIGNATURE_LEN] = { '\0' };

public:
    signature_t(){};

    signature_t(const char* const _signatureString) {      
      strncpy(value_, _signatureString, SIGNATURE_LEN);
      value_[SIGNATURE_LEN - 1] = '\0';
    };

    const char* const description() const { return value_; };      
};


typedef signature_t Signature;

const  Signature SIGNATURE_EMPTY();

#endif