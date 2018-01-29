

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
	
/*  ================================================  */
/*  =============  */
/*  ARK::Delegate  */
struct Delegate
{
public:
	String username;
	Address address;
	Publickey publicKey;
	Balance vote;
	int producedblocks;
	int missedblocks;
	int rate;
	double approval;
	double productivity;

	String description();

};
/*  =============  */
/*  ================================================  */

}

/*  ================================================  */
/*  =====  */
/*  Description  */
String ARK::Delegate::Delegate::description()
{
	String resp;
	resp += "username: ";
	resp += this->username;
	resp += "\n";
	resp += "address.description: ";
	resp += this->address.description();
	resp += "\n";
	resp += "publicKey.description: ";
	resp += this->publicKey.description();
	resp += "\n";
	resp += "vote.ark: ";
	resp += this->vote.ark;
	resp += "\n";
	resp += "producedblocks: ";
	resp += this->producedblocks;
	resp += "\n";
	resp += "missedblocks: ";
	resp += this->missedblocks;
	resp += "\n";
	resp += "rate: ";
	resp += this->rate;
	resp += "\n";
	resp += "approval: ";
	resp += this->approval;
	resp += "%\n";
	resp += "productivity: ";
	resp += this->productivity;
	resp += "%";
	return resp;
}
/*  =====  */
/*  ================================================  */

#endif
