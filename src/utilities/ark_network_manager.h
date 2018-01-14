

#ifndef ark_network_manager_h
#define ark_network_manager_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace ARK {
  namespace Utilities {
    namespace Network {

      /*
        ARK::Network mainnet = ARK::Constants::Networks::Mainnet::model;
        ARK::Utilities::Network::Manager manager(mainnet);
        const char* manager.network.nethash;
        String manager.networkPeer;
      */
      class Manager {
        public:

          ARK::Network network;
          String networkPeer;
          int networkPort;
          ARK::NetworkType netType;

          Manager() {
            network = ARK::Network();
            networkPeer = "";
            netType = ARK::NetworkType();
          };

          Manager(ARK::Network _network) {
            connect(_network);
          };

          void connect(ARK::Network _network) {
            if (_network.nethash == ARK::Constants::Networks::Devnet::nethash)
              netType = ARK::NetworkType::DEV;
            if (_network.nethash == ARK::Constants::Networks::Mainnet::nethash)
              netType = ARK::NetworkType::MAIN;
            this->network = _network;
            this->setNetworkPeer(this->randomPeer());
            this->isReachable = true;
          };

          void connectCustom(ARK::Network _network, String _peer, int _port) {
            this->netType = ARK::NetworkType::CUSTOM;
            this->network = _network;
            this->networkPeer = _peer;
            this->networkPort = _port;
            this->isReachable = true;
          };

          bool disconnect() {
            if (!this->isReachable) {
              return false;
            }
            network = ARK::Network();
            this->networkPeer = "";
            this->isReachable = false;
            return !this->isReachable;
          };


/* move client out of CB */

            // HTTPClient http2;


          String cb(String _request) {

            HTTPClient http;


            if (this->isConnected == false) {
              http.setReuse(true);
              http.setTimeout(1000);
              http.begin(this->networkPeer, this->networkPort, _request);
              this->isConnected = true;
            } else {

              http.begin(_request);

            };

              delay(500);

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
            // switch (this->isReachable) {
            //   case true:
            //     String streamStr = http.getStreamPtr()->readString();
            //    return streamStr; break;
            //   default: return "Error: Connection to Peer could not be established";
            // }
          };
          
        private:

          bool isConnected = false;

          bool isReachable = false;

          String randomPeer() {
            if (this->netType == ARK::NetworkType::DEV)
              return ARK::Constants::Networks::Devnet::randomPeer();
            if (this->netType == ARK::NetworkType::MAIN)
              return ARK::Constants::Networks::Mainnet::randomPeer();
            return "Error: Nethash does not match ARK::Constants";
          };

          void setNetworkPeer(String _peer) {
            
            Serial.println("setNetworkPeer");
            Serial.println(_peer);
            Serial.println();

            if (this->netType == ARK::NetworkType::DEV)
              this->networkPort = ARK::Constants::Networks::Devnet::port;
            if (this->netType == ARK::NetworkType::MAIN)
              this->networkPort = ARK::Constants::Networks::Mainnet::port;
            this->networkPeer = _peer;
          };

      };

    };
    

  };
};

#endif
