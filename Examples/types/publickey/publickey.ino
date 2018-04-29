#include <ark.h>

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/

void constructPublickey() {
    Serial.println("\n=====\n");

  Publickey pubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("pubkey: 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\n");
    Serial.println("pubkey.description: ");
    Serial.println(pubkey.description());
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
  constructPublickey();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}