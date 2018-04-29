/***************************************
* Ark-Cpp - for the Ark Ecosystem (ark.io)
* https://github.com/Ark-IoT/Ark-Cpp
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ARK_H
#define ARK_H

#ifdef __cplusplus

#include <Arduino.h>
#include "Ark-Cpp.h"

using namespace ARK;


typedef ARK::Account Account;
typedef ARK::Block Block;
typedef ARK::Delegate Delegate;
typedef ARK::Fees Fees;
typedef ARK::Network Network;
typedef ARK::Peer Peer;
typedef ARK::Transaction Transaction;
typedef ARK::Voter Voter;

#else

#error C++ compiler required. expected file extensions: ".cc" ".cpp"

#endif

#endif
