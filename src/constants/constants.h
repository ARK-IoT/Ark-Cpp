/***************************************
*	Ark-Cpp - for the Ark Ecosystem (ark.io)
*	https://github.com/Ark-IoT/Ark-Cpp
*
*	sleepdeficit(simon@ark.io)
*	MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "constants/currencies.h"
#include "constants/networks.h"

namespace ARK {

// amounts in arktoshi
const auto send_fee = 10000000u;
const auto vote_fee = 100000000u;
const auto delegate_fee = 2500000000u;
const auto second_signature_fee = 500000000u;
const auto multi_signature_fee = 500000000u;

namespace Crypto {

const auto PUBLIC_KEY_SIZE = 65u;
const auto COMPRESSED_PUBLIC_KEY_SIZE = 33u;
const auto PRIVATE_KEY_SIZE = 32u;

}

}

#endif
