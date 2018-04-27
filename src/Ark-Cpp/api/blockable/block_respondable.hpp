

#ifndef BLOCK_RESPONDABLE_HPP
#define BLOCK_RESPONDABLE_HPP

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{
/*************************************************
*	  ARK::API::Block::Respondable::height_t 
*   @param: char height[64], char id[64]
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief: Model for Height API Response
**************************************************/
struct height_t
{
public:
  char height[64];
  char id[64];
};
/*************************************************/

/*************************************************
*	  ARK::API::Block::Respondable::Height 
*   inherits:
*			const char* height
*			const char* id
*   printTo(HardwareSerial &serial)
*
*   @brief: Model for Height API Response
**************************************************/
struct Height : public height_t, Printable
{
public:
  Height(
      const char *const newHeight,
      const char *const newID)
  {
    strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
    strncpy(id, newID, sizeof(id) / sizeof(id[0]));
  }

  /*************************************************
    *
    **************************************************/
  virtual size_t printTo(Print &p) const
  {
    size_t size = 0;
    size += p.print("\nheight: ");
    size += p.print(this->height);
    size += p.print("\nid: ");
    size += p.print(this->id);
    return size;
  };
  /*************************************************/
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	  ARK::API::Block::Respondable::status_t 
*
*		@param:
*     const char* epoch,
*     const char* height,
*     const Balance fee,
*     int milestone,
*     Hash nethash,
*     const Balance reward,
*     const Balance supply;
*
*   @brief:
*			Model for Block Status API Response
*
**************************************************/
struct status_t
{
public:
  char epoch[64]; //TODO: check sizes
  char height[64];
  Balance fee;
  int milestone;
  Hash nethash;
  Balance reward;
  Balance supply;
};
/*************************************************/

/*************************************************
*	ARK::API::Block::Respondable::Status 
*
*		inherits:
*			const char* epoch;
*			const char* height;
*			const Balance fee;
*			int milestone;
*			Hash nethash;
*			const Balance reward;
*			const Balance supply;
*
*   printTo(HardwareSerial &serial)
*
*   @brief: Constructor Model for Block Status API Response
**************************************************/
struct Status : public status_t, Printable
{
public:
  Status(
      const char *const newEpoch,
      const char *const newHeight,
      const char *const newFee,
      int newMilestone,
      const char *const newNethash,
      const char *const newReward,
      const char *const newSupply)
  {
    strncpy(epoch, newEpoch, sizeof(epoch) / sizeof(epoch[0]));
    strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
    fee = Balance(newFee);
    milestone = newMilestone;
    nethash = Hash(newNethash);
    reward = Balance(newReward);
    supply = Balance(newSupply);
  };

  /*************************************************
  *
  **************************************************/
  virtual size_t printTo(Print &p) const
  {
    size_t size = 0;
    size += p.print("\nepoch: ");
    size += p.print(this->epoch);

    size += p.print("\nheight: ");
    size += p.print(this->height);

    size += p.print("\nfee: ");
    size += p.print(this->fee.ark());

    size += p.print("\nmilestone: ");
    size += p.print(this->milestone);

    size += p.print("\nnethash: ");
    size += p.print(this->nethash);

    size += p.print("\nreward: ");
    size += p.print(this->reward.ark());

    size += p.print("\nsupply: ");
    size += p.print(this->supply.ark());
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
