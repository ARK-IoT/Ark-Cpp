

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

Hash transactionID = { "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e" };

/*  ==================================  */
  String transactionFromIDDescription = _arkManager.transaction(transactionID).description(); //has vendorField value
    Serial.println("transactionFromIDDescription: ");
    Serial.println(transactionFromIDDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
//  String transactions = _arkManager.transactions();
//    Serial.println("transactions: ");
//    Serial.println(transactions);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
  String transactionUnconfirmedFromId = _arkManager.transactionUnconfirmed(transactionID);
    Serial.println("transactionUnconfirmedFromId: ");
    Serial.println(transactionUnconfirmedFromId);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String transactionsUnconfirmed = _arkManager.transactionsUnconfirmed();
    Serial.println("transactionsUnconfirmed: ");
    Serial.println(transactionsUnconfirmed);
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