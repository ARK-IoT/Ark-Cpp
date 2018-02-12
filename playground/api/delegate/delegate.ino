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

Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

/*  ==================================  */
  int delegatesCount = _arkManager.delegatesCount();
    Serial.println("delegatesCount: ");
    Serial.println(delegatesCount);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
	char buf[512] = {};
	  _arkManager.delegateSearch("sleepdeficit").description(buf, sizeof(buf));
    Serial.println("delegateSearchDescription: ");
    Serial.println(buf);
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
    _arkManager.delegate("sleepdeficit").description(buf, sizeof(buf));
    Serial.println("delegateByUsernameDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.delegate(darkPubkey.description()).description(buf, sizeof(buf));
    Serial.println("delegateByPublickeyDescription: ");
    Serial.println(buf);
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
	//TODO:  fails here
	const auto delegateFee = _arkManager.delegateFee();
    Serial.println("delegateFeeArk: ");
    Serial.println(delegateFee.ark());
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.delegateForgedByAccount(darkPubkey).description(buf, sizeof(buf));
    Serial.println("delegateForgedByAccountDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
    _arkManager.delegateNextForgers().description(buf, sizeof(buf));
    Serial.println("delegateNextForgersDescription: ");
    Serial.println(buf);
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
