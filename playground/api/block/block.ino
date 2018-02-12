#include <ark.h>
//#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* block: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager _arkManager(devnet);
/*  ==================================  */

/*  ==================================  */
    char buf[512] = {};
    _arkManager.block("4367122150875693402").description(buf, sizeof(buf));
    Serial.println("blockDescription: ");
    Serial.println(buf);
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
  const auto blockEpoch = _arkManager.blockEpoch();
    Serial.println("blockEpoch: ");
    Serial.println(blockEpoch);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.blockHeight().description(buf, sizeof(buf)); 
    Serial.println("blockHeightDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  const auto blockNethashDescription = _arkManager.blockNethash().description();
    Serial.println("blockNethashDescription: ");
    Serial.println(blockNethashDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  const auto blockFeeArk = _arkManager.blockFee().ark();
    Serial.println("blockFeeArk: ");
    Serial.println(blockFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.blockFees().description(buf, sizeof(buf));
    Serial.println("blockFeesDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    const auto blockMilestone = _arkManager.blockMilestone();
    Serial.println("blockMilestone: ");
    Serial.println(blockMilestone);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    const auto blockRewardArk = _arkManager.blockReward().ark();
    Serial.println("blockRewardArk: ");
    Serial.println(blockRewardArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    const auto blockSupplyArk = _arkManager.blockSupply().ark();
    Serial.println("blockSupplyArk: ");
    Serial.println(blockSupplyArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.blockStatus().description(buf, sizeof(buf));
    Serial.println("blockStatusDescription: ");
    Serial.println(buf);
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
