

#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

namespace ARK
{
namespace Utilities
{
namespace Network
{
/*************************************************
* ARK::Utilities::Network::Connectable
*   Forward Declaration. for inheritance
**************************************************/
class Connectable;
/*************************************************/

/*************************************************
* ARK::Utilities::Network::Connector
**************************************************/
class Connector
    : public HTTPConnectable
{
public:
  /****************************************
*  ARK::Utilities::Network::Connectable
*  virtual HTTPConnectable
*
*  ARK::Utilities::Network::HTTP http; 
*****************************************/

  const ARK::Network *network;
  ARK::NetworkType netType;

  char networkPeer[16];
  int networkPort;

  Connector();
  Connector(const ARK::Network &network);
  Connector(ARK::NetworkType networktype);

  Connector(const Connector &) = delete;
  Connector &operator=(const Connector &) = delete;
  Connector(Connector &&) = default;
  Connector &operator=(Connector &&) = default;

  void connect(const ARK::Network &network);
  void connectCustom(const ARK::Network &network, const char *peer, int port);

  bool disconnect();

  const char *cb(const char *const request);

private:
  const char *randomPeer();
  void setNetworkPeer(const char *peer);
  /*************************************************/

};



};
};
};

/*************************************************
* ARK::Utilities::Network::Connectable
*   Inheritable Connector object
**************************************************/
class ARK::Utilities::Network::Connectable
{
  public:
    ARK::Utilities::Network::Connector netConnector;
};
/*************************************************/


/*************************************************
* Default constructor
*
**************************************************/
ARK::Utilities::Network::Connector::Connector()
{}
/*************************************************/

/*************************************************
* Connects this to the supplied ARK::Network
*
**************************************************/
ARK::Utilities::Network::Connector::Connector(const ARK::Network &network)
{
  this->connect(network);
}
/*************************************************/

/*************************************************
* Connects this to the supplied ARK::NetworkType
*
*
**************************************************/
ARK::Utilities::Network::Connector::Connector(ARK::NetworkType networkType)
{
  (networkType == DEV)
      ? (this->connect(ARK::Constants::Networks::Model::Devnet))
      : (this->connect(ARK::Constants::Networks::Model::Mainnet));
}
/*************************************************/

/*************************************************
* Sets networktype, network, and peer
*
*
**************************************************/
void ARK::Utilities::Network::Connector::connect(const ARK::Network &network)
{
  if (strcmp(network.nethash.getValue(), ARK::Constants::Networks::Devnet::nethash) == 0)
  {
    this->netType = ARK::NetworkType::DEV;
  }
  else if (strcmp(network.nethash.getValue(), ARK::Constants::Networks::Mainnet::nethash) == 0)
  {
    this->netType = ARK::NetworkType::MAIN;
  }
  else if (strcmp(network.nethash.getValue(), "") != 0)
  {
    this->netType = ARK::NetworkType::CUSTOM;
  }
  else
  {
    this->netType = ARK::NetworkType::INVALID;
  };

  this->network = &network;
  this->setNetworkPeer(this->randomPeer());
}
/*************************************************/

/*************************************************
*
*
**************************************************/
void ARK::Utilities::Network::Connector::connectCustom(const ARK::Network &network, const char *peer, int port)
{
  this->netType = ARK::NetworkType::CUSTOM;
  this->network = &network;
  strncpy(this->networkPeer, peer, sizeof(this->networkPeer) / sizeof(this->networkPeer[0]));
  this->networkPort = port;
}
/*************************************************/

/*************************************************
* Sets Random Peer based on this->NetworkType
*   returns error c_string if error
*
*
**************************************************/
const char *ARK::Utilities::Network::Connector::randomPeer()
{
  return ARK::Constants::Networks::randomPeer(this->netType);
}
/*************************************************/

/*************************************************
* Checks this->NetworkType
*   @brief: Assigns ip & port to this
**************************************************/
void ARK::Utilities::Network::Connector::setNetworkPeer(const char *peer)
{
  this->networkPort = ARK::Constants::Networks::getPort(this->netType);
  strncpy(networkPeer, peer, sizeof(networkPeer) / sizeof(networkPeer[0]));
}
/*************************************************/

/*************************************************
* Manages directing the callback from
*   the devices HTTPClient Library
*
*
**************************************************/
const char *ARK::Utilities::Network::Connector::cb(const char *const request)
{
  return this->http.get(this->networkPeer, this->networkPort, request);
}
/*************************************************/

#endif
