

#ifndef NETWORKS_H
#define NETWORKS_H

#include "utilities/platform.h"
#include "models/network.h"
#include "types/types.h"

namespace ARK {
namespace Constants {
namespace Networks {

namespace Devnet
{
/* Devnet
	ARK::Network devnet = ARK::Constants::Networks::Devnet::model;

	578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
	DARK
	DѦ
	https://dexplorer.ark.io/
	30
*/
	extern const Hash nethash;

	extern const char* const seeds[6];
	extern const int port;
	extern const ARK::NetworkType type;
};

namespace Mainnet
{
/*	Mainnet
ARK::Network mainnet = ARK::Constants::Networks::Mainnet::model;
ARK::API::Manager mngr(mainnet);

6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988
ARK
Ѧ
https://explorer.ark.io/
23
*/
	extern const Hash nethash;
	extern const char* const seeds[46];
	extern const int port;
	extern const ARK::NetworkType type;
};

const char *randomPeer(ARK::NetworkType netType);
int getPort(ARK::NetworkType netType);

namespace Model
{
	extern const ARK::Network Devnet;
	extern const ARK::Network Mainnet;
};

namespace Network_ADV
{
	extern const ARK::Network_ADV::network_t devnet;
	extern const ARK::Network_ADV::network_t main;
	extern const ARK::Network_ADV::network_t testnet;
	extern const ARK::Network_ADV::network_t bitcoin;
};

};
};
};

#endif
