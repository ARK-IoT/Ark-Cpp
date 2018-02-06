

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
      char epoch[64] = {'\0'};  //TODO: check sizes
      char height[64] = {'\0'};
      Balance fee;
      int milestone;
      Hash nethash;
      Balance reward;
      Balance supply;

      void description(char* const buf, size_t size);
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
      char height[64] = {'\0' }; // TODO: check sizes 
      char id[64] = { '\0' };

      void description(char* const buf, size_t size);
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
void ARK::API::Block::Respondable::Status::description(char* const buf, size_t size)
{
    strcpy(buf, "epoch: ");
    strcat(buf, this->epoch);
    strcat(buf, "\nheight: ");
    strcat(buf, this->height);
    strcat(buf, "\nfee.ark: ");
    strcat(buf, this->fee.ark());
    strcat(buf, "\nmilestone: ");
    strcat(buf, this->milestone);
    strcat(buf, "\nnethash.description: ");
    strcat(buf, this->nethash.description());
    strcat(buf, "\nreward.ark: ");
    strcat(buf, this->reward.ark());
    strcat(buf, "\supply.ark: ");
    strcat(buf, this->supply.ark);
}
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Description  */
void ARK::API::Block::Respondable::Height::description(char* const buf, size_t size)
{
    strcpy(buf, "height: ");
    strcat(buf, this->height);
    strcat(buf, "\nid: ");
    strcat(buf, this->id);
}
/*  ====================================  */
/*  ==========================================================================  */


#endif