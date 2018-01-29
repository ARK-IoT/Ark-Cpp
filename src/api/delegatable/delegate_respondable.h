

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
    String username;
    Address address;
    Publickey publicKey;
    Balance vote;
    int producedblocks;
    int missedblocks;

    String description();
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

      String description();
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

      String description();
  };
/*  ==================================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==============================================  */
  /*  ARK::API::Delegate::Respondable::NextForgers  */
  struct NextForgers
  {
    public:
      String currentBlock;
      String currentSlot;
      Publickey delegates[10];

      NextForgers(String _currentBlock, String _currentSlot, Publickey _delegates[10]);

      String description();
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
String ARK::API::Delegate::Respondable::Search::description()
{
	String resp;
	resp += "username: ";
	resp += this->username;
	resp += "\n";
	resp += "address.description: ";
	resp += this->address.description();
	resp += "\n";
	resp += "publicKey.description: ";
	resp += this->publicKey.description();
	resp += "\n";
	resp += "vote.ark: ";
	resp += this->vote.ark;
	resp += "\n";
	resp += "producedblocks: ";
	resp += this->producedblocks;
	resp += "\n";
	resp += "missedblocks: ";
	resp += this->missedblocks;
	return resp;
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
String ARK::API::Delegate::Respondable::Voters::description() {
  String resp;

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
