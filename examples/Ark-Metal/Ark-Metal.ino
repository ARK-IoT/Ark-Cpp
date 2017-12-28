#include <ark.h>

void setup()
{
  Serial.begin(115200);

  ARK::Model::Account account;
  account.username = "test";
  Serial.print(account.username); 

  ARK::Model::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager mngr(devnet);
  Serial.print(mngr.isConnected);

} 

void loop() {}
