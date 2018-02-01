#include <ark.h>

/********************************************************************************
* example peer from: api/peers/get?ip=167.114.29.55&port=4002
*
* peer: 
*   {
*     "ip": String,         //  "167.114.29.55",
*     "port": int,          //  4002,
*     "version":  String,   //  "1.1.1",
*     "errors": int,        //  0,
*     "os": String,         //  "linux4.4.0-79-generic",
*     "height": String,     //  2467740,
*     "status": String,     //  "OK",
*     "delay":  int         //  9
*   }
*
********************************************************************************/

void constructPeer() {

  ARK::Peer peer = {
    "167.114.29.55",
    4002,
    "1.1.1",
    0,
    "linux4.4.0-79-generic",
    "2467740",
    "OK",
    9,
  };

  Serial.println("Offline Instantiated Peer Description\n"); 
  Serial.println(peer.description()); 

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
  constructPeer();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}