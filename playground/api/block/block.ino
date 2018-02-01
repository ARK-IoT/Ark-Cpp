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
  String blockDescription = _arkManager.block("4367122150875693402").description();
    Serial.println("blockDescription: ");
    Serial.println(blockDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/* needs stream->string size fix for large callbacks */
//  String blocks = _arkManager.blocks();
//    Serial.println(blocks);
//    Serial.println();
//    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockEpoch = _arkManager.blockEpoch();
    Serial.println("blockEpoch: ");
    Serial.println(blockEpoch);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockHeightDescription = _arkManager.blockHeight().description();
    Serial.println("blockHeightDescription: ");
    Serial.println(blockHeightDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockNethashDescription = _arkManager.blockNethash().description();
    Serial.println("blockNethashDescription: ");
    Serial.println(blockNethashDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockFeeArk = _arkManager.blockFee().ark;
    Serial.println("blockFeeArk: ");
    Serial.println(blockFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockFeesDescription = _arkManager.blockFees().description();
    Serial.println("blockFeesDescription: ");
    Serial.println(blockFeesDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockMilestone = _arkManager.blockMilestone();
    Serial.println("blockMilestone: ");
    Serial.println(blockMilestone);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockRewardArk = _arkManager.blockReward().ark;
    Serial.println("blockRewardArk: ");
    Serial.println(blockRewardArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockSupplyArk = _arkManager.blockSupply().ark;
    Serial.println("blockSupplyArk: ");
    Serial.println(blockSupplyArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockStatusDescription = _arkManager.blockStatus().description();
    Serial.println("blockStatusDescription: ");
    Serial.println(blockStatusDescription);
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