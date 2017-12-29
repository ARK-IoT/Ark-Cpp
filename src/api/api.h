

#ifndef api_h
#define api_h

#include "api_model.h"
#include "api_constants.h"


namespace ARK {
  namespace API {
    
    class API_Manager {

      public:

        API_Manager();

        API_Manager(ARK::Model::Network _network) {          
          this->connectNetwork(_network);
        };


        String getBalance(String _arkAddress) {
          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::getBalance_s;
          String address = "?address=" + _arkAddress;
          return basepoint + address;
        };

        String getPublickey(String _arkAddress) {

          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::getPublickey_s;
          String address = "?address=" + _arkAddress;
          return basepoint + address;
        };
        String delegatesFee(String _arkAddress) {
          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::delegatesFee_s;
          String address = "?address=" + _arkAddress;
          return basepoint + address;
        };

        String delegates(String _arkAddress) {
          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::delegates_s;
          String address = "?address=" + _arkAddress;
          return basepoint + address;
        };

        String accounts(String _arkAddress) {
          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::accounts_s;
          String address = "?address=" + _arkAddress;
          return basepoint + address;
        };

        String top(int _limit = 0, int _offset = 0) {
          if (this->netManager.network.nethash != ARK::Constants::Networks::Mainnet::nethash)
            return "Only available on Mainnet";
          String basepoint = netManager.networkPeer + ARK::API::Endpoints::Account::top_s;
          if (_limit + _offset == 0)
            return basepoint;
          String limit = String("?") + "limit=" + String(_limit);
          String offset = String("&") + "offset=" + String(_offset);
          return basepoint + limit + offset;
        };


      private:

        ARK::Utilities::Network::Manager netManager;

        void connectNetwork(ARK::Model::Network _network) {
          this->netManager = ARK::Utilities::Network::Manager(_network);
        };

    };





  };
};

#endif
