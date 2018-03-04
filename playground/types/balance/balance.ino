#include <ark.h>


/********************************************************************************
*
* Currently very verbose, needs bigint implementation using pow(10,8)
*
* Balance: 
*   arktoshi : "100000000"
*   ark : "1.00000000"
*   
*   Big Integer/Floating Point | 8-decimal places/pow(10,8)
*   
*   Currenty Block Supply total ~ 1.3e16 (12984403000000000:arktoshi)/(129844030.00000000:ark)
*
********************************************************************************/

void constructBalance() {
    Serial.println("\n=====\n");

  Balance balance("12984403000000000");
    Serial.println("Balance: 12984403000000000\n");
    Serial.println("Balance.ark: ");
    Serial.println(balance.ark());
    Serial.println("\nBalance.arktoshi: ");
    Serial.println(balance.arktoshi());
    Serial.println("\n=====\n");
    Serial.flush();

  Balance balance2("100000000");
    Serial.println("Balance: 100000000\n");
    Serial.println("Balance.ark: ");
    Serial.println(balance2.ark());
    Serial.println("\nBalance.arktoshi: ");
    Serial.println(balance2.arktoshi());
    Serial.println("\n=====\n");
    Serial.flush();

  Balance balance3("10000000");
    Serial.println("Balance: 10000000\n");
    Serial.println("Balance.ark: ");
    Serial.println(balance3.ark());
    Serial.println("\nBalance.arktoshi: ");
    Serial.println(balance3.arktoshi());
    Serial.println("\n=====\n");
    Serial.flush();

  Balance balance4("10000");
    Serial.println("Balance: 10000\n");
    Serial.println("Balance.ark: ");
    Serial.println(balance4.ark());
    Serial.println("\nBalance.arktoshi: ");
    Serial.println(balance4.arktoshi());
    Serial.println("\n=====\n");
    Serial.flush();


};


/*  ==========================================================================  */
extern "C" {
#include "user_interface.h"
}
void reportFreeHeap() {
  Serial.print("\n\nsystem_get_free_heap_size: ");
  Serial.print(system_get_free_heap_size());
  Serial.println("\n\n");
};
/*  ==========================================================================  */


void check() {
  constructBalance();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}
