

#ifndef PEER_GETTABLE_H
#define PEER_GETTABLE_H

#include "peer.h"
#include "connector.h"
#include "peer_respondable.h"

namespace ARK
{
namespace API
{
namespace Peer
{

/*  ==========================================================================  */
/*  ===================================  */
/*  PROTECTED: ARK::API::Peer::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/delegates/fee  */
    ARK::Peer peer(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _ip,
        int _port);

    ARK::Peer peerfromJSON(const char* const _jsonStr);
    ARK::Peer peerfromJSON(const String& _jsonStr) {
        return peerfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks  */
  /*    Peers callback is ~11,000 bytes  */
    // ARK::API::PeerGettablePeersResponse peersfromJSON(String _jsonStr);
    // ARK::API::PeerGettablePeersResponse peers(ARK::Utilities::Network::Connector _netConnector);
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/peers/version  */
    ARK::API::Peer::Respondable::Version version(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Peer::Respondable::Version versionfromJSON(const char* const _jsonStr);
    ARK::API::Peer::Respondable::Version versionfromJSON(const String& _jsonStr) {
        return versionfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ===================================  */
/*  ==========================================================================  */
};
};
};


#endif