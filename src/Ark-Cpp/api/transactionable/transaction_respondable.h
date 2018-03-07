

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
*	  ARK::API::Transaction::Respondable::Unconfirmed
*
*   @param: bool loaded, int now, char blocksCount[64];
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief: Model for Loader Status API Response
**************************************************/
struct Unconfirmed :
    public Printable
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

    ~Unconfirmed() { delete [] transactions; };

    /*************************************************
    *	  ARK::API::Transaction::Respondable::Unconfirmed 
    *
    *   @methods:	printTo(HardwareSerial &serial)
    *
    *   @brief: Prints API Transaction Unconfirmed Response to Serial
    **************************************************/
    virtual size_t printTo(Print& p) const
    {
      size_t size = 0;

        if (this->count == 0)
        {
          size += p.print("There are currently no Unconfirmed Transactions");
        }
        else
        {
          for (int i = 0; i < this->count; i++)
          {
            size += p.print("\ntransaction ");
            size += p.print(i + 1);
            size += p.print(":\n");
            size += p.print(this->transactions[i]);
          };
        };
      return size;
    };  
    /*************************************************/

};
/*************************************************/

};
};
};
};

#endif
