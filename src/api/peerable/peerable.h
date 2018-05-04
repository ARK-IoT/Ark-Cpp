

#ifndef PEERABLE_H
#define PEERABLE_H

#include "api/peerable/peer_respondable.h"
#include "api/peerable/peer_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Peerable
*	public Peer::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Peer Model
**************************************************/
class Peerable :
    public Peer::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*	/api/peers/get?ip=167.114.29.55&port=4002
		*
		*	@method:	peer(const char* const ip, int port)
    *	@param:	const char* const ip
		*	@param:	int port
		*	@return:	ARK::Peer
		*
		*	@brief:	Gets Ark Network Peer from a Node via API.
		**************************************************/
    ARK::Peer peer(
				const char* const ip,
				int port
		)
    {
      return ARK::API::Peer::Gettable::peer(this->netConnector, ip, port);
    };
    /*************************************************/

		/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
  	/*	BROKEN: fix for large callbacks  */
  	/*	Peers callback is ~11,000 bytes  */
    /*  /api/peers  */
    // ARK::API::PeerGettable::PeersResponse peers()
    // { return ARK::API::PeerGettable::peers(this->netConnector); };
    /*************************************************/
    /*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/peers/version
		*
		*	@method:	peerVersion()
		*	@return:	ARK::API::Peer::Respondable::Version
		*
		*	@brief:	Gets Ark Network Peer Version from a Node via API.
		**************************************************/
    ARK::API::Peer::Respondable::Version peerVersion()
    {
      return ARK::API::Peer::Gettable::version(this->netConnector);
    };
    /*************************************************/

};
/*************************************************/

};
};

#endif
