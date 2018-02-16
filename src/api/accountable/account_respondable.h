

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
*	ARK::API::Account::Respondable::balances_t
*
*   @variables:
*			Balance confirmed
*			Balance confirmed
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Balances API Response
*
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
*		ARK::API::Account::Respondable::balance_printable
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Model for printing balances_t items to Serial
*
**************************************************/
struct balance_printable : virtual balances_t
{ 
  void printTo(HardwareSerial &serial);
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @description:
*     Constructed API Balances Response Object
*
**************************************************/
struct Balances : virtual balances_t, balance_printable
{
public:
  Balances();
  Balances(const Balance &c, const Balance &u);
};
/*************************************************/


};
};
};
};


/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @constructor
*
*   @description:
*     Constructed API Balances Response Object
*
**************************************************/
ARK::API::Account::Respondable::Balances::Balances(const Balance &c, const Balance &u)
{
  this->confirmed = c;
  this->unconfirmed = u;
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @constructor
*
*   @description:
*     Empty Initialization
*
**************************************************/
ARK::API::Account::Respondable::Balances::Balances() {};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*		ARK::API::Account::Respondable::balance_printable
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints balances_t items to Serial
*
**************************************************/
void ARK::API::Account::Respondable::balance_printable::printTo(HardwareSerial &serial)
{
    serial.print("\nconfirmed balance.ark: ");
    serial.print(this->confirmed.ark());
    serial.print("\nconfirmed balance.arktoshi: ");
    serial.print(this->confirmed.arktoshi());
    serial.print("\n\nunconfirmed balance.ark: ");
    serial.print(this->unconfirmed.ark());
    serial.print("\nunconfirmed balance.arktoshi: ");
    serial.print(this->unconfirmed.arktoshi());
    serial.print("\n");
    serial.flush();
};
/*************************************************/


#endif