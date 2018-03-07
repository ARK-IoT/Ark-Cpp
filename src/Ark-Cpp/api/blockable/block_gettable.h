

#ifndef BLOCK_GETTABLE_H
#define BLOCK_GETTABLE_H

#include "block_respondable.h"
#include "block.h"
#include "connector.h"
#include "fees.h"

namespace ARK
{
namespace API
{
namespace Block
{

/*  ==========================================================================  */
/*  ====================================  */
/*  PROTECTED: ARK::API::Block::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/blocks/get?id=_blockID */
    ARK::Block block(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _blockId);

    ARK::Block blockfromJSON(const char* const _jsonStr);
    ARK::Block blockfromJSON(const String& _jsonStr) {
        return blockfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks   */
  /*   blocks callback is ~63,712 bytes   */
  /*  /api/blocks  */
  // String blocks(ARK::Utilities::Network::Connector _netConnector) {
  // String blocksfromJSON(String _jsonStr) {
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getEpoch  */
    String epoch(ARK::Utilities::Network::Connector& _netConnector);
    String epochfromJSON(const char* const _jsonStr);
    String epochfromJSON(const String& _jsonStr) {
        return epochfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getHeight  */
    ARK::API::Block::Respondable::Height height(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Block::Respondable::Height heightfromJSON(const char* const _jsonStr);
    ARK::API::Block::Respondable::Height heightfromJSON(const String& _jsonStr) {
        return heightfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getNethash  */
    Hash nethash(ARK::Utilities::Network::Connector& _netConnector);
    Hash nethashfromJSON(const char* const _jsonStr);
    Hash nethashfromJSON(const String& _jsonStr) {
        return nethashfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFee  */
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);
    Balance feefromJSON(const char* const _jsonStr);
    Balance feefromJSON(const String& _jsonStr) {
        return feefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getFees  */
    ARK::Fees fees(ARK::Utilities::Network::Connector& _netConnector);
    ARK::Fees feesfromJSON(const char* const _jsonStr);
    ARK::Fees feesfromJSON(const String& _jsonStr) {
        return feesfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getMilestone  */
    String milestone(ARK::Utilities::Network::Connector& _netConnector);
    String milestonefromJSON(const char* const _jsonStr);
    String milestonefromJSON(const String& _jsonStr) {
        return milestonefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getReward  */
    Balance reward(ARK::Utilities::Network::Connector& _netConnector);
    Balance rewardfromJSON(const char* const _jsonStr);
    Balance rewardfromJSON(const String& _jsonStr) {
        return rewardfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getSupply  */
    Balance supply(ARK::Utilities::Network::Connector& _netConnector);
    Balance supplyfromJSON(const char* const _jsonStr);
    Balance supplyfromJSON(const String& _jsonStr) {
        return supplyfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/blocks/getStatus  */
    ARK::API::Block::Respondable::Status status(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Block::Respondable::Status statusfromJSON(const char* const _jsonStr);
    ARK::API::Block::Respondable::Status statusfromJSON(const String& _jsonStr) {
        return statusfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ====================================  */
/*  ==========================================================================  */
};
};
};

#endif
