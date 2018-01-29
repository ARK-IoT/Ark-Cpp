

#ifndef LOADER_RESPONDABLE_H
#define LOADER_RESPONDABLE_H


namespace ARK
{
namespace API
{
namespace Loader
{
namespace Respondable
{

/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Status  */
  struct Status {
    public:
      bool loaded;
      int now;
      String blocksCount;

      String description();
  };
/*  ============  */
/*  ================================================  */


/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Sync  */
  struct Sync {
    public:
      bool syncing;
      int blocks;
      String height;
      String id;

      String description();
  };
/*  ============  */
/*  ================================================  */

};
};
};
};




/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Status  */
/*  Description  */
String ARK::API::Loader::Respondable::Status::description()
{
  String resp;
  resp += "loaded: ";
  resp += this->loaded;
  resp += "\n";
  resp += "now: ";
  resp += this->now;
  resp += "\n";
  resp += "blocksCount: ";
  resp += this->blocksCount;
  return resp;
};
/*  ============  */
/*  ================================================  */




/*  ================================================  */
/*  ============  */
/*  ARK::Loader::Loader::Sync  */
/*  Description  */
String ARK::API::Loader::Respondable::Sync::description()
{
  String resp;
  resp += "syncing: ";
  resp += this->syncing;
  resp += "\n";
  resp += "blocks: ";
  resp += this->blocks;
  resp += "\n";
  resp += "height: ";
  resp += this->height;
  resp += "\n";
  resp += "id: ";
  resp += this->id;
  return resp;
};
/*  ============  */
/*  ================================================  */


#endif
