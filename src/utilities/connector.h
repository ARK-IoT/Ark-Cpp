

#ifndef CONNECTOR_H
#define CONNECTOR_H


namespace ARK
{
namespace Utilities
{
namespace Network
{

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable
*   Inheritable Connector object
**************************************************/
class Connectable; 
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connector
**************************************************/
class Connector
    : virtual HTTPConnectable
{
/*  ==================================  */
  public:
  
/****************************************
*  ARK::Utilities::Network::Connectable
*  virtual HTTPConnectable
*
*  ARK::Utilities::Network::HTTP http; 
*****************************************/

    const ARK::Network* network;
    ARK::NetworkType netType;

    String networkPeer;
    int networkPort;

    Connector();
    Connector(const ARK::Network& network);
    Connector(ARK::NetworkType networktype);

    void connect(const ARK::Network& network);
    void connectCustom(const ARK::Network& network, String peer, int port);

    bool disconnect();

    String cb(String request);
/*  ==================================  */


/*  ==================================  */
  private:
  
    String randomPeer();
    void setNetworkPeer(String peer);
/*  ==================================  */
/*  ==========================================================================  */

};
};
};
};





/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable
*   Inheritable Connector object
**************************************************/
class ARK::Utilities::Network::Connectable
{
public:

  ARK::Utilities::Network::Connector netConnector;
};
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connector
*   Default empty constructor
**************************************************/
ARK::Utilities::Network::Connector::Connector()
{
  this->network = nullptr;
  networkPeer = "";
  netType = ARK::NetworkType();
};

/**************************************************
* Connects this to the supplied ARK::Network
**************************************************/
ARK::Utilities::Network::Connector::Connector(const ARK::Network& network)
{
  this->connect(network);
}

/**************************************************
* Connects this to the supplied ARK::NetworkType
**************************************************/
ARK::Utilities::Network::Connector::Connector(ARK::NetworkType networkType)
{
  (networkType == DEV)
      ? (this->connect(ARK::Constants::Networks::Devnet::model))
      : (this->connect(ARK::Constants::Networks::Mainnet::model));
}

/**************************************************
* Sets networktype, network, and peer
*
**************************************************/
void ARK::Utilities::Network::Connector::connect(const ARK::Network& network)
{
  this->netType = (
      (network.nethash == ARK::Constants::Networks::Devnet::nethash)
      && (network.nethash != ARK::Constants::Networks::Mainnet::nethash))
          ? (ARK::NetworkType::DEV)
          : (ARK::NetworkType::MAIN);

  this->network = &network;
  this->setNetworkPeer(this->randomPeer());
}

/**************************************************
*
*
**************************************************/
void ARK::Utilities::Network::Connector::connectCustom(const ARK::Network& network, String peer, int port)
{
  this->netType = ARK::NetworkType::CUSTOM;
  this->network = &network;

  this->networkPeer = peer;
  this->networkPort = port;
}

/**************************************************
* Sets Random Peer based on this->NetworkType
*   returns error String if error
**************************************************/
String ARK::Utilities::Network::Connector::randomPeer()
{
  if (this->netType == ARK::NetworkType::DEV)
    return ARK::Constants::Networks::Devnet::randomPeer();

  if (this->netType == ARK::NetworkType::MAIN)
    return ARK::Constants::Networks::Mainnet::randomPeer();

  return "Error: Nethash does not match ARK::Constants";
}

/**************************************************
* Checks this->NetworkType
* Assigns ip & port to this
**************************************************/
void ARK::Utilities::Network::Connector::setNetworkPeer(String peer)
{
  if (this->netType == ARK::NetworkType::DEV)
    this->networkPort = ARK::Constants::Networks::Devnet::port;

  if (this->netType == ARK::NetworkType::MAIN)
    this->networkPort = ARK::Constants::Networks::Mainnet::port;

  this->networkPeer = peer;
}

/**************************************************
* Manages directing the callback from
*   the devices HTTPClient Library
**************************************************/
String ARK::Utilities::Network::Connector::cb(String request)
{
  String resp = this->http.get(this->networkPeer, this->networkPort, request);
  return resp;
}
/*  ==========================================================================  */


#endif
