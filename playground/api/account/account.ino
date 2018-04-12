#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* account: 
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
  ARK::API::Manager arkManager(ARK::Constants::Networks::Model::Devnet);
  /*************************************************/
  
  Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

  /*************************************************/
  auto balances = arkManager.accountBalance(darkAddress);
    Serial.println("balanceDescription: ");
    Serial.println(balances);
    Serial.println("\n=====\n");
    delay(50); 
  /*************************************************/

  /*************************************************/
  auto publicKey = arkManager.accountPublickey(darkAddress);
    Serial.println("publicKey: ");
    Serial.println(publicKey.getValue());
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance delegatesFee = arkManager.accountDelegatesFee(darkAddress);
    Serial.println("delegatesFee: ");
    Serial.println(delegatesFee.ark());
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/
  
  /*************************************************/
  ARK::Delegate delegate = arkManager.accountDelegates(darkAddress);
    Serial.println("delegate: ");
    Serial.println(delegate);
    Serial.println("\n=====\n");
  delay(50);
  /*************************************************/

  /*************************************************/
  auto account = arkManager.account(darkAddress);
    Serial.println("account: ");
    Serial.println(account);
    Serial.println("\n=====\n");
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
