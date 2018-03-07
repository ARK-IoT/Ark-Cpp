

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
struct Fees :
		public fees_t, Printable
{
	public:

		Fees (
				const char* const newSend,
				const char* const newVote,
				const char* const newDelegate,
				const char* const newSS,
				const char* const newMS
		)
		{
			this->send = Balance(newSend);
			this->vote = Balance(newVote);
			this->delegate = Balance(newDelegate);
			this->secondsignature = Balance(newSS);
			this->multisignature = Balance(newMS);
		};

    /*************************************************
    *
    **************************************************/
    virtual size_t printTo(Print& p) const
    {
        size_t size = 0;

        size += p.print("\nsend: ");
        size += p.print(this->send.ark());

        size += p.print("\nvote: ");
        size += p.print(this->vote.ark());

        size += p.print("\ndelegate: ");
        size += p.print(this->delegate.ark());

        size += p.print("\nsecondsignature: ");
        size += p.print(this->secondsignature.ark());

        size += p.print("\nmultisignature: ");
        size += p.print(this->multisignature.ark());
        
        return size;
    }
    /*************************************************/

};
/*************************************************/

};

#endif
