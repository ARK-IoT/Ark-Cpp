

#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* peer: 
********************************************************************************/

void checkAPI()
{
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

   /*************************************************/
  auto peer = arkManager.peer("167.114.29.55", 4002);
    Serial.println("peer: ");
    Serial.println(peer);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  /*************************************************/
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~10,000 bytes  */
//  String peersDescription = _arkManager.peers().description();
//    Serial.println("peersDescription: ");
//    Serial.println(peersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
  /*************************************************/
  /*************************************************/

  /*************************************************/
  auto peerVersion = arkManager.peerVersion();
    Serial.println("peerVersion: ");
    Serial.println(peerVersion);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/
}
/*************************************************/

/*************************************************/
void setup()
{
  Serial.begin(115200);

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
  checkAPI();
}

void loop() {}
/*************************************************/
