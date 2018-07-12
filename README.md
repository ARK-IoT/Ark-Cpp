<p align="center">
  <img src="https://github.com/Ark-IoT/ark-cpp/blob/master/ark_cpp_logo.png"/>
</p>

# Ark for Machines v0.8 

![language](https://img.shields.io/badge/language-Cpp/C++-blue.svg?style=flat) 
![version](https://img.shields.io/badge/version-v0.6.8-orange.svg?style=flat)
![License: MIT](https://img.shields.io/badge/license-MIT-BE90D4.svg?style=flat)  
![environment](https://img.shields.io/badge/environment-arduino-15909C.svg?style=flat)  
![environment](https://img.shields.io/badge/environment-linux-FF7F50.svg?style=flat)  
![environment](https://img.shields.io/badge/environment-macOS-blue.svg?style=flat)  
![environment](https://img.shields.io/badge/environment-windows-blue.svg?style=flat)  

[![Build Status](https://travis-ci.org/Ark-IoT/Ark-Cpp.svg?branch=master)](https://travis-ci.org/Ark-IoT/Ark-Cpp)  

[![Build status](https://ci.appveyor.com/api/projects/status/dtbx7xmu6m8fpdb7?svg=true)](https://ci.appveyor.com/project/Ark-IoT/ark-cpp)

Not production ready.  

# Supported Boards
- [X] ESP8266 https://www.adafruit.com/product/2821   // Development board
- [X] ESP32 https://www.adafruit.com/product/3405


#### What can this do?  
GET information from the Ark Blockchain using Arduino boards.  
Create models of basic Ark "types." (e.g. Accounts, Blocks, Delegates, Peers, etc)  

#### What CAN'T this do (yet)?  
Generate Ark Addresses & Signatures.  
Create Signed transaction for broadcast to the Ark Ecosystem.  


# How to use this

1) Define the network  
>  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;  

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
    - [X] test secp256k1 ECDSA
    - [X] test ripemd160
    - [X] test base58
    - [X] test Address generation
    - [ ] test Signing/Signature Generation
  - [ ] Add Crypto
    - [X] add sha256
    - [X] add bigint
    - [X] add secp256k1 ECDSA
    - [X] add ripemd160
    - [X] add base58
    - [X] add Address generation
    - [ ] add Signing/Signature Generation


- [ ] TODO
  - [ ] Documentation 
  - [ ] Handle Large Callbacks 

