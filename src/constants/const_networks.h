

#ifndef const_networks_h
#define const_networks_h

namespace ARK {
	namespace Constants {
		namespace Networks {
		
			ARK::Model::Network Devnet {
				"6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988",
				"DARK",
				"DѦ",
				"https://dexplorer.ark.io/",
				"1.1.0"
			};
			
			ARK::Model::Network Mainnet {
				"6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988",
				"DARK",
				"Ѧ",
				"https://explorer.ark.io/",
				"1.0.2"
			};

		};
  };
};

#endif

/*
namespace Network_ADV  {
	ARK::Model::Network_ADV::network_t main {
		"\x18\Ark Signed Message:\n",
		{
			0x2bf4968, // base58 will have a prefix 'apub'
			0x2bf4530 // base58Priv will have a prefix 'apriv'
		},
		0x17, // Addresses will begin with 'A'
		0xaa // Network prefix for wif generation
	};
	ARK::Model::Network_ADV::network_t devnet {
		"\x18\Ark Devnet Signed message:\n",
		{
			0x43587CF, //<-hex dec: 70617039,
			0x4358394 //<-hex dec: 70615956
		},
		0x1E, //<-hex dec: 30,
		0xBB //<-hex dec: 187
	};
	ARK::Model::Network_ADV::network_t testnet {
		"\x18\Ark Testnet Signed Message:\n",
		{
			0x043587cf,
			0x04358394
		},
		0x52, // Addresses will begin with 'a'
		0xba // Network prefix for wif generation
	};
	ARK::Model::Network_ADV::network_t bitcoin {
		"\x18\Bitcoin Signed Message:\n",
		{
			0x0488b21e,
			0x0488ade4
		},
		0x00,
		0x80
	};
};
*/