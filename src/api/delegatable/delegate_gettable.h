

#ifndef DELEGATE_GETTABLE_H
#define DELEGATE_GETTABLE_H

#include "connector.h"
#include "delegate.h"
#include "delegate_respondable.h"

namespace ARK
{
namespace API
{
namespace Delegate
{

/*  ==========================================================================  */
/*  =====================================  */
/*  PROTECTED: ARK::API::Delegate::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/delegates/count  */
    int count(ARK::Utilities::Network::Connector& _netConnector);
    int countfromJSON(const char* const _jsonStr);
    int countfromJSON(const String& _jsonStr) {
        return countfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/delegates/search?q=sleepdeficit  */
    ARK::API::Delegate::Respondable::Search search(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _username);

    ARK::API::Delegate::Respondable::Search searchfromJSON(const char* const _jsonStr);
    ARK::API::Delegate::Respondable::Search searchfromJSON(const String& _jsonStr) {
        return searchfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/delegates/voters?publicKey=_pubKey  */
    ARK::API::Delegate::Respondable::Voters voters(
        ARK::Utilities::Network::Connector& _netConnector,
        const Publickey& _publicKey);

    ARK::API::Delegate::Respondable::Voters votersfromJSON(const char* const _jsonStr);
    ARK::API::Delegate::Respondable::Voters votersfromJSON(const String& _jsonStr) {
        return votersfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /* 
            /api/delegates/get?username=sleepdeficit
            /api/delegates/get?publicKey=_pubKey
        */
    ARK::Delegate delegate(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _parameter);

    ARK::Delegate delegatefromJSON(const char* const _jsonStr);
    ARK::Delegate delegatefromJSON(const String& _jsonStr) {
        return delegatefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks    */
    /*  Delegates callback is ~13,564 bytes  */
    // String delegates(ARK::Utilities::Network::Connector _netConnector);
    // String delegatesfromJSON(String _jsonStr);
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/delegates/fee  */
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);
    Balance feefromJSON(const char* const _jsonStr);
    Balance feefromJSON(const String& _jsonStr) {
        return feefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
    ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccount(
        ARK::Utilities::Network::Connector& _netConnector,
        const Publickey& _generatorPublicKey);

    ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccountfromJSON(const char* const _jsonStr);
    ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccountfromJSON(const String& _jsonStr) {
        return forgedByAccountfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/delegates/forging/getNextForgers  */
    ARK::API::Delegate::Respondable::NextForgers nextForgers(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Delegate::Respondable::NextForgers nextForgersfromJSON(const char* const _jsonStr);
    ARK::API::Delegate::Respondable::NextForgers nextForgersfromJSON(const String& _jsonStr) {
        return nextForgersfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
  };
/*  =====================================  */
/*  ==========================================================================  */

};
};
};


#endif
