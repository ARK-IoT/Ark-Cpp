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

Publickey darkPubkey = { "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456" };

/*  ==================================  */
  int delegatesCount = _arkManager.delegatesCount();
    Serial.println("delegatesCount: ");
    Serial.println(delegatesCount);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateSearchDescription = _arkManager.delegateSearch("sleepdeficit").description();
    Serial.println("delegateSearchDescription: ");
    Serial.println(delegateSearchDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
//  String delegateVotersDescription = _arkManager.delegateVoters(darkPubkey).description();
//    Serial.println("delegateVotersDescription: ");
//    Serial.println(delegateVotersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateByUsernameDescription = _arkManager.delegate("sleepdeficit").description();
    Serial.println("delegateByUsernameDescription: ");
    Serial.println(delegateByUsernameDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateByPublickeyDescription = _arkManager.delegate(darkPubkey.description()).description();
    Serial.println("delegateByPublickeyDescription: ");
    Serial.println(delegateByPublickeyDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateFeeArk = _arkManager.delegateFee().ark;
    Serial.println("delegateFeeArk: ");
    Serial.println(delegateFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateForgedByAccountDescription = _arkManager.delegateForgedByAccount(darkPubkey).description();
    Serial.println("delegateForgedByAccountDescription: ");
    Serial.println(delegateForgedByAccountDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateNextForgersDescription = _arkManager.delegateNextForgers().description();
    Serial.println("delegateNextForgersDescription: ");
    Serial.println(delegateNextForgersDescription);
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