<p align="center">
  <img src="https://github.com/sleepdefic1t/ark-cpp/blob/master/ark_cpp_logo.png"/>
</p>

# Ark for Machines v0.6  

![environment](https://img.shields.io/badge/environment-arduino-15909C.svg?style=flat) 
![language](https://img.shields.io/badge/language-Cpp/C++-blue.svg?style=flat) 
![version](https://img.shields.io/badge/version-v0.6-orange.svg?style=flat)
![build](https://img.shields.io/badge/build-passing-159C40.svg?style=flat) 
![License: MIT](https://img.shields.io/badge/license-MIT-BE90D4.svg?style=flat)  

Not production ready.  

# Supported Boards
- [X] ESP8266 https://www.adafruit.com/product/2821   // Development board
- [ ] ESP32 https://www.adafruit.com/product/3405     // currently testing
- [ ] Uno r3 https://www.adafruit.com/product/50      // currently testing



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
    - [ ] test bigint
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

