

#ifndef BLOCKABLE_H
#define BLOCKABLE_H

#include "block_respondable.h"
#include "block_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  ===========================  */
/*  PUBLIC: ARK::API::Blockable  */
class Blockable :
		public Block::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
/*  ==========================================================================  */
		/*  /api/blocks/get?id=_blockID */
		ARK::Block block(const char* const _blockId)
		{
			return ARK::API::Block::Gettable::block(this->netConnector, _blockId);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*    BROKEN: fix for large callbacks   */
		/*   blocks callback is ~63,712 bytes   */
		/*  /api/blocks */
		// String blocks()
		// { return ARK::API::Block::Gettable::blocks(this->netConnector); };
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getEpoch  */
		String blockEpoch()
		{
			return ARK::API::Block::Gettable::epoch(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getHeight  */
		ARK::API::Block::Respondable::Height blockHeight()
		{
			return ARK::API::Block::Gettable::height(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getNethash  */
		Hash blockNethash()
		{
			return ARK::API::Block::Gettable::nethash(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getFee  */
		Balance blockFee()
		{
			return ARK::API::Block::Gettable::fee(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getFees  */
		ARK::Fees blockFees()
		{
			return ARK::API::Block::Gettable::fees(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getMilestone  */
		String blockMilestone()
		{
			return ARK::API::Block::Gettable::milestone(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getReward  */
		Balance blockReward()
		{
			return ARK::API::Block::Gettable::reward(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getSupply  */
		Balance blockSupply()
		{
			return ARK::API::Block::Gettable::supply(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/blocks/getStatus  */
		ARK::API::Block::Respondable::Status blockStatus()
		{
			return ARK::API::Block::Gettable::status(this->netConnector);
		};
/*  ==========================================================================  */
};
/*  ===========================  */
/*  ==========================================================================  */

};
};

#endif
