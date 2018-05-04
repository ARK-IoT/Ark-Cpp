#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* signature: 
********************************************************************************/

void checkAPI()
{
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456" );

  /*************************************************/
  Balance signaturesFee = arkManager.signaturesFee();
    Serial.print("signaturesFee: ");
    Serial.println(signaturesFee.ark());
    Serial.println();
    delay(50);
  /*************************************************/


  /*************************************************/
  auto multisignaturesPending = arkManager.multisignaturesPending(darkPubkey);
    Serial.print("multisignaturesPending: ");
    Serial.println(multisignaturesPending);
    Serial.println("\n=====\n");
    delay(50);
  /*************************************************/


  /*************************************************/
  /*************************************************/
  /*  Only on Mainnet?  */
  //  String multisignaturesAccounts = arkManager.multisignaturesAccounts(darkHash);
  //    Serial.println("multisignaturesAccounts: ");
  //    Serial.println(multisignaturesAccounts);
  //    Serial.println("\n=====\n");
  //    delay(50);
  /*************************************************/
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
