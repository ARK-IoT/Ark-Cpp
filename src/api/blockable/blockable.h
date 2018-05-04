

#ifndef BLOCKABLE_H
#define BLOCKABLE_H

#include "api/blockable/block_respondable.h"
#include "api/blockable/block_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Blockable
*	public Block::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Block Model
**************************************************/
class Blockable :
		public Block::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*	/api/blocks/get?id=_blockID
		*
		*	@param:	const char *const blockId
		*	@return:	ARK::Block
		*
		*	@brief:	Uses Block ID to get that Blocks information from a Node via API.
		**************************************************/
		ARK::Block block(
				const char *const blockId
		)
		{
			return ARK::API::Block::Gettable::block(this->netConnector, blockId);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************/
		/*************************************************
		*	BROKEN: fix for large callbacks
		*	blocks callback is ~63,712 bytes
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
		*	/api/blocks/getEpoch
		*
		*	@param:	char buffer[]
		*
		*	@brief:	Gets the Block Epoch from a Node via API.
		**************************************************/
		void blockEpoch(
				char buffer[]
		)
		{
			return ARK::API::Block::Gettable::epoch(this->netConnector, buffer);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getHeight
		*
		*	@return:	ARK::API::Block::Respondable::Height
		*
		*	@brief:	Gets the Block-Height from a Node via API.
		**************************************************/
		ARK::API::Block::Respondable::Height blockHeight()
		{
			return ARK::API::Block::Gettable::height(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getNethash
		*
		*	@return:	Hash
		*
		*	@brief:	Gets the Networks Hash from a Node via API.
		**************************************************/
		Hash blockNethash()
		{
			return ARK::API::Block::Gettable::nethash(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getFee
		*
		*	@return:	Balance
		*
		*	@brief:	Gets the Block-Fee from a Node via API.
		**************************************************/
		Balance blockFee()
		{
			return ARK::API::Block::Gettable::fee(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getFees
		*
		*	@return:	ARK::Fees
		*
		*	@brief:	Gets Ark Network Fees from a Node via API.
		**************************************************/
		ARK::Fees blockFees()
		{
			return ARK::API::Block::Gettable::fees(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getMilestone
		*
		*	@return:	const char*
		*
		*	@brief:	Gets the Block Milestone from a Node via API.
		**************************************************/
		const char *blockMilestone()
		{
			return ARK::API::Block::Gettable::milestone(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getReward
		*
		*	@return:	Balance
		*
		*	@brief:	Gets the Block Reward from a Node via API.
		**************************************************/
		Balance blockReward()
		{
			return ARK::API::Block::Gettable::reward(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getSupply
		*
		*	@return:	Balance
		*
		*	@brief:	Gets the current Ark Supply from a Node via API.
		**************************************************/
		Balance blockSupply()
		{
			return ARK::API::Block::Gettable::supply(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getStatus
		*
		*	@return:	ARK::API::Block::Respondable::Status
		*
		*	@brief:	Gets the Ark Networks Status from a Node via API.
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
