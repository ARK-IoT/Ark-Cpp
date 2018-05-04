#include <ark.h>

/********************************************************************************
*
* delegate: 
*   {
*     "username": const char*,         //  "sleepdeficit",
*     "address":  Address,        //  "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
*     "publicKey":  Publickey,    //  "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*     "vote": Balance,            //  "8418345341862",
*     "producedblocks": int,      //  35810,
*     "missedblocks": int,        //  3164
*     "rate": int,                //  31,
*     "approval": double,         //  0.06,
*     "productivity": double      //  91.88
*   }
*
********************************************************************************/
void constructDelegate()
{
  ARK::Delegate delegate(
    "sleepdeficit",
    "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
    "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
    "8418345341862",
    35810,
    3164,
    31,
    0.06,
    91.88
  );
  Serial.println("Offline Instantiated Delegate Description\n"); 
  Serial.println(delegate); 
};

void setup()
{
  Serial.begin(115200);
  constructDelegate();
}

void loop() {}
