

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
*   ARK::Delegate
**************************************************/
struct Delegate
{
public:
	const char* username;
	Address address;
	Publickey publicKey;
	const Balance vote;
	int producedblocks;
	int missedblocks;
	int rate;
	double approval;
	double productivity;

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
    serial.print(this->address.value);
    serial.print("\npublicKey: ");
    serial.print(this->publicKey.value);
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
