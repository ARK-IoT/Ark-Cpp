

#ifndef delegate_h
#define delegate_h

/********************************************************************************
*
* delegate: 
*		{  
*			"username": String,
*			"address":	Address,
*			"publicKey":	Publickey,
*			"vote":	Balance,
*			"producedblocks": uint,
*			"missedblocks":	uint,
*			"rate":	int,
*			"approval": double,
*			"productivity":	double
*		}
*
********************************************************************************/

namespace ARK
{


/*************************************************
*   ARK::delegate_t
**************************************************/
struct delegate_t
{
	public:
		char username[20];
		Address address;
		Publickey publicKey;
		Balance vote;
		int producedblocks;
		int missedblocks;
		int rate;
		double approval;
		double productivity;
};
/*************************************************/


/*************************************************
*   ARK::Delegate
**************************************************/
struct Delegate :
		public delegate_t
{
		public:
		
		Delegate(
			const char* const newUsername,
			const char* const newAddress,
			const char* const newPublicKey,
			const char* const newVote,
			int newProducedblocks,
			int newMissedblocks,
			int newRate,
			double newApproval,
			double newProductivity
		)
		{
			strncpy(username, newUsername, sizeof(username) / sizeof(username[0]));
			address = Address(newAddress);
			publicKey = Publickey(newPublicKey);
			vote = Balance(newVote);
			producedblocks = newProducedblocks;
			missedblocks =  newMissedblocks;
			rate = newRate;
			approval = newApproval;
			productivity = newProductivity;
		};

	void printTo(HardwareSerial &serial);
};
/*************************************************/

}


/*************************************************
*   printTo(Serial)
**************************************************/
void ARK::Delegate::printTo(HardwareSerial &serial)
{
	serial.print("username: ");
    serial.print(this->username);
	serial.print("\naddress: ");
    serial.print(this->address.getValue());
	serial.print("\npublicKey: ");
		serial.print(this->publicKey.getValue());
	serial.print("\nvote: ");
    serial.print(this->vote.ark());
	serial.print("\nproducedblocks: ");
    serial.print(this->producedblocks);
	serial.print("\nmissedblocks: ");
    serial.print(this->missedblocks);
	serial.print("\nrate: ");
    serial.print(this->rate);
	serial.print("\napproval: ");
    serial.print(this->approval);
	serial.print("%\nproductivity: ");
    serial.print(this->productivity);
		serial.print("%\n");
	serial.flush();
}
/*************************************************/


#endif
