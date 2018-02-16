

#ifndef TRANSACTION_RESPONDABLE_H
#define TRANSACTION_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Transaction
{
namespace Respondable
{

  /*************************************************
  *	ARK::API::Transaction::Respondable::Unconfirmed
  *
  *   @variables:
  *			bool loaded;
  *			int now;
  *			char blocksCount[64];
  *
  *   @methods:	printTo(HardwareSerial &serial)
  *
  *   @description:
  *			Model for Loader Status API Response
  *
  **************************************************/
  struct Unconfirmed
  {
    private:
      int count;

    public:
		  ARK::Transaction* transactions = new ARK::Transaction[5];

      Unconfirmed(
          const ARK::Transaction* const tx,
          int c)
      {
        this->count = c;
        this->transactions = new ARK::Transaction[this->count];
        for (int i = 0; i < count; ++i)
        {
          this->transactions[i] = tx[i];
        };
      };

      ~Unconfirmed() {
        delete [] transactions;
      };

      void printTo(HardwareSerial &serial);
  };
  /*************************************************/

};
};
};
};


/*************************************************
*	ARK::API::Transaction::Respondable::Unconfirmed 
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Transaction Unconfirmed Response to Serial
*
**************************************************/
void ARK::API::Transaction::Respondable::Unconfirmed::printTo(HardwareSerial &serial)
{
  if (this->count == 0)
  {
    serial.print("There are currently no Unconfirmed Transactions");
  }
  else
  {
    for (int i = 0; i < this->count; i++) {
      serial.print("\ntransaction ");
      serial.print(i + 1);
      serial.print(":\n");
      this->transactions[i].printTo(serial);
      serial.print("\n");
      serial.flush();
    };
  };
};
/*************************************************/


#endif
