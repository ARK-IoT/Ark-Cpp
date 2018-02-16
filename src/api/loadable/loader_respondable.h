

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
*	ARK::API::Loader::Respondable::Status
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
  struct Status {
    public:
      bool loaded;
      int now;
			const char* blocksCount;

      void printTo(HardwareSerial &serial);
  };
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Loader::Respondable::Sync 
*
*   @variables:
*			bool syncing;
*			int blocks;
*			const char* height;
*			const char* id;
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Loader Sync API Response
*
**************************************************/
  struct Sync {
    public:
      bool syncing;
      int blocks;
			const char* height;
			const char* id;

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
