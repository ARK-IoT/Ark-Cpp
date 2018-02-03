

#ifndef PUBLICKEY_H
#define PUBLICKEY_H
#pragma once

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/


    #define PUBLICKEY_SIZE 66

    struct publickey_t {
    private:
        static const auto PUBLICKEY_LEN = PUBLICKEY_SIZE / sizeof(char);
        char value_[PUBLICKEY_LEN] = { '\0' };

    public:
        publickey_t() { };

        publickey_t(const char* const _base64String) {      
          strncpy(value_, _base64String, PUBLICKEY_LEN);
          value_[PUBLICKEY_LEN - 1] = '\0';
        };

        const char* const description() const { return value_; };      
    };

    typedef publickey_t Publickey;


//   };
// };


#endif
