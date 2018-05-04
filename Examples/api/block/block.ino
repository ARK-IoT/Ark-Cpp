#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* block: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  /*************************************************/
  ARK::Block block = arkManager.block("4367122150875693402");
    Serial.println("block: ");
    Serial.println(block);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/


  /*************************************************/
  /*************************************************/
/* needs stream->string size fix for large callbacks */
//  String blocks = arkManager.blocks();
//    Serial.println(blocks);
//    Serial.println();
//    delay(50);
  /*************************************************/
  /*************************************************/


  /*************************************************/
  auto blockEpoch = arkManager.blockEpoch();
    Serial.println("blockEpoch: ");
    Serial.println(blockEpoch);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto blockHeight =  arkManager.blockHeight();
    Serial.println("blockHeight: ");
    Serial.println(blockHeight);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  Hash blockNethash = arkManager.blockNethash();
    Serial.println("blockNethash: ");
    Serial.println(blockNethash);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockFee = arkManager.blockFee();
    Serial.println("blockFee: ");
    Serial.println(blockFee.ark());
    Serial.println("\n=====\n");
    delay(100);
  /*************************************************/

  /*************************************************/
  ARK::Fees blockFees = arkManager.blockFees();
    Serial.println("blockFees: ");
    Serial.println(blockFees);
    Serial.println("\n=====\n");
    delay(100);
  /*************************************************/

  /*************************************************/
  auto blockMilestone = arkManager.blockMilestone();
    Serial.println("blockMilestone: ");
    Serial.println(blockMilestone);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockReward = arkManager.blockReward();
    Serial.println("blockReward: ");
    Serial.println(blockReward.ark());
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockSupply = arkManager.blockSupply();
    Serial.println("blockSupply: ");
    Serial.println(blockSupply.ark());
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/

  /*************************************************/
  auto blockStatus = arkManager.blockStatus();
    Serial.println("blockStatus: ");
    Serial.println(blockStatus);
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
