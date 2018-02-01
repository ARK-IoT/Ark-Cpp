<img src="https://github.com/sleepdefic1t/ark-cpp/blob/master/ark_cpp_logo.png" width="500px">


This is not production ready.
It will be changing quite a bit before a final release version.


# How to use this

1) Define the network  
>  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;  

or  

> 	ARK::Network devnet { "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", "DARK", "DѦ", "https://dexplorer.ark.io/", 30 };  



2) Create the manager instance  
> ARK::API::Manager arkManager(devnet)  

3) Use manager to get info from the Ark Blockchain  
> String statusDescription = arkManager.loaderStatus().description()  
> prints {"success":true,"loaded":false,"now":2348744,"blocksCount":0}  


## todo

- [ ] API
  - [x] add models & constants
  - [x] add static endpoints
  - [x] Network manager
    - [x] test network manager
    - [x] add network manager
  - [X] Network Client
    - [X] test network client
    - [X] add network client
  - [ ] API Gets
    - [X] test api calls
    - [ ] finish api calls
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


- [ ] Needs Fixed
  - [ ] Stack Network Calls
  - [ ] Handle Array Values in Callback
  - [ ] Handle Large Callback Strings 
