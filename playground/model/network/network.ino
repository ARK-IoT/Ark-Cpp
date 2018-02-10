#include <ark.h>

/********************************************************************************
* example devnet from: api/loader/autoconfigure
*
* network:
*   {
*     "nethash":  Hash,   //  "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
*     "token":  String,   //  "DARK",
*     "symbol": String,   //  "DѦ",
*     "explorer": String, //  "http://dexplorer.ark.io",
*     "version":  Int,    //  30
*   }
*
********************************************************************************/

void constructNetwork() {

  ARK::Network network(
    "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
    "DARK",
    "DѦ",
    "http://dexplorer.ark.io",
    30
  );

  Serial.println("Offline Instantiated Network Description\n"); 
  char buf[512] = {};
  network.description(buf, sizeof(buf));
  Serial.println(buf); 

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
  constructNetwork();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}
