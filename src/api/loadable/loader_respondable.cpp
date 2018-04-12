#include "api/loadable/loader_respondable.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
namespace API
{
namespace Loader
{
namespace Respondable
{

/*************************************************
*	Constructor
**************************************************/
Status::Status(
		bool 							newLoaded,
		int 							newNow,
		const char *const newBlocksCount
)
{
	this->loaded_ = newLoaded;
	this->now_ = newNow;
	strncpy(this->blocksCount_, newBlocksCount, sizeof(blocksCount_) / sizeof(blocksCount_[0]));
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Status::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("loaded: ");
		size += p.print(this->loaded_ ? "true" : "false");
		size += p.print("\nnow: ");
		size += p.print(this->now_);
		size += p.print("\nblocksCount: ");
		size += p.print(this->blocksCount_);
	return size;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	Constructor
**************************************************/
Sync::Sync(
		bool 							newSyncing,
		int 							newBlocks,
		const char *const newHeight,
		const char *const newID
)
{
	this->syncing_ = newSyncing;
	this->blocks_ = newBlocks;
	strncpy(height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(id_, newID, sizeof(id_) / sizeof(id_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Sync::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("syncing: ");
		size += p.print(this->syncing_ ? "true" : "false");
		size += p.print("\nblocks: ");
		size += p.print(this->blocks_);
		size += p.print("\nheight: ");
		size += p.print(this->height_);
		size += p.print("\nid: ");
		size += p.print(this->id_);
	return size;
};
/*************************************************/

};
};
};
};
