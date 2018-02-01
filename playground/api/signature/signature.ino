

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
  String signaturesFeeArk = _arkManager.signaturesFee().ark;
    Serial.println("signaturesFeeArk: ");
    Serial.println(signaturesFeeArk);
    Serial.println();
    delay(50);
/*  ==================================  */


/*  ==================================  */
  String multisignaturesPending = _arkManager.multisignaturesPending(darkPubkey);
    Serial.println("multisignaturesPending: ");
    Serial.println(multisignaturesPending);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*  Only on Mainnet?  */
//  String multisignaturesAccounts = _arkManager.multisignaturesAccounts(darkHash);
//    Serial.println("multisignaturesAccounts: ");
//    Serial.println(multisignaturesAccounts);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
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