
#include "ark.h"


void setup()
{
  Serial.begin(115200);
  ARK::Model::Account account;
  account.username = "test";
  Serial.print(account.username); 
}

void loop() {}
