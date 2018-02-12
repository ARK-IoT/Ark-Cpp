#include "account_respondable.h"

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
