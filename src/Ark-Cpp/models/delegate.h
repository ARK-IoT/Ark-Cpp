

#ifndef delegate_h
#define delegate_h

<<<<<<< HEAD
#include "address.h"
#include "balance.h"
#include "publickey.h"
#include "platform.h"

#include <cstring>
#include <cstdio>

=======
>>>>>>> master
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

<<<<<<< HEAD
namespace ARK {
	
/*  ================================================  */
/*  =============  */
/*  ARK::Delegate  */
class Delegate : public Printable {
private:
	char username_[1024];
	Address address_;
	Publickey publicKey_;
	Balance vote_;
	int producedblocks_;
	int missedblocks_;
	int rate_;
	double approval_;
	double productivity_;

public:
    Delegate(
        const char* const u, 
        const char* const a, 
        const char* const p, 
        const char* const v,
        int pb,
        int mb,
        int r,
        double ap,
        double pr
    ) : 
		username_(), 
		address_(a), 
		publicKey_(p), 
		vote_(v), 
		producedblocks_(pb), 
		missedblocks_(mb), 
		rate_(r), 
		approval_(ap), 
		productivity_(pr)
    { 
        strncpy(username_, u, sizeof(username_) / sizeof(username_[0]));
    }

	const char* username() const noexcept { return username_; }
	const Address& address() const noexcept { return address_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	const Balance& vote() const noexcept { return vote_; }
	int produced_blocks() const noexcept { return producedblocks_; }
	int missed_blocks() const noexcept { return missedblocks_; }
	int rate() const noexcept { return rate_; }
	double approval() const noexcept { return approval_; }
	double productivity() const noexcept { return productivity_; }

	size_t printTo(Print& p) const override;

};
/*  =============  */
/*  ================================================  */

}
=======
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
>>>>>>> master

#endif
