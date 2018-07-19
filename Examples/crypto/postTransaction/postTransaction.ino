#include <ark.h>


void postTransaction()
{
	// Select devnet
	const auto network_id = ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash;

	// Select mainnet
	//const auto network_id = ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash;
	
	const auto recipient_address = ""; // Example: Devnet: DGUac5xr1cn7D2VVG7hEmV1cb1wfvbbc6p, Mainnet: AQf97MEVnnJSYsJHfcrLTGH5J4GYSB5dLH
	const auto amount_in_arktoshi = 00000001u;
	const auto optional_vendor_field = "";
	const auto passphrase = ""; // Example: word1 word2 word3 .... word12
	
	// Create the transaction
	const auto t = ARK::make_transaction(
		network_id,
		recipient_address,
		amount_in_arktoshi,
		optional_vendor_field,
		passphrase
	);
	
	// Send the transaction to the blockchain
	ARK::Network network = ARK::Constants::Networks::Model::Devnet;
	//ARK::Network network = ARK::Constants::Networks::Model::Mainnet;

	ARK::API::Manager arkManager(network);

	const auto success = _arkManager.postTransaction(*t);
	
	Serial.print("Success: ");
	Serial.println(success);
	
	Serial.print("Transaction Id: ");
	Serial.println(t->id());
}

void setup()
{
  Serial.begin(115200);
  postTransaction();
}

void loop() {}
