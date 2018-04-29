#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* loader: 
********************************************************************************/

/*************************************************/
//  #ifdef DEBUG_ESP_PORT
//  #define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
//  #else
//  #define DEBUG_MSG(...)
//  #endif
/*************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  /*************************************************/
	auto loaderStatus = arkManager.loaderStatus();
    Serial.println("loaderStatus: ");
    Serial.println(loaderStatus);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
	auto loaderSync = arkManager.loaderSync();
    Serial.println("loaderSync: ");
    Serial.println(loaderSync);
		Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
	auto autoconfigure = arkManager.loaderAutoconfigure();
    Serial.println("autoconfigure: ");
    Serial.println(autoconfigure);
    Serial.println("\n=====\n");
    delay(50); 
  /*************************************************/
}
/*************************************************/


/*************************************************/
extern "C" {
#include "user_interface.h"
}
void reportFreeHeap()
{
  Serial.print("\n\nsystem_get_free_heap_size: ");
  Serial.print(system_get_free_heap_size());
  Serial.println("\n\n");
};
/*************************************************/


/*************************************************/
void check()
{
  checkAPI();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}
/*************************************************/


/*************************************************/
void setup()
{
  Serial.begin(115200);
  reportFreeHeap();
    
  WiFi.mode(WIFI_STA);
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
/*************************************************/
