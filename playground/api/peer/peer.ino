

#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* block: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet);
/*  ==================================  */

/*  ==================================  */
  String peerDescription = _arkManager.peer("167.114.29.55", 4002).description();
    Serial.println("peerDescription: ");
    Serial.println(peerDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~10,000 bytes  */
//  String peersDescription = _arkManager.peers().description();
//    Serial.println("peersDescription: ");
//    Serial.println(peersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
  String peerVersionDescription = _arkManager.peerVersion().description();
    Serial.println("peerVersionDescription: ");
    Serial.println(peerVersionDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
}


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
  checkAPI();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}