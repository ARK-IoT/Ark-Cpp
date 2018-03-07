

#ifndef PEERABLE_H
#define PEERABLE_H

#include "peer_respondable.h"
#include "peer_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  ==========================  */
/*  PUBLIC: ARK::API::Peerable  */
class Peerable :
    public Peer::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
/*  ==========================================================================  */
    /*  /api/peers/get?ip=167.114.29.55&port=4002  */
    ARK::Peer peer(const char* const _ip, int _port)
    {
      return ARK::API::Peer::Gettable::peer(this->netConnector, _ip, _port);
    };
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks  */
  /*    Peers callback is ~11,000 bytes  */
    /*  /api/peers  */
    // ARK::API::PeerGettable::PeersResponse peers()
    // { return ARK::API::PeerGettable::peers(this->netConnector); };
/*  ==========================================================================  */
/*  ==========================================================================  */

 /*  ==========================================================================  */
    /*  /api/peers/version  */
    ARK::API::Peer::Respondable::Version peerVersion()
    {
      return ARK::API::Peer::Gettable::version(this->netConnector);
    };
/*  ==========================================================================  */
};
/*  ==========================  */
/*  ==========================================================================  */
};
};

#endif
