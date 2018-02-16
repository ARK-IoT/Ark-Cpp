

#ifndef voter_h
#define voter_h

namespace ARK {
    
/*************************************************
*   ARK::Voter
**************************************************/
struct Voter {
	public:
    const char* username;
    Address address;
    Publickey publicKey;
    Balance balance;

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
	serial.print(this->address.value);
	serial.print("\npublicKey: ");
	serial.print(this->publicKey.value);
	serial.print("\nbalance.ark: ");
	serial.print(this->balance.ark());
	serial.print("\n");
	serial.flush();
}
/*************************************************/


#endif
