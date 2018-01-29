

#ifndef CONNECTOR_H
#define CONNECTOR_H


namespace ARK
{
namespace Utilities
{
namespace Network
{

class Connectable; /* Inheritable Connector object  */

/*  ==================================  */
/*  ARK::Utilities::Network::Connector  */
class Connector : virtual HTTPConnectable
{

public:

/****************************************
*  ARK::Utilities::Network::Connectable
*  virtual HTTPConnectable
*
*  ARK::Utilities::Network::HTTP http; 
*****************************************/

  ARK::Network network;
  ARK::NetworkType netType;

  String networkPeer;
  int networkPort;

  Connector();
  Connector(ARK::Network network);
  Connector(ARK::NetworkType networktype);

  void connect(ARK::Network network);
  void connectCustom(ARK::Network network, String peer, int port);

  bool disconnect();

  String cb(String request);

private:

  bool isConnected = false;

  String randomPeer();
  void setNetworkPeer(String peer);



  
};
};
};
};

/*  ====================================  */
/*  ARK::Utilities::Network::Connectable  */
/*      Inheritable Connector object      */
class ARK::Utilities::Network::Connectable
{
public:

  ARK::Utilities::Network::Connector netConnector;
};
/*  =====================================  */

/*  ================================  */
/*  ARK::Utilities::Network::Connector  */

ARK::Utilities::Network::Connector::Connector()
{
  this->network = ARK::Network();

  networkPeer = "";

  netType = ARK::NetworkType();
};

ARK::Utilities::Network::Connector::Connector(ARK::Network network)
{
  this->connect(network);
}

ARK::Utilities::Network::Connector::Connector(ARK::NetworkType networktype)
{
  ARK::Network network;

  switch (networktype)
  {
  case DEV:
    network = ARK::Constants::Networks::Devnet::model;
    break;
  case MAIN:
    network = ARK::Constants::Networks::Mainnet::model;
    break;
  default:
    break;
  };
  this->connect(network);
}

void ARK::Utilities::Network::Connector::connect(ARK::Network network)
{
  if (network.nethash == ARK::Constants::Networks::Devnet::nethash)
    netType = ARK::NetworkType::DEV;

  if (network.nethash == ARK::Constants::Networks::Mainnet::nethash)
    netType = ARK::NetworkType::MAIN;

  this->network = network;
  this->setNetworkPeer(this->randomPeer());

  this->isConnected = true;
}

void ARK::Utilities::Network::Connector::connectCustom(ARK::Network network, String peer, int port)
{
  this->netType = ARK::NetworkType::CUSTOM;
  this->network = network;

  this->networkPeer = peer;
  this->networkPort = port;

  this->isConnected = true;
}

bool ARK::Utilities::Network::Connector::disconnect()
{
  if (!this->isConnected)
  {
    return false;
  }
  network = ARK::Network();

  this->networkPeer = "";

  this->isConnected = false;

  return !this->isConnected;
}

String ARK::Utilities::Network::Connector::randomPeer()
{
  if (this->netType == ARK::NetworkType::DEV)
    return ARK::Constants::Networks::Devnet::randomPeer();

  if (this->netType == ARK::NetworkType::MAIN)
    return ARK::Constants::Networks::Mainnet::randomPeer();

  return "Error: Nethash does not match ARK::Constants";
}

void ARK::Utilities::Network::Connector::setNetworkPeer(String peer)
{
  if (this->netType == ARK::NetworkType::DEV)
    this->networkPort = ARK::Constants::Networks::Devnet::port;

  if (this->netType == ARK::NetworkType::MAIN)
    this->networkPort = ARK::Constants::Networks::Mainnet::port;

  this->networkPeer = peer;
}

String ARK::Utilities::Network::Connector::cb(String request)
{
  String resp = this->http.get(this->networkPeer, this->networkPort, request);
  return resp;

  // HTTPClient http;
  // if (this->isConnected == false)
  // {
  //   http.setReuse(true);
  //   http.setTimeout(1000);
  //   http.begin(this->networkPeer, this->networkPort, request);

  //   this->isConnected = true;
  // }
  // else
  // {
  //   http.begin(request);
  // };

  // int httpCode = http.GET();

  // while (!http.connected())
  // {
  //   delay(1000);
  //   Serial.println("waiting for HTTP connection");
  // };

  // this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());

  // if (this->isReachable)
  // {
  //   String streamStr = String(http.getStreamPtr()->readString());

  //   http.end();

  //   return streamStr;
  // }
  // else
  // {
  //   http.end();

  //   this->isConnected = false;

  //   return "Error: Connection to Peer could not be established";
  // };
}

  /*  ================================  */

#endif
