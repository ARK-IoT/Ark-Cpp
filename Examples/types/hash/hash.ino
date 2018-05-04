#include <ark.h>

/********************************************************************************
*
* hash: 
*   "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*   
*   64 Characters | HEX-encoded
*
********************************************************************************/
void constructHash()
{
  Hash hash("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23");
    Serial.println("hash: 578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23\n");
    Serial.println("hash: ");
    Serial.println(hash);
};

void setup() {
  Serial.begin(115200);
  constructHash();
}

void loop() {}
