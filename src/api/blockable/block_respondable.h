

#ifndef BLOCK_RESPONDABLE_H
#define BLOCK_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{

/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Status  */
  struct Status
  {
    public:
      String epoch;
      String height;
      Balance fee;
      int milestone;
      Hash nethash;
      Balance reward;
      Balance supply;

      String description();
  };
/*  ====================================  */
/*  ================================================  */


/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Definition  */
  struct Height
  {
    public:
      String height;
      String id;

      String description();
  };
/*  ====================================  */
/*  ==========================================================================  */

};
};
};
};




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Status  */
/*  Description  */
String ARK::API::Block::Respondable::Status::description()
{
	String resp;
	resp += "epoch: ";
	resp += this->epoch;
	resp += "\n";
	resp += "height: ";
	resp += this->height;
	resp += "\n";
	resp += "fee.ark: ";
	resp += this->fee.ark;
	resp += "\n";
	resp += "milestone: ";
	resp += this->milestone;
	resp += "\n";
	resp += "nethash.description: ";
	resp += this->nethash.description();
	resp += "\n";
	resp += "reward.ark: ";
	resp += this->reward.ark;
	resp += "\n";
	resp += "supply.ark: ";
	resp += this->supply.ark;
	return resp;
}
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Description  */
String ARK::API::Block::Respondable::Height::description()
{
	String resp;
	resp += "height: ";
	resp += this->height;
	resp += "\n";
	resp += "id: ";
	resp += this->id;
	return resp;
}
/*  ====================================  */
/*  ==========================================================================  */


#endif