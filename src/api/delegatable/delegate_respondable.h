

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

#include "address.h"
#include "publickey.h"
#include "balance.h"
#include "voter.h"

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


#endif
