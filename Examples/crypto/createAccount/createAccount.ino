#include <ark.h>


void createAccount()
{
	// Creates a devnet account
	const auto network_id = ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash;

	// Creates a mainnet account
	//const auto network_id = ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash;
	
	// Randomly generate a 12 word passphrase using English words
	const auto passphrase = ARK::Crypto::BIP39::generate_mnemonic();

	const auto account = ARK::Crypto::create_account(network_id, passphrase);
	Serial.print("Address: ");
	Serial.println(account.address().getValue());

	Serial.print("Public Key: ");
	Serial.println(account.public_key().getValue());
}

void setup()
{
  Serial.begin(115200);
  createAccount();
}

void loop() {}
