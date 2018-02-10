#include <ark.h>

/********************************************************************************
*
* delegate: 
*   {
*     "username": String,         //  "sleepdeficit",
*     "address":  Address,        //  "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
*     "publicKey":  Publickey,    //  "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*     "vote": Balance,            //  "8418345341862",
*     "producedblocks": int,      //  35810,
*     "missedblocks": int,        //  3164
*     "rate": int,                //  31,
*     "approval": double,         //  0.06,
*     "productivity": double      //  91.88
*   }
*
********************************************************************************/

void constructDelegate() {

  ARK::Delegate delegate(
    "sleepdeficit",
    "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
    "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
    "8418345341862",
    35810,
    3164,
    31,
    0.06,
    91.88
  );

  Serial.println("Offline Instantiated Delegate Description\n"); 
  char buf[512] = {};
  delegate.description(buf, sizeof(buf));
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
  constructDelegate();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}
