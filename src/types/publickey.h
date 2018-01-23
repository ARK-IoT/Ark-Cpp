

#ifndef publickey_h
#define publickey_h
#pragma once


// namespace ARK {
//   namespace Utilities {



// {"success":true,"publicKey":"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"}
// base64
// 66 characters

    #define PUBLICKEY_SIZE 66

    struct publickey_t {
      public:
        char value[PUBLICKEY_SIZE / sizeof(char)] = { '\0' };    ;

        publickey_t(){
          for (int i = 0; i < PUBLICKEY_SIZE; i++) {
            this->value[i] = 0;
          };
        };

        publickey_t(String _base64String) {      
          for (int i = 0; i < PUBLICKEY_SIZE; i++) {
            this->value[i] = _base64String[i];
          };
        };

        String description() {
          String resp;
          for (int i = 0; i < PUBLICKEY_SIZE; i++) {
            resp += value[i];
          };
          return resp;
        };      
    };

    typedef publickey_t Publickey;


//   };
// };


#endif
