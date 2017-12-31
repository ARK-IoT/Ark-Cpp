

#ifndef ark_network_manager_h
#define ark_network_manager_h

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
            this->isConnected = true;
          };

          bool disconnect() {
            if (!this->isConnected) {
              return false;
            }
            network = ARK::Model::Network();
            this->networkPeer = "";
            this->isConnected = false;
            return !this->isConnected;
          };


        private:
          bool isConnected = false;

          String randomPeer() {
            if (this->netType == ARK::Model::NetworkType::DEV)
              return ARK::Constants::Networks::Devnet::randomPeer();
            if (this->netType == ARK::Model::NetworkType::MAIN)
              return ARK::Constants::Networks::Mainnet::randomPeer();
            return "Error: Nethash does not match ARK::Constants";
          };

          void setNetworkPeer(String _peer) {
            String p = ":";
            if (this->netType == ARK::Model::NetworkType::DEV)
              p.concat(ARK::Constants::Networks::Devnet::port);
            if (this->netType == ARK::Model::NetworkType::MAIN)
              p.concat(ARK::Constants::Networks::Mainnet::port);
            this->networkPeer = _peer + p;
          };

      };

    };
    

  };
};

#endif
