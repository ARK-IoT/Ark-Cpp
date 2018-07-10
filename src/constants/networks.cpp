

#include "constants/networks.h"

namespace ARK
{
namespace Constants
{
namespace Networks
{

namespace Devnet
{
	const Hash nethash = "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23";
	const char* const seeds[NUM_SEEDS] = {
		"167.114.29.32", "167.114.29.33",
		"167.114.29.34", "167.114.29.35",
		"167.114.29.36"
	};
	const uint16_t port = 4002;
	const ARK::NetworkType type = NetworkType::DEV;
};

namespace Mainnet
{
	const Hash nethash = "6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988";
	const char* const seeds[NUM_SEEDS] = {
		"5.39.9.240",
		"5.39.9.241",
		"5.39.9.242",
		"5.39.9.243",
		"5.39.9.244",
		"5.39.9.245",
		"5.39.9.246",
		"5.39.9.247",
		"5.39.9.248",
		"5.39.9.249",
		"5.39.9.250",
		"5.39.9.251",
		"5.39.9.252",
		"5.39.9.253",
		"5.39.9.254",
		"5.39.9.255",
		"54.38.48.160",
		"54.38.48.161",
		"54.38.48.162",
		"54.38.48.163",
		"54.38.48.164",
		"54.38.48.165",
		"54.38.48.166",
		"54.38.48.167",
		"54.38.48.168",
		"54.38.48.169",
		"54.38.48.170",
		"54.38.48.171",
		"54.38.48.172",
		"54.38.48.173",
		"54.38.48.174",
		"54.38.48.175"
	};
	const uint16_t port = 4001;
	const ARK::NetworkType type = NetworkType::MAIN;
};


const char *randomPeer(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return ARK::Constants::Networks::Devnet::seeds[generate_random_number(0, ARK::Constants::Networks::Devnet::NUM_SEEDS)];
		case MAIN: return ARK::Constants::Networks::Mainnet::seeds[generate_random_number(0, ARK::Constants::Networks::Mainnet::NUM_SEEDS)];
		case CUSTOM: return "Error: method yet not available for custom networks";
		default: return "Error: Nethash Invalid";
	}
}

int getPort(ARK::NetworkType netType)
{
	switch (netType) {
		case DEV: return ARK::Constants::Networks::Devnet::port;
		case MAIN: return ARK::Constants::Networks::Mainnet::port;
		default: return -1;
	}
}


namespace Model
{
	const ARK::Network Devnet =
	{
		Devnet::nethash.getValue(),
		"DARK",
		u8"DѦ",
		"https://dexplorer.ark.io/",
		30
	};

	const ARK::Network Mainnet =
	{
		Mainnet::nethash.getValue(),
		"ARK",
		u8"Ѧ",
		"https://explorer.ark.io/",
		23
	};
}


namespace Network_ADV
{
	const ARK::Network_ADV::network_t devnet
	{
		"\x18 Ark Devnet Signed message:\n",
		{
			0x43587CF, //<-hex dec: 70617039,
			0x4358394	//<-hex dec: 70615956
		},
		0x1E, //<-hex dec: 30,
		0xaa	//<-hex dec: 187
	};

	const ARK::Network_ADV::network_t main
	{
		" \x18 Ark Signed Message: \n",
		{
			0x2bf4968, // base58 will have a prefix 'apub'
			0x2bf4530	// base58Priv will have a prefix 'apriv'
		},
		0x17, // Addresses will begin with 'A'
		// 0xaa works based on available test data but don't know if it is right
		// should it be 0xbb, or 0xef????
		0xaa	// Network prefix for wif generation
	};

	const ARK::Network_ADV::network_t testnet
	{
		"\x18 Ark Testnet Signed Message:\n",
		{
			0x043587cf,
			0x04358394
		},
		0x52, // Addresses will begin with 'a'
		0xba	// Network prefix for wif generation
	};

	const ARK::Network_ADV::network_t bitcoin
	{
		"\x18 Bitcoin Signed Message:\n",
		{
			0x0488b21e,
			0x0488ade4
		},
		0x00,
		0x80
	};
};

};
};
};
