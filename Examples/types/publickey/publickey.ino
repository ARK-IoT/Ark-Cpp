#include <ark.h>

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/
void constructPublickey()
{
  Publickey pubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("pubkey: 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456\n");
    Serial.println("pubkey: ");
    Serial.println(pubkey);
};

void setup()
{
  Serial.begin(115200);
  constructPublickey();
}

void loop() {}
