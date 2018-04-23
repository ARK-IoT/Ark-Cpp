

#ifndef NETWORKS_H
#define NETWORKS_H

<<<<<<< HEAD
#include "platform.h"
#include "network.h"

=======
>>>>>>> master
namespace ARK
{
namespace Constants
{
namespace Networks
{

<<<<<<< HEAD
namespace Devnet
{

	/*
=======

namespace Devnet
{

/*
>>>>>>> master
			ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
			ARK::API::Manager mngr(devnet);
					Serial.println(mngr.network.nethash);
					Serial.println(mngr.network.token);
					Serial.println(mngr.network.symbol);
					Serial.println(mngr.network.explorer);
					Serial.println(mngr.network.version);

			Outputs: =====
				578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
				DARK
				DѦ
				https://dexplorer.ark.io/
				30
			==============
	*/

<<<<<<< HEAD
	extern const char* nethash;

	extern const char* const seeds[6];

	extern const int port;

    extern const NetworkType type;

	/*	String randomPeer = ARK::Constants::Networks::Devnet::randomPeer();	*/
	inline const char* randomPeer()
	{
		return seeds[random(0, 5)];
	};

	extern const ARK::Network model;
}


=======
const auto nethash = "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23";
const char *const seeds[6] = {
		"167.114.29.32", "167.114.29.33",
		"167.114.29.34", "167.114.29.35",
		"167.114.29.36",
		"130.211.155.75"
};
const auto port = 4002;
const auto type = NetworkType::DEV;

};
>>>>>>> master

namespace Mainnet
{

<<<<<<< HEAD
	/*	TEST
=======
/*	TEST
>>>>>>> master
		ARK::Network mainnet = ARK::Constants::Networks::Mainnet::model;
		ARK::API::Manager mngr(mainnet);
		Serial.println(mngr.network.nethash);
		Serial.println(mngr.network.token);
		Serial.println(mngr.network.symbol);
		Serial.println(mngr.network.explorer);
		Serial.println(mngr.network.version);

		Outputs: =====
			6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988
			ARK
			Ѧ
			https://explorer.ark.io/
			23
		==============
	*/

<<<<<<< HEAD
	extern const char* nethash;
	extern const char* const seeds[46];

	extern const int port;

    extern const NetworkType type;

	/*	String randomPeer = ARK::Constants::Networks::Mainnet::randomPeer();	*/
	inline const char* randomPeer()
	{
		return seeds[random(0, 45)];
	};

	extern const ARK::Network model;
}

namespace Network_ADV
{

	extern const ARK::Network_ADV::network_t devnet;

	extern const ARK::Network_ADV::network_t main;

	extern const ARK::Network_ADV::network_t testnet;

	extern const ARK::Network_ADV::network_t bitcoin;
};

};
}
}
=======
const auto nethash = "6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988";
const char *const seeds[46] =
		{
				"5.39.9.240", "5.39.9.241", "5.39.9.242", "5.39.9.243",
				"5.39.9.244", "5.39.9.250", "5.39.9.251", "5.39.9.252",
				"5.39.9.253", "5.39.9.254", "5.39.9.255", "5.39.53.48",
				"5.39.53.49", "5.39.53.50", "5.39.53.51", "5.39.53.52",
				"5.39.53.53", "5.39.53.54", "5.39.53.55",
				"37.59.129.160", "37.59.129.161", "37.59.129.162", "37.59.129.163",
				"37.59.129.164", "37.59.129.165", "37.59.129.166", "37.59.129.167",
				"37.59.129.168", "37.59.129.169", "37.59.129.170", "37.59.129.171",
				"37.59.129.172", "37.59.129.173", "37.59.129.174", "37.59.129.175",
				"193.70.72.80", "193.70.72.81", "193.70.72.82", "193.70.72.83",
				"193.70.72.84", "193.70.72.85", "193.70.72.86", "193.70.72.87",
				"193.70.72.88", "193.70.72.89", "193.70.72.90"
};
const auto port = 4001;
const auto type = NetworkType::MAIN;

};


const char *randomPeer(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return ARK::Constants::Networks::Devnet::seeds[random(0, 5)];		break;
		case MAIN: return ARK::Constants::Networks::Devnet::seeds[random(0, 45)];	break;
		case CUSTOM: return "Error: method yet not available for custom networks";break;
		default: return "Error: Nethash Invalid";		break;
	}
}

int getPort(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return ARK::Constants::Networks::Devnet::port;		break;
		case MAIN: return ARK::Constants::Networks::Devnet::port;		break;
		default: return -1;			break;
	}
}


namespace Model
{

ARK::Network Devnet =
		{
				Devnet::nethash,
				"DARK",
				"DѦ",
				"https://dexplorer.ark.io/",
				30};

ARK::Network Mainnet =
		{
				Mainnet::nethash,
				"ARK",
				"Ѧ",
				"https://explorer.ark.io/",
				23};
}
namespace Network_ADV
{

ARK::Network_ADV::network_t devnet{
		"\x18 Ark Devnet Signed message:\n",
		{
				0x43587CF, //<-hex dec: 70617039,
				0x4358394	//<-hex dec: 70615956
		},
		0x1E, //<-hex dec: 30,
		0xBB	//<-hex dec: 187
};

ARK::Network_ADV::network_t main{
		" \x18 Ark Signed Message: \n",
		{
				0x2bf4968, // base58 will have a prefix 'apub'
				0x2bf4530	// base58Priv will have a prefix 'apriv'
		},
		0x17, // Addresses will begin with 'A'
		0xaa	// Network prefix for wif generation
};

ARK::Network_ADV::network_t testnet{
		"\x18 Ark Testnet Signed Message:\n",
		{0x043587cf,
		 0x04358394},
		0x52, // Addresses will begin with 'a'
		0xba	// Network prefix for wif generation
};

ARK::Network_ADV::network_t bitcoin{
		"\x18 Bitcoin Signed Message:\n",
		{0x0488b21e,
		 0x0488ade4},
		0x00,
		0x80};
};
};
};
};

>>>>>>> master
#endif
