

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

/**************************************************************************************************/

/*************************************************
*   ARK::Delegate
**************************************************/
struct Delegate : public delegate_t, Printable
{
public:
	Delegate(
			const char *const newUsername,
			const char *const newAddress,
			const char *const newPublicKey,
			const char *const newVote,
			int 							newProducedblocks,
			int 							newMissedblocks,
			int 							newRate,
			double 						newApproval,
			double 						newProductivity
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
};

#endif
