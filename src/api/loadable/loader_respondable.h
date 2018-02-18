

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


  /*************************************************
  *	ARK::API::Loader::Respondable::status_t
  *
  *   @variables:
  *			bool loaded;
  *			int now;
  *			char blocksCount[64];
  *
  *   @description:
  *			Model for Loader Status API Response
  *
  **************************************************/
  struct status_t
  {
    public:
      bool loaded;
      int now;
			char blocksCount[32];
  };
  /*************************************************/


  /*************************************************
  *	ARK::API::Loader::Respondable::Status
  *
  *   @inherits:
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
  struct Status :
      public status_t
  {
    Status(
      bool newLoaded,
      int newNow,
      const char* const newBlocksCount
    )
    {
      loaded = newLoaded;
      now = newNow;
      strncpy(blocksCount, newBlocksCount, sizeof(blocksCount) / sizeof(blocksCount[0]));
    };

    void printTo(HardwareSerial &serial);
  };
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Loader::Respondable::sync_t 
*
*   @variables:
*			bool syncing;
*			int blocks;
*			char height[32];
*			char id[32];
*
*   @description:
*			Model for Loader Sync API Response
*
**************************************************/
  struct sync_t
  {
    public:
      bool syncing;
      int blocks;
			char height[32];
			char id[32];
  };
/*************************************************/


/*************************************************
*	ARK::API::Loader::Respondable::Sync 
*
*   @inherits:
*			bool syncing;
*			int blocks;
*			char height[32];
*			char id[32];
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Loader Sync API Response
*
**************************************************/
  struct Sync :
      public sync_t
  {
    Sync(
      bool newSyncing,
      int newBlocks,
      const char* const newHeight,
      const char* const newID
    )
    {
      this->syncing = newSyncing;
      this->blocks = newBlocks;
      strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
      strncpy(id, newID, sizeof(id) / sizeof(id[0]));
    };

    void printTo(HardwareSerial &serial);
  };
/*************************************************/

};
};
};
};


/*************************************************
*	ARK::API::Loader::Respondable::Status
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Loader Status Response to Serial
*
**************************************************/
void ARK::API::Loader::Respondable::Status::printTo(HardwareSerial &serial)
{
  serial.print("\nloaded: ");
    serial.print(this->loaded ? "true" : "false");
  serial.print("\nnow: ");
    serial.print(this->now);
  serial.print("\nblocksCount: ");
    serial.print(this->blocksCount);
  serial.print("\n");
  serial.flush();
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Loader::Respondable::Sync
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Loader Sync Response to Serial
*
**************************************************/
void ARK::API::Loader::Respondable::Sync::printTo(HardwareSerial &serial)
{
  serial.print("\nsyncing: ");
    serial.print(this->syncing ? "true" : "false");
  serial.print("\nblocks: ");
    serial.print(this->blocks);
  serial.print("\nheight: ");
    serial.print(this->height);
  serial.print("\nid: ");
    serial.print(this->id);
  serial.print("\n");
  serial.flush();
};
/*************************************************/


#endif
