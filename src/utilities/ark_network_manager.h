

#ifndef ark_network_manager_h
#define ark_network_manager_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace ARK {
  namespace Utilities {
    namespace Network {

      /*
        ARK::Model::Network mainnet = ARK::Constants::Networks::Mainnet::model;
        ARK::Utilities::Network::Manager manager(mainnet);
        const char* manager.network.nethash;
        String manager.networkPeer;
      */
      class Manager {
        public:

          ARK::Model::Network network;
          String networkPeer;
          int networkPort;
          ARK::Model::NetworkType netType;

          Manager() {
            network = ARK::Model::Network();
            networkPeer = "";
            netType = ARK::Model::NetworkType();
          };

          Manager(ARK::Model::Network _network) {
            connect(_network);
          };

          void connect(ARK::Model::Network _network) {
            if (_network.nethash == ARK::Constants::Networks::Devnet::nethash)
              netType = ARK::Model::NetworkType::DEV;
            if (_network.nethash == ARK::Constants::Networks::Mainnet::nethash)
              netType = ARK::Model::NetworkType::MAIN;
            this->network = _network;
            this->setNetworkPeer(this->randomPeer());
            this->isReachable = true;
          };

          void connectCustom(ARK::Model::Network _network, String _peer, int _port) {
            this->netType = ARK::Model::NetworkType::CUSTOM;
            this->network = _network;
            this->networkPeer = _peer;
            this->networkPort = _port;
            this->isReachable = true;
          };

          bool disconnect() {
            if (!this->isReachable) {
              return false;
            }
            network = ARK::Model::Network();
            this->networkPeer = "";
            this->isReachable = false;
            return !this->isReachable;
          };

          String cb(String _request) {
            HTTPClient http;
            http.setReuse(true);
            http.begin(this->networkPeer, this->networkPort, _request);
              delay(500);
            int httpCode = http.GET();
              delay(500);
            this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());
            switch (this->isReachable) {
              case true: return http.getString(); break;
              default: return "Error: Connection to Peer could not be established";
            };
          };
          
        private:

          bool isReachable = false;

          String randomPeer() {
            if (this->netType == ARK::Model::NetworkType::DEV)
              return ARK::Constants::Networks::Devnet::randomPeer();
            if (this->netType == ARK::Model::NetworkType::MAIN)
              return ARK::Constants::Networks::Mainnet::randomPeer();
            return "Error: Nethash does not match ARK::Constants";
          };

          void setNetworkPeer(String _peer) {
            if (this->netType == ARK::Model::NetworkType::DEV)
              this->networkPort = ARK::Constants::Networks::Devnet::port;
            if (this->netType == ARK::Model::NetworkType::MAIN)
              this->networkPort = ARK::Constants::Networks::Mainnet::port;
            this->networkPeer = _peer;
          };

      };

    };
    

  };
};

#endif
