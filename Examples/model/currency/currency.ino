#include <ark.h>

/********************************************************************************
*
* currency: 
*   {
*     "ticker": const char*,   //  "ARK",
*     "name":  const char*,    //  "ark",
*     "symbol":  const char*,  //  "Ѧ",
*   }
*
********************************************************************************/

void constructBlock() {

  ARK::Model::Currency currency(
    "ARK",
    "ark",
    "Ѧ"
  );

  Serial.println("Offline Instantiated Block Description\n"); 
  Serial.println(currency); 

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
  constructBlock();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}
