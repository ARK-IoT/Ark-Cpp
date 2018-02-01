#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* account: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet);
/*  ==================================  */

Address darkAddress = { "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA" };

/*  ==================================  */
 String balanceDescription = arkManager.accountBalance(darkAddress).description();
    Serial.println("balanceDescription: ");
    Serial.println(balanceDescription);
    Serial.println("\n=====\n");
    delay(50); 
/*  ==================================  */

/*  ==================================  */
  String publicKeyDescription = arkManager.accountPublickey(darkAddress).description();
    Serial.println("publicKeyDescription: ");
    Serial.println(publicKeyDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegatesFeeArk = arkManager.accountDelegatesFee(darkAddress).ark;
    Serial.println("delegatesFeeArk: ");
    Serial.println(delegatesFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
  
/*  ==================================  */
  String delegatesDescription = arkManager.accountDelegates(darkAddress).description();
    Serial.println("delegatesDescription: ");
    Serial.println(delegatesDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String accountDescription = arkManager.account(darkAddress).description();
    Serial.println("accountDescription: ");
    Serial.println(accountDescription);
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