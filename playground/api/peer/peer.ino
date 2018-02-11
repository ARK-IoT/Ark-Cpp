

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
	_arkManager.peer("167.114.29.55", 4002).description(buf, sizeof(buf));
    Serial.println("peerDescription: ");
    Serial.println(buf);
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
	_arkManager.peerVersion().description(buf, sizeof(buf));
    Serial.println("peerVersionDescription: ");
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