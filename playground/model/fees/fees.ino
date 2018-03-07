#include <ark.h>

/********************************************************************************
*
* fees: 
*   {
*     "send": Balance,              //  10000000,
*     "vote": Balance,              //  100000000,
*     "secondsignature": Balance,   //  500000000,
*     "delegate": Balance,          //  2500000000,
*     "multisignature": Balance,    //  500000000
*   }
*
********************************************************************************/

void constructFees() {

  ARK::Fees fees(
    "10000000",
    "100000000",
    "500000000",
    "2500000000",
    "500000000"
  );

  Serial.println("Offline Instantiated Fees Description\n");
  Serial.println(fees); 

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
  constructFees();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}
