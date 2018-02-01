#include <ark.h>

/********************************************************************************
*
* transaction: 
*   {
*     "id": String,                   //  "f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9",
*     "blockid":  String,             //  "14671461178414977683",
*     "height": String,               //  1696504
*     "type": int,                    //  0,
*     "timestamp":  String,           //  9656006,
*     "amount": Balance,              //  51000,
*     "fee":  Balance,                //  10000000,
*     "vendorField": String,          //
*     "senderId": Address             //  "DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
*     "recipientId":  Address,        //  "D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD",
*     "senderPublicKey":  Publickey,  //  "039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c",
*     "signature":  Signature,        //  "3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b",
*     "asset":                        //  {},
*     "confirmations":  String        //  1868079
*   }
*
********************************************************************************/

void constructTransaction() {

  ARK::Transaction transaction = {
    "f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9",
    "14671461178414977683",
    "1696504",
    0,
    "9656006",
    { "51000" },
    { "10000000" },
    "vendorField",
    "DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
    "D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD",
    { "039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c" },
    { "3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b" },
    "1868079" 
  };

  
  Serial.println("Offline Instantiated Transaction Description\n"); 
  Serial.println(transaction.description()); 

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
  constructTransaction();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}