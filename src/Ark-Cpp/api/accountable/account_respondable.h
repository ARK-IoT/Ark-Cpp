

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
/*************************************************
*	  ARK::API::Account::Respondable::balances_t
*
*   @param:
*			Balance confirmed
*			Balance confirmed
*
*   @brief:
*			Model for Balances API Response
**************************************************/
struct balances_t
{
public:
  Balance confirmed;
  Balance unconfirmed;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @brief:
*     Constructed API Balances Response Object
*
**************************************************/
struct Balances :
    public Printable,
    virtual balances_t
{
  public:

    /*************************************************
    *		ARK::API::Account::Respondable::Balances
    *
    *   @brief:
    *     Empty Initialization
    **************************************************/
    Balances() {};


    /*************************************************
    *		ARK::API::Account::Respondable::Balances(const char* const, const char* const)
    *
    *   @brief:
    *     Constructed API Balances Response Object
    **************************************************/
    Balances( const char* const newConfirmed, const char* const newUnconfirmed)
    {
      this->confirmed = Balance(newConfirmed);
      this->unconfirmed = Balance(newUnconfirmed);
    }


    /*************************************************
    *   printTo(HardwareSerial &serial)
    *
    *   @brief:
    *     Prints balances_t items
    **************************************************/
    virtual size_t printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("\nconfirmed balance.ark: ");
        size += p.print(this->confirmed.ark());
        size += p.print("\nconfirmed balance.arktoshi: ");
        size += p.print(this->confirmed.arktoshi());
        size += p.print("\n\nunconfirmed balance.ark: ");
        size += p.print(this->unconfirmed.ark());
        size += p.print("\nunconfirmed balance.arktoshi: ");
        size += p.print(this->unconfirmed.arktoshi());
      return size;
    };


};
/*************************************************/

};
};
};
};

#endif
