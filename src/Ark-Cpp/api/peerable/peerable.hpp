

#ifndef PEERABLE_HPP
#define PEERABLE_HPP

#include "peer_respondable.hpp"
#include "peer_gettable.hpp"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Peerable
*   	public Peer::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Peer Model
**************************************************/
class Peerable :
    public Peer::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*		/api/peers/get?ip=167.114.29.55&port=4002
		*		@return:	ARK::Peer
		*   @method:	peer(const char* const ip, int port)
    *   @parameters:	const char* const ip, int port
		*   calls:	ARK::API::Peer::Gettable::peer(this->netConnector, ip, port)
		*
		*   @brief:	Gets Ark Network Peer from a Node via API.
		**************************************************/
    ARK::Peer peer(const char* const ip, int port)
    {
      return ARK::API::Peer::Gettable::peer(this->netConnector, ip, port);
    };
    /*************************************************/

/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
  	/*    BROKEN: fix for large callbacks  */
  	/*    Peers callback is ~11,000 bytes  */
    /*  /api/peers  */
    // ARK::API::PeerGettable::PeersResponse peers()
    // { return ARK::API::PeerGettable::peers(this->netConnector); };
    /*************************************************/
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/peers/version
		*		@return:	ARK::API::Peer::Respondable::Version
		*   @method:	ppeerVersion()
		*   calls:	ARK::API::Peer::Gettable::version(this->netConnector)
		*
		*   @brief:	Gets Ark Network Peer Version from a Node via API.
		**************************************************/
    ARK::API::Peer::Respondable::Version peerVersion()
    {
      return ARK::API::Peer::Gettable::version(this->netConnector);
    };
    /*************************************************/
	};

};
};

#endif
