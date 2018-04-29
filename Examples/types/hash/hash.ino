#include <ark.h>

/********************************************************************************
*
* hash: 
*   "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*   
*   64 Characters | HEX-encoded
*
********************************************************************************/

void constructHash() {
    Serial.println("\n=====\n");

  Hash hash("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23");
    Serial.println("hash: 578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23\n");
    Serial.println("hash.description: ");
    Serial.println(hash.description());
    Serial.println("\n=====\n");
};


/*  ==========================================================================  */
extern "C" {
#include "user_interface.h"
}
void reportFreeHeap() {
  Serial.print("\n\nsystem_get_free_heap_size: ");
  Serial.print(system_get_free_heap_size());
  Serial.println("\n\n");
};
/*  ==========================================================================  */


void check() {
  constructHash();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}