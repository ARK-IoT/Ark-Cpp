<p align="center">
  <img src="https://github.com/sleepdefic1t/ark-cpp/blob/master/ark_cpp_logo.png"/>
</p>

# Ark for Machines v0.6.3  

![environment](https://img.shields.io/badge/environment-arduino-15909C.svg?style=flat) 
![language](https://img.shields.io/badge/language-Cpp/C++-blue.svg?style=flat) 
![version](https://img.shields.io/badge/version-v0.6.3-orange.svg?style=flat)
![build](https://img.shields.io/badge/build-passing-159C40.svg?style=flat) 
![License: MIT](https://img.shields.io/badge/license-MIT-BE90D4.svg?style=flat)  

Not production ready.  

For advanced usage, be sure to check out our Cross-platform feature branch  
https://github.com/ark-iot/ark-cpp/tree/feature/cmake_platform_io

# Supported Boards
- [X] ESP8266 https://www.adafruit.com/product/2821   // Development board
- [ ] ESP32 https://www.adafruit.com/product/3405     // currently testing


#### What can this do?  
GET information from the Ark Blockchain using Arduino boards.  
Create models of basic Ark "types." (e.g. Accounts, Blocks, Delegates, Peers, etc)  

#### What CAN'T this do (yet)?  
Generate Ark Addresses & Signatures.  
Create Signed transaction for broadcast to the Ark Ecosystem.  


# How to use this

1) Define the network  
>  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;  

or  

> ARK::Network devnet {  
  "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",  
  "DARK",  
  "DѦ",  
  "https://dexplorer.ark.io/",  
  30  
};  



2) Create the manager instance  
> ARK::API::Manager arkManager(devnet)  

3) Use manager to get info from the Ark Blockchain  
> auto status = arkManager.loaderStatus()
> Serial.print(status) 
> prints {  
  "success":true,  
  "loaded":false,  
  "now":2348744,  
  "blocksCount":0  
}  



## Examples

Get VendorField of a given Transaction ID using the ESP8266
```cpp
/*
* demo_sketch.ino
*/

#include <ESP8266WiFi.h>

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

void testVendorField()
{
  Network devnet = Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);

  Hash txID = "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e";

  auto vendorField = arkManager.getVendorField(txID);
    Serial.print("\nvendorField: ");
    Serial.println(vendorField);
}

void setup()
{
  Serial.begin(115200);
  reportFreeHeap();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  testVendorField();
}

void loop(){}

```
> vendorField: 1ARK-GOLang is saying whoop whooop  


#

Get Ark Account from a given Ark Address
```cpp
  Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
  auto account = arkManager.account(darkAddress);
    Serial.print("\naccount: ");
    Serial.println(account);
```
> account:  
> address: DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA  
> unconfirmedBalance: 106914.85341862  
> balance: 106914.85341862  
> publicKey: 0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456  
> unconfirmedSignature: 1  
> secondSignature: 1  
> secondPublicKey: 03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869  
> multisignatures:  
> u_multisignatures:  


## todo

- [ ] API
  - [x] add models & constants
  - [x] add static endpoints
  - [x] Network manager
  - [X] Network Client
  - [X] API Gets
  - [ ] API Posts
    - [ ] test api posts
    - [ ] finish api posts
  - [ ] Error Handling
    - [X] test error handling
    - [ ] finish error handling


- [ ] Crypto
  - [ ] Test Crypto
    - [X] test sha256
    - [X] test bigint
    - [ ] test secp256k1 ECDSA
    - [X] test ripemd160
    - [X] test base58
    - [ ] test Signing and Address generation.
  - [ ] Add Crypto
    - [ ] add sha256
    - [ ] add bigint
    - [ ] add secp256k1 ECDSA
    - [ ] add ripemd160
    - [ ] add base58
    - [ ] add Signing and Address generation.


- [ ] TODO
  - [ ] Documentation 
  - [ ] Tests 
  - [ ] Handle Large Callbacks 
  - [X] Remove 'String' objects in favor of 'const char*'

