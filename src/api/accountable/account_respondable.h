

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

#include "balance.h"

namespace ARK
{
namespace API
{
namespace Account
{
namespace Respondable
{

/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Respondable::Balance  */
  struct Balances {
    public:
        Balance confirmed;
        Balance unconfirmed;

        Balances() { }
        Balances(const Balance& c, const Balance& u) : confirmed(c), unconfirmed(u) { }

        void description(char* const buf, size_t size);
  };
/*  ======================================  */
/*  ==========================================================================  */

};
};
};
};

#endif