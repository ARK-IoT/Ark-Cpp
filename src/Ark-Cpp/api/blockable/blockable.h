

#ifndef BLOCKABLE_H
#define BLOCKABLE_H

#include "block_respondable.h"
#include "block_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Blockable
*   	public Block::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Block Model
* 
**************************************************/
class Blockable :
		public Block::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*		/api/blocks/get?id=_blockID
		*
		*		@uri:	/api/blocks/get?id=_blockID
		*		@returnType:	ARK::Block
		*
		*   @method:	block(const char* const blockId)
		*   @parameter:		const char* const blockId
		*
		*   @outs:	ARK::API::Block::Gettable::block(this->netConnector, blockId)
		*
		*   @description:
		*			Uses Block ID to get that Blocks information 
		*			from a Node via API.
		* 
		**************************************************/
		ARK::Block block(const char* const blockId)
		{
			return ARK::API::Block::Gettable::block(this->netConnector, blockId);
		};
    /*************************************************/

/**************************************************************************************************/

    /*************************************************/
		/*************************************************
    * 	BROKEN: fix for large callbacks
		*		blocks callback is ~63,712 bytes
    **************************************************/
		/*************************************************/
		/*************************************************
    * /api/blocks
    **************************************************/
		// String blocks()
		// { return ARK::API::Block::Gettable::blocks(this->netConnector); };
    /*************************************************/
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getEpoch
		*
		*		@uri:	/api/blocks/getEpoch
		*		@returnType:	const char*
		*
		*   @method:	blockEpoch()
		*
		*   @outs:	ARK::API::Block::Gettable::epoch(this->netConnector)
		*
		*   @description:
		*			Gets the Block Epoch from a Node via API.
		* 
		**************************************************/
		const char* blockEpoch()
		{
			return ARK::API::Block::Gettable::epoch(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getHeight
		*
		*		@uri:	/api/blocks/getHeight
		*		@returnType:	ARK::API::Block::Respondable::Height
		*
		*   @method:	blockHeight()
		*
		*   @outs:	ARK::API::Block::Gettable::height(this->netConnector)
		*
		*   @description:
		*			Gets the Block-Height from a Node via API.
		* 
		**************************************************/
		ARK::API::Block::Respondable::Height blockHeight()
		{
			return ARK::API::Block::Gettable::height(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getNethash
		*
		*		@uri:	/api/blocks/getNethash
		*		@returnType:	Hash
		*
		*   @method:	blockNethash()
		*
		*   @outs:	ARK::API::Block::Gettable::nethash(this->netConnector)
		*
		*   @description:
		*			Gets the Networks Hash from a Node via API.
		* 
		**************************************************/
		Hash blockNethash()
		{
			return ARK::API::Block::Gettable::nethash(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getFee
		*
		*		@uri:	/api/blocks/getFee
		*		@returnType:	Balance
		*
		*   @method:	blockFee()
		*
		*   @outs:	ARK::API::Block::Gettable::fee(this->netConnector)
		*
		*   @description:
		*			Gets the Block-Fee from a Node via API.
		* 
		**************************************************/
		Balance blockFee()
		{
			return ARK::API::Block::Gettable::fee(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getFees
		*
		*		@uri:	/api/blocks/getFees
		*		@returnType:	ARK::Fees
		*
		*   @method:	blockFees()
		*
		*   @outs:	ARK::API::Block::Gettable::fees(this->netConnector)
		*
		*   @description:
		*			Gets Ark Network Fees from a Node via API.
		* 
		**************************************************/
		ARK::Fees blockFees()
		{
			return ARK::API::Block::Gettable::fees(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getMilestone
		*
		*		@uri:	/api/blocks/getMilestone
		*		@returnType:	const char*
		*
		*   @method:	blockMilestone()
		*
		*   @outs:	ARK::API::Block::Gettable::milestone(this->netConnector)
		*
		*   @description:
		*			Gets the Block Milestone from a Node via API.
		* 
		**************************************************/
		const char* blockMilestone()
		{
			return ARK::API::Block::Gettable::milestone(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getReward
		*
		*		@uri:	/api/blocks/getReward
		*		@returnType:	Balance
		*
		*   @method:	blockReward()
		*
		*   @outs:	ARK::API::Block::Gettable::reward(this->netConnector)
		*
		*   @description:
		*			Gets the Block Reward from a Node via API.
		* 
		**************************************************/
		Balance blockReward()
		{
			return ARK::API::Block::Gettable::reward(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getSupply
		*
		*		@uri:	/api/blocks/getSupply
		*		@returnType:	Balance
		*
		*   @method:	blockSupply()
		*
		*   @outs:	ARK::API::Block::Gettable::supply(this->netConnector)
		*
		*   @description:
		*			Gets the current Ark Supply from a Node via API.
		* 
		**************************************************/
		Balance blockSupply()
		{
			return ARK::API::Block::Gettable::supply(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/blocks/getStatus
		*
		*		@uri:	/api/blocks/getStatus
		*		@returnType:	ARK::API::Block::Respondable::Status
		*
		*   @method:	blockStatus()
		*
		*   @outs:	ARK::API::Block::Gettable::status(this->netConnector)
		*
		*   @description:
		*			Gets the Ark Networks Status from a Node via API.
		* 
		**************************************************/
		ARK::API::Block::Respondable::Status blockStatus()
		{
			return ARK::API::Block::Gettable::status(this->netConnector);
		};
    /*************************************************/
};
/*************************************************/

};
};


#endif
