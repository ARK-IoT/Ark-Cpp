

#ifndef ark_network_manager_h
#define ark_network_manager_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace ARK {
  namespace Utilities {
    namespace Network {


      class Managable; /* Inheritable public var instance  */


/*  ==================================  */
/*  ARK::Utilities::Network::Manager  */
      class Manager {

        public:

          ARK::Network network;
          ARK::NetworkType netType;
          String networkPeer;
          int networkPort;

          Manager();
          Manager(ARK::Network _network);
          Manager(ARK::NetworkType _networktype);

          void connect(ARK::Network _network);
          void connectCustom(ARK::Network _network, String _peer, int _port);

          bool disconnect();

          String cb(String _request);

        private:

          bool isConnected = false;
          bool isReachable = false;
          String randomPeer();
          void setNetworkPeer(String _peer);
      };


    };
  };
};



/*  ==================================  */
/*  ARK::Utilities::Network::Managable  */

class ARK::Utilities::Network::Managable {
  public:
    ARK::Utilities::Network::Manager netManager;
};
/*  ==================================  */




/*  ================================  */
/*  ARK::Utilities::Network::Manager  */

ARK::Utilities::Network::Manager::Manager() {
  this->network = ARK::Network();
  networkPeer = "";
  netType = ARK::NetworkType();
};

ARK::Utilities::Network::Manager::Manager(ARK::Network _network) {
  this->connect(_network);
}


ARK::Utilities::Network::Manager::Manager(ARK::NetworkType _networktype) {
  ARK::Network network;
  switch (_networktype) {
    case DEV: network = ARK::Constants::Networks::Devnet::model; break;
    case MAIN: network = ARK::Constants::Networks::Mainnet::model; break;
    default: break;
  };
  this->connect(network);
}


void ARK::Utilities::Network::Manager::connect(ARK::Network _network) {
  if (_network.nethash == ARK::Constants::Networks::Devnet::nethash)
    netType = ARK::NetworkType::DEV;
  if (_network.nethash == ARK::Constants::Networks::Mainnet::nethash)
    netType = ARK::NetworkType::MAIN;
  this->network = _network;
  this->setNetworkPeer(this->randomPeer());
  this->isReachable = true;
}

void ARK::Utilities::Network::Manager::connectCustom(ARK::Network _network, String _peer, int _port) {
  this->netType = ARK::NetworkType::CUSTOM;
  this->network = _network;
  this->networkPeer = _peer;
  this->networkPort = _port;
  this->isReachable = true;
}

bool ARK::Utilities::Network::Manager::disconnect() {
  if (!this->isReachable) {
    return false;
  }
  network = ARK::Network();
  this->networkPeer = "";
  this->isReachable = false;
  return !this->isReachable;
}

String ARK::Utilities::Network::Manager::randomPeer() {
  if (this->netType == ARK::NetworkType::DEV)
    return ARK::Constants::Networks::Devnet::randomPeer();
  if (this->netType == ARK::NetworkType::MAIN)
    return ARK::Constants::Networks::Mainnet::randomPeer();
  return "Error: Nethash does not match ARK::Constants";
}

void ARK::Utilities::Network::Manager::setNetworkPeer(String _peer) {
  if (this->netType == ARK::NetworkType::DEV)
    this->networkPort = ARK::Constants::Networks::Devnet::port;
  if (this->netType == ARK::NetworkType::MAIN)
    this->networkPort = ARK::Constants::Networks::Mainnet::port;
  this->networkPeer = _peer;
}

String ARK::Utilities::Network::Manager::cb(String _request) {
  HTTPClient http;
  if (this->isConnected == false) {
    http.setReuse(true);
    http.setTimeout(1000);
    http.begin(this->networkPeer, this->networkPort, _request);
    this->isConnected = true;
  } else {
    http.begin(_request);
  };
  int httpCode = http.GET();
  while (!http.connected()) { delay(1000); Serial.println("waiting for HTTP connection"); };
  this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());
  if (this->isReachable) {
    String streamStr = String(http.getStreamPtr()->readString());
    http.end();
    return streamStr; 
  } else {
    http.end();
    this->isConnected = false;
    return "Error: Connection to Peer could not be established";
  };
}

/*  ================================  */


#endif
