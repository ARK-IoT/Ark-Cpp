#include <ark.h>

void setup()
{
  Serial.begin(115200);

  ARK::Model::Account account;
    account.username = "test";
    Serial.print(account.username); 
   
  delay(1000);

  ARK::Model::Network devnet = ARK::Constants::Networks::Devnet::model;
    Serial.println(devnet.nethash);
    Serial.println(devnet.token);
    Serial.println(devnet.symbol);
    Serial.println(devnet.explorer);
    Serial.println(devnet.version);

  delay(1000);

  String randomPeer = ARK::Constants::Networks::Devnet::randomPeer();
    Serial.println("randomPeer: " + randomPeer);

  delay(1000);

  ARK::Utilities::Network::Manager netManager(devnet);
    Serial.println(netManager.networkPeer);

  delay(100000);

} 

void loop() {}
