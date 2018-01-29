

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

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

      String description();
  };
/*  ======================================  */
/*  ==========================================================================  */

};
};
};
};


/*  ==========================================================================  */
/*  =====================================================  */
/*  ARK::API::Account::Respondable::Balances::description  */
/*  Description  */
  String ARK::API::Account::Respondable::Balances::description()
  {
    String resp;
    resp += "confirmed balance.ark: ";
    resp += this->confirmed.ark;
    resp += "\n";
    resp += "confirmed balance.arktoshi: ";
    resp += this->confirmed.arktoshi;
    resp += "\n\n";
    resp += "unconfirmed balance.ark: ";
    resp += this->unconfirmed.ark;
    resp += "\n";
    resp += "unconfirmed balance.arktoshi: ";
    resp += this->unconfirmed.arktoshi;
    return resp;
  }
/*  =====================================================  */
/*  ==========================================================================  */



#endif