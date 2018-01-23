

#ifndef hash_h
#define hash_h
#pragma once


/*  65 char hex: */
/*  (example) 578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23  */
#define HASH_SIZE 64

struct Hash {
  public:
    char value[HASH_SIZE] = { '\0' };

    Hash(){
      for (int i = 0; i < HASH_SIZE; i++) {
        this->value[i] = '0';
      };
    };

    /*  =====  */

    Hash(String _hashString) {      
      for (int i = 0; i < HASH_SIZE; i++) {
        this->value[i] = _hashString[i];
      };
    };

    /*  =====  */

    String description() {
      String resp;
      for (int i = 0; i < HASH_SIZE; i++) {
        resp += value[i];
      };
      return resp;
    };      
};



#endif