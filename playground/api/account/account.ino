#include <ark.h>
//#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* account: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);
/*  ==================================  */
  char buf[512] = {};
Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

/*  ==================================  */
  arkManager.accountBalance(darkAddress).description(buf, sizeof(buf));
    Serial.println("balanceDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50); 
/*  ==================================  */

/*  ==================================  */
  auto publicKeyDescription = arkManager.accountPublickey(darkAddress).description();
    Serial.println("publicKeyDescription: ");
    Serial.println(publicKeyDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  auto delegatesFeeArk = arkManager.accountDelegatesFee(darkAddress).ark();
    Serial.println("delegatesFeeArk: ");
    Serial.println(delegatesFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
  
/*  ==================================  */
    arkManager.accountDelegates(darkAddress).description(buf, sizeof(buf));
    Serial.println("delegatesDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  arkManager.account(darkAddress).description(buf, sizeof(buf));
    Serial.println("accountDescription: ");
    Serial.println(buf);
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
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println();
  
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    check();
}

void loop() {}
