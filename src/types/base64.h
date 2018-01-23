

#ifndef base64_h
#define base64_h
#pragma once


// namespace ARK {
//   namespace Utilities {



// // {"success":true,"publicKey":"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"}
// // base64
// // 66 characters

    #define BASE64_SIZE 66

    struct base64_t {
      public:
        char value[BASE64_SIZE];
        base64_t();

        base64_t(String _base64String) {      
          for (int i = 0; i < BASE64_SIZE; i++) {
            this->value[i] = _base64String[i];
          };
        };

        String description() {
          String resp;
          for (int i = 0; i < BASE64_SIZE; i++) {
            resp += value[i];
          };
          return resp;
        };      
    };

    typedef base64_t Base64;


//   };
// };


#endif
