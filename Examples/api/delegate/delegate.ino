#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* delegate: 
********************************************************************************/

/*************************************************/
// #ifdef DEBUG_ESP_PORT
// #define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
// #else
// #define DEBUG_MSG(...)
// #endif
/*************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

  /*************************************************/
  const int delegatesCount = arkManager.delegatesCount();
    Serial.println("delegatesCount: ");
    Serial.println(delegatesCount);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateSearch = arkManager.delegateSearch("sleepdeficit");
    Serial.println("delegateSearch: ");
    Serial.println(delegateSearch);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateVoters = arkManager.delegateVoters(darkPubkey);
    Serial.println("delegateVoters: ");
    Serial.println(delegateVoters);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  ARK::Delegate delegateByUsername = arkManager.delegate("sleepdeficit");
    Serial.println("delegateByUsername: ");
    Serial.println(delegateByUsername);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  ARK::Delegate delegateByPublickey = arkManager.delegate(darkPubkey);
    Serial.println("delegateByPublickey: ");
    Serial.println(delegateByPublickey);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  /*************************************************/
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
  /*************************************************/
  /*************************************************/

  /*************************************************/
	Balance delegateFee = arkManager.delegateFee();
    Serial.println("delegateFee: ");
    Serial.println(delegateFee.ark());
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateForgedByAccount = arkManager.delegateForgedByAccount(darkPubkey);
    Serial.println("delegateForgedByAccount: ");
    Serial.println(delegateForgedByAccount);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateNextForgers = arkManager.delegateNextForgers();
    Serial.println("delegateNextForgers: ");
    Serial.println(delegateNextForgers);
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
