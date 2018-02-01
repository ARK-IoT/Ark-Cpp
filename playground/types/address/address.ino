#include <ark.h>

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

void constructAddress() {
    Serial.println("\n=====\n");

  Address address("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("address: DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\n");
    Serial.println("address.description: ");
    Serial.println(address.description());
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
  constructAddress();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}