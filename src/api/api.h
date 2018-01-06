

#ifndef api_h
#define api_h

#include "api_model.h"
#include "api_constants.h"

namespace ARK {
  namespace API {
    
    class API_Manager {

      public:

        API_Manager() {
          ARK::Model::Network _network;
          this->connect(_network);
        };

        API_Manager(ARK::Model::Network _network) {          
          this->connect(_network);
        };

        void connect(ARK::Model::Network _network) {
          this->netManager = ARK::Utilities::Network::Manager(_network);
        };




        /*  /api/accounts/getBalance?address=arkAddress */
        String getBalance(String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::getBalance_s;
            uri += "?address=" + _arkAddress;
          String callback = this->netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::getBalancefromJSON(callback);
        };


        /*  /api/accounts/getPublickey?address=arkAddress */
        String getPublickey(String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::getPublickey_s;
            uri += "?address=" + _arkAddress;
          String callback = this->netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::getPublickeyfromJSON(callback);
        };


        /*  /api/accounts/delegates/fee?address=arkAddress  */
        String delegatesFee(String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::delegatesFee_s;
            uri += "?address=" + _arkAddress;
          String callback = this->netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::getDelegatesFeefromJSON(callback);
        };


        /*  /api/accounts/delegates?address=arkAddress  */
        String delegates(String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::delegates_s;
            uri += "?address=" + _arkAddress;
          String callback = this->netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::getDelegatesfromJSON(callback);
        };


        /*  /api/accounts?address=arkAddress  */
        String accounts(String _arkAddress) {
          String uri = ARK::API::Endpoints::Account::accounts_s;
            uri += "?address=" + _arkAddress;
          String callback = this->netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Account::getAccountfromJSON(callback);
        };


        /**/
        String top(int _limit = 0, int _offset = 0) {
          if (this->netManager.network.nethash != ARK::Constants::Networks::Mainnet::nethash)
            return "Only available on Mainnet";
          String basepoint = this->netManager.networkPeer + ARK::API::Endpoints::Account::top_s;
          if (_limit + _offset == 0)
            return basepoint;
          String limit = String("?") + "limit=" + String(_limit);
          String offset = String("&") + "offset=" + String(_offset);
          return basepoint + limit + offset;
        };

      private:

        ARK::Utilities::Network::Manager netManager;

    };

  };
};

#endif
