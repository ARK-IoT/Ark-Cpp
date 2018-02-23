

#ifndef voter_h
#define voter_h

namespace ARK
{
    
/*************************************************
*   ARK::voter_t
**************************************************/
struct voter_t
{
	public:
    char username[20];
    Address address;
    Publickey publicKey;
    Balance balance;
};
/*************************************************/


/*************************************************
*   ARK::Voter
**************************************************/
struct Voter :
		public voter_t
{
	Voter() {
		strncpy(this->username, "", sizeof(this->username) / sizeof(this->username[0]));
		this->address = Address("");
		this->publicKey = Publickey("");
		this->balance = Balance("0");
	};

	Voter(
		const char* const newUsername,
		const char* const newAddress,
		const char* const newPublickey,
		const char* const newBalance
	) {
		strncpy(this->username, newUsername, sizeof(this->username) / sizeof(this->username[0]));
		this->address = Address(newAddress);
		this->publicKey = Publickey(newPublickey);
		this->balance = Balance(newBalance);
	};

	void printTo(HardwareSerial &serial);
};
/*************************************************/

};


/*************************************************
*	ARK::Voter
*		printTo(Serial)
**************************************************/
void ARK::Voter::printTo(HardwareSerial &serial)
{
	serial.print("\nusername: ");
		serial.print(this->username);
	serial.print("\naddress: ");
		serial.print(this->address.getValue());
	serial.print("\npublicKey: ");
		serial.print(this->publicKey.getValue());
	serial.print("\nbalance.ark: ");
		serial.print(this->balance.ark());
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif
