

#ifndef PEERABLE_H
#define PEERABLE_H

#include "api/peerable/peer_respondable.h"
#include "api/peerable/peer_gettable.h"
#include "models/transaction.h"

namespace ARK {
namespace API {

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
    }

	bool postTransaction(const ARK::Transaction& transaction) {
		auto callback = netConnector.post(ARK::API::Paths::Peer::transactions_s, transaction.json().c_str());
		/* 
		{
		  type: 0, // Transaction type. 0 = Normal transaction.
		  amount: 100000000000, // The amount to send expressed as an integer value.
		  asset: {}, // Transaction asset, dependent on tx type.
		  fee: 100000000, // 0.1 ARK expressed as an integer value.
		  id: "500224999259823996", // Transaction ID.
		  recipientId: "AGihocTkwDygiFvmg6aG8jThYTic47GzU9", // Recipient ID.
		  senderPublicKey: "56e106a1d4a53dbe22cac52fefd8fc4123cfb4ee482f8f25a4fc72eb459b38a5", // Sender's public key.
		  signSignature: "03fdd33bed30270b97e77ada44764cc8628f6ad3bbd84718571695262a5a18baa37bd76a62dd25bc21beacd61eaf2c63af0cf34edb0d191d225f4974cd3aa509", // Sender's second passphrase signature.
		  signature: "9419ca3cf11ed2e3fa4c63bc9a4dc18b5001648e74522bc0f22bda46a188e462da4785e5c71a43cfc0486af08d447b9340ba8b93258c4c7f50798060fff2d709", // Transaction signature.
		  timestamp: 27953413 // Based on UTC time of genesis since epoch.
		}
		*/
	}
    /*************************************************/

};
/*************************************************/

};
};

#endif
