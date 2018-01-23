

#ifndef blockable_h
#define blockable_h

#include "block_gettable.h"

namespace ARK {
  namespace API { 

    /*  ===========================  */
    /*  PUBLIC: ARK::API::Blockable  */

    class Blockable : public BlockGettable, virtual ARK::Utilities::Network::Managable {

      public: 

/*  ==========================================================================  */

        /*  /api/blocks/get?id=_blockID */
        ARK::Block block(String _blockId)
        { return ARK::API::BlockGettable::block(this->netManager, _blockId); };

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks   */
    /*   blocks callback is ~63,712 bytes   */
        /*  /api/blocks */
        // String blocks()
        // { return ARK::API::BlockGettable::blocks(this->netManager); };
/*  ==========================================================================  */

        /*  /api/blocks/getEpoch  */
        String blockEpoch()
        { return ARK::API::BlockGettable::epoch(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getHeight  */
        ARK::Block::BlockHeightResponse blockHeight()
        { return ARK::API::BlockGettable::height(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getNethash  */
        Hash blockNethash()
        { return ARK::API::BlockGettable::nethash(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getFee  */
        Balance blockFee()
        { return ARK::API::BlockGettable::fee(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getFees  */
        ARK::Fees blockFees()
        { return ARK::API::BlockGettable::fees(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getMilestone  */
        String blockMilestone()
        { return ARK::API::BlockGettable::milestone(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getReward  */
        Balance blockReward()
        { return ARK::API::BlockGettable::reward(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getSupply  */
        Balance blockSupply()
        { return ARK::API::BlockGettable::supply(this->netManager); };

/*  ==========================================================================  */

        /*  /api/blocks/getStatus  */
        ARK::Block::Block::BlockStatusResponse blockStatus()
        { return ARK::API::BlockGettable::status(this->netManager); };

/*  ==========================================================================  */

    };
    /*  ===========================  */


  };
};

#endif
