

#ifndef fees_h
#define fees_h

namespace ARK
{
/*************************************************
*   ARK::fees_t
**************************************************/
struct fees_t
{
public:
	Balance send;
	Balance vote;
	Balance delegate;
	Balance secondsignature;
	Balance multisignature;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::Fees
*   /api/blocks/getFees
**************************************************/
struct Fees : public fees_t, Printable
{
public:
	Fees(
			const char *const newSend,
			const char *const newVote,
			const char *const newDelegate,
			const char *const newSS,
			const char *const newMS
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
};

#endif
