

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
*		ARK::API::Loader::Respondable::status_t
*
*   @param:	bool loaded, int now, char blocksCount[64]
*
*   @brief:	Model for Loader Status API Response
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
*   @param: bool loaded, int now, char blocksCount[64]
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief:	Model for Loader Status API Response
**************************************************/
struct Status :
		public status_t, Printable
{
	public:

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

    virtual size_t printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("loaded: ");
        size += p.print(this->loaded ? "true" : "false");
        size += p.print("\nnow: ");
        size += p.print(this->now);
        size += p.print("\nblocksCount: ");
        size += p.print(this->blocksCount);
      return size;
    };

};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*		ARK::API::Loader::Respondable::sync_t 
*
*   @param:	bool syncing, int blocks, char height[32], char id[32];
*
*   @brief:	Model for Loader Sync API Response
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
*		ARK::API::Loader::Respondable::Sync 
*
*   @param:	bool syncing, int blocks, char height[32], char id[32]
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief:	Model for Loader Sync API Response
**************************************************/
struct Sync :
    public sync_t, Printable
{
  public:

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

    virtual size_t printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("syncing: ");
        size += p.print(this->syncing ? "true" : "false");
        size += p.print("\nblocks: ");
        size += p.print(this->blocks);
        size += p.print("\nheight: ");
        size += p.print(this->height);
        size += p.print("\nid: ");
        size += p.print(this->id);
      return size;
    }
};
/*************************************************/

};
};
};
};

#endif
