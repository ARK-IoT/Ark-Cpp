

#ifndef peerable_h
#define peerable_h

#include "peer_gettable.h"
    
namespace ARK {
  namespace API {

    /*  ==========================  */
    /*  PUBLIC: ARK::API::Peerable  */

    class Peerable : public PeerGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/peers/get?ip=167.114.29.55&port=4002  */
        ARK::Peer peer(String _ip, int _port)
        { return ARK::API::PeerGettable::peer(this->netManager, _ip, _port); };

/*  ==========================================================================  */

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks  */
    /*    Peers callback is ~11,000 bytes  */
        /*  /api/peers  */
        // ARK::Peer::PeersResponse peers()
        // { return ARK::API::PeerGettable::peers(this->netManager); };
/*  ==========================================================================  */

        /*  /api/peers/version  */
        ARK::Peer::Version peerVersion()
        { return ARK::API::PeerGettable::version(this->netManager); };

/*  ==========================================================================  */

    };
    /*  ==========================  */

  };
};


#endif
