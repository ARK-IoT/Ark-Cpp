

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{


/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Delegate::Respondable::Search  */
  struct Search
  {
  public:
    char username[64]; //TODO review sizes
    Address address;
    Publickey publicKey;
    Balance vote;
    int producedblocks;
    int missedblocks;

    Search(
        const char* const u, 
        const char* const a, 
        const char* const pk, 
        const char* const v, 
        int pb, 
        int mb
    ) : username(), address(a), publicKey(pk), vote(v), producedblocks(pb), missedblocks(mb) {
        strncpy(username, u, sizeof(username) / sizeof(username[0]));
    }

    void description(char* const buf, size_t size);
  };
/*  =======================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  =========================================  */
  /*  ARK::API::Delegate::Respondable::Voters  */
struct Voters {
public:
    size_t count;
    ARK::Voter* const _voters;

    Voters(size_t c) : count(c), _voters(new ARK::Voter[c]) { }
    ~Voters() {
        delete [] _voters;
    }

    const Voter& operator[](size_t index) const { return _voters[index]; }
    Voter& operator[](size_t index) { return _voters[index]; }

    void description(char* const buf, size_t size);
};
/*  =========================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==================================================  */
  /*  ARK::API::Delegate::Respondable::ForgedByAccount  */
struct ForgedByAccount
{
public:
    Balance fees;
    Balance rewards;
    Balance forged;

    ForgedByAccount(const char* const f, const char* const r, const char* const fg) : fees(f), rewards(r), forged(fg) { }

    void description(char* const buf, size_t size);
};
/*  ==================================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==============================================  */
  /*  ARK::API::Delegate::Respondable::NextForgers  */
  struct NextForgers
  {
    public:
      char currentBlock[64];
      char currentSlot[64];
      Publickey delegates[10];

      NextForgers(const char* const _currentBlock, const char* const _currentSlot, const Publickey* const _delegates);

      void description(char* const buf, size_t size);
  };
/*  ==============================================  */
/*  ==========================================================================  */

};
};
};
};


/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Delegate::Respondable::Search  */
/*  Description  */
void ARK::API::Delegate::Respondable::Search::description(char* const buf, size_t size)
{
    strcpy(buf, "username: ");
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote.ark());
    strcat(buf, "\nproducedblocks: ");
    auto len = strlen(buf);
    sprintf(buf + len, "%d", this->producedblocks);
    strcat(buf, "\nmissedblocks: ");
    len = strlen(buf);
    sprintf(buf + len, "%d", this->missedblocks);
}
/*  =======================================  */
/*  ==========================================================================  */



/*  =========================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::Voters::description(char* const buf, size_t size) {
  if (this->count > 0) {
      buf[0] = '\0';
    for (int i = 0; i < this->count; i++) {
        strcat(buf, "\nvoter ");
        auto len = strlen(buf);
        sprintf(buf + len, "%d", i + 1);
        strcat(buf, ":\n");
        len = strlen(buf);
        (*this)[i].description(buf + len, size - len);
        strcat(buf, "\n");
    };
  };
}
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==================================================  */
/*  ARK::API::Delegate::Respondable::ForgedByAccount  */
/*  Description  */
void ARK::API::Delegate::Respondable::ForgedByAccount::description(char* const buf, size_t size)
{
    strcpy(buf, "fees.ark: ");
    strcat(buf, this->fees.ark());
    strcat(buf, "\nrewards.ark: ");
    strcat(buf, this->rewards.ark());
    strcat(buf, "\nforged.ark: ");
    strcat(buf, this->forged.ark());
}
/*  ==================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Delegate::Respondable::NextForgers  */
/*  Constructor  */
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
    const char* const _currentBlock, const char* const _currentSlot,
    const Publickey* const _delegates) : currentBlock(), currentSlot()
{
    //TODO:  wish i had std::array for _delegates.  pointer decay sucks.
    strncpy(this->currentBlock, _currentBlock, sizeof(this->currentBlock));
    strncpy(this->currentSlot, _currentSlot, sizeof(this->currentSlot));
	for (auto i = 0; i < 10; ++i)
	{
		this->delegates[i] = _delegates[i];
	};
}
/*  ============================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::NextForgers::description(char* const buf, size_t size)
{
    strcpy(buf, "currentBlock: ");
    strcat(buf, this->currentBlock);
    strcat(buf, "\ncurrentSlot: ");
    strcat(buf, this->currentSlot);
    strcat(buf, "\n");

	for (auto i = 0; i < 10; ++i)
	{
        strcat(buf, "delegate ");
        const auto len = strlen(buf);
        sprintf(buf + len, "%d", i + 1);
        strcat(buf, ": \n publicKey: ");
        strcat(buf, delegates[i].description());
        strcat(buf, "\n");
	};
}
/*  ============================================  */
/*  ==========================================================================  */


#endif
