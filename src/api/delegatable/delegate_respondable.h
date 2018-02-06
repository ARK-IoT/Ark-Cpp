

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
   char username[64] = { '\0' }; //TODO review sizes
    Address address;
    Publickey publicKey;
    Balance vote;
    int producedblocks;
    int missedblocks;

    void description(char* const buf, size_t size);
  };
/*  =======================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  =========================================  */
  /*  ARK::API::Delegate::Respondable::Voters  */
  struct Voters {
    public:

      int count;
      ARK::Voter list[10];// = {{}};

      Voters(int);

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
      char currentBlock[64] = {'\0'};
      char currentSlot[64] = { '\0' };
      Publickey delegates[10];

      NextForgers(const char* const _currentBlock, const char* const _currentSlot, Publickey _delegates[10]);

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
    strcat(buf, this->producedblocks);
    strcat(buf, "\nmissedblocks: ");
    strcat(buf, this->missedblocks);
}
/*  =======================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =========================================  */
  /*  ARK::API::Delegate::Respondable::Voters  */
/*  Constructor  */
ARK::API::Delegate::Respondable::Voters::Voters(int _count){
  this->count = _count;
}
/*  =========================================  */
/*  Description  */
void ARK::API::Delegate::Respondable::Voters::description(char* const buf, size_t size) {
  if (this->count > 0) {
    for (int i = 0; i < this->count; i++) {
      resp += "\nvoter ";
      resp += i + 1;
      resp += ":\n";
      resp += this->list[i].description();
      resp += "\n";
    };
  };
  return resp;
}
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==================================================  */
/*  ARK::API::Delegate::Respondable::ForgedByAccount  */
/*  Description  */
String ARK::API::Delegate::Respondable::ForgedByAccount::description()
{
	String resp;
	resp += "fees.ark: ";
	resp += this->fees.ark;
	resp += "\n";
	resp += "rewards.ark: ";
	resp += this->rewards.ark;
	resp += "\n";
	resp += "forged.ark: ";
	resp += this->forged.ark;
	return resp;
}
/*  ==================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Delegate::Respondable::NextForgers  */
/*  Constructor  */
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
    String _currentBlock, String _currentSlot,
    Publickey _delegates[10])
{
	this->currentBlock = _currentBlock;
	this->currentSlot = _currentSlot;
	for (int i = 0; i < 10; i++)
	{
		this->delegates[i] = _delegates[i];
	};
}
/*  ============================================  */
/*  Description  */
String ARK::API::Delegate::Respondable::NextForgers::description()
{
	String resp;
	resp += "currentBlock: ";
	resp += this->currentBlock;
	resp += "\n";
	resp += "currentSlot: ";
	resp += this->currentSlot;
	resp += "\n";
	for (int i = 0; i < 10; i++)
	{
		resp += "delegate ";
		resp += i + 1;
		resp += ": \n publicKey: ";
		resp += delegates[i].description();
		resp += "\n";
	};
	return resp;
}
/*  ============================================  */
/*  ==========================================================================  */


#endif
