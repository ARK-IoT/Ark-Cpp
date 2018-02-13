

#ifndef delegate_h
#define delegate_h

#include "address.h"
#include "balance.h"
#include "publickey.h"

#include <cstring>
#include <cstdio>

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
	char username[1024] = { '\0' };
	Address address;
	Publickey publicKey;
	Balance vote;
	int producedblocks;
	int missedblocks;
	int rate;
	double approval;
	double productivity;

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
    ) : address(a), publicKey(p), vote(v), producedblocks(pb), missedblocks(mb), rate(r), approval(ap), productivity(pr)
    { 
        strncpy(username, u, sizeof(username) / sizeof(username[0]));
    }

	void description(char* const buf, size_t size) const;

};
/*  =============  */
/*  ================================================  */

}

#endif
