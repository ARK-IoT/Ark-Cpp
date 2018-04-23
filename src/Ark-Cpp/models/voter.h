

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
/**************************************************************************************************/
/*************************************************
*   ARK::Voter
**************************************************/
struct Voter : public voter_t, Printable
{
public:
	Voter();
	Voter(
			const char *const newUsername,
			const char *const newAddress,
			const char *const newPublickey,
			const char *const newBalance
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
};

#endif
