#include "api/blockable/block_respondable.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{

/*************************************************
* Constructor
**************************************************/
Height::Height(
    const char *const newHeight,
    const char *const newID
)
{
  strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
  strncpy(this->id_, newID, sizeof(id_) / sizeof(id_[0]));
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Height::printTo(Print &p) const
{
  size_t size = 0;
		size += p.print("\nheight: ");
		size += p.print(this->height_);
		size += p.print("\nid: ");
		size += p.print(this->id_);
  return size;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Constructor
**************************************************/
Status::Status(
    const char *const newEpoch,
    const char *const newHeight,
    const char *const newFee,
    int               newMilestone,
    const char *const newNethash,
    const char *const newReward,
    const char *const newSupply)
{
  strncpy(this->epoch_, newEpoch, sizeof(epoch_) / sizeof(epoch_[0]));
  strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
  this->fee_ = Balance(newFee);
  this->milestone_ = newMilestone;
  this->nethash_ = Hash(newNethash);
  this->reward_ = Balance(newReward);
  this->supply_ = Balance(newSupply);
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Status::printTo(Print &p) const
{
  size_t size = 0;
    size += p.print("\nepoch: ");
    size += p.print(this->epoch_);

    size += p.print("\nheight: ");
    size += p.print(this->height_);

    size += p.print("\nfee: ");
    size += p.print(this->fee_.ark());

    size += p.print("\nmilestone: ");
    size += p.print(this->milestone_);

    size += p.print("\nnethash: ");
    size += p.print(this->nethash_);

    size += p.print("\nreward: ");
    size += p.print(this->reward_.ark());

    size += p.print("\nsupply: ");
    size += p.print(this->supply_.ark());
  return size;
};
/*************************************************/

};
};
};
};
