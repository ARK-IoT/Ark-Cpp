

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


/*  ==========================================================================  */
/*  =====================================================  */
/*  ARK::API::Account::Respondable::Balances::description  */
/*  Description  */
  void ARK::API::Account::Respondable::Balances::description(char* const buf, size_t size)
  {
      strcpy(buf, "confirmed balance.ark: ");
      strcat(buf, this->confirmed.ark());
      strcat(buf, "\nconfirmed balance.arktoshi: ");
      strcat(buf, this->confirmed.arktoshi());
      strcat(buf, "\n\nunconfirmed balance.ark: ");
      strcat(buf, this->unconfirmed.ark());
      strcat(buf, "\nunconfirmed balance.arktoshi: ");
      strcat(buf, this->unconfirmed.arktoshi());
  }
/*  =====================================================  */
/*  ==========================================================================  */



#endif