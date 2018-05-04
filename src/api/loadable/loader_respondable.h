

#ifndef LOADER_RESPONDABLE_H
#define LOADER_RESPONDABLE_H

#include "utilities/platform.h"
#include <cstdio>
#include <cstring>

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
*	@param:	bool loaded
*	@param:	int now
*	@param:	char blocksCount[64]
*
*	@brief:	Model for Loader Status API Response
**************************************************/
struct status_t
{
	protected:
		bool	loaded_;
		int 	now_;
		int		blocksCount_;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Loader::Respondable::Status
*
*	@param: bool loaded
*	@param: int now
*	@param: char blocksCount[64]
*
*	@brief:	Model for Loader Status API Response
**************************************************/
struct Status :
		public status_t,
		Printable
{
public:
	/*************************************************
	*	Constructor
	**************************************************/
	Status(
			bool	newLoaded,
			int		newNow,
			int		newBlocksCount
	);
	/*************************************************/

	/*************************************************
	*	Accessors
	**************************************************/
	bool loaded() const noexcept { return loaded_; }
	int now() const noexcept { return now_; }
	int blocks_count() const noexcept { return blocksCount_; }
	/*************************************************/

	/*************************************************
	*
	**************************************************/
	virtual size_t printTo(Print &p) const;
	/*************************************************/

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::API::Loader::Respondable::sync_t 
*
*	@param:	bool syncing
*	@param:	int blocks
*	@param:	char height[32]
*	@param:	char id[32];
*
*	@brief:	Model for Loader Sync API Response
**************************************************/
struct sync_t
{
	protected:
		bool	syncing_;
		int 	blocks_;
		char	height_[32];
		char	id_[32];
};
/*************************************************/

/*************************************************
*	ARK::API::Loader::Respondable::Sync 
*
*	@param:	bool syncing
*	@param:	int blocks
*	@param:	char height[32]
*	@param:	char id[32]
*
*	@brief:	Model for Loader Sync API Response
**************************************************/
struct Sync :
		public sync_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Sync(
				bool							newSyncing,
				int								newBlocks,
				const char *const newHeight,
				const char *const newID
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		bool syncing() const noexcept { return syncing_; }
		int blocks() const noexcept { return blocks_; }
		const char* height() const noexcept { return height_; }
		const char* id() const noexcept { return id_; }
		/*************************************************/
		
		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/
		
};
/*************************************************/

};
};
};
};

#endif
