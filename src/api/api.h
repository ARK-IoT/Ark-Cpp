

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
          String getBalance(String _arkAddress)
          { return ARK::API::Account::getBalance(this->netManager, _arkAddress); };

          /*  /api/accounts/getPublickey?address=arkAddress */
          String getPublickey(String _arkAddress)
          { return ARK::API::Account::getPublickey(this->netManager, _arkAddress); };

          /*  /api/accounts/delegates/fee?address=arkAddress  */
          String delegatesFee(String _arkAddress)
          { return ARK::API::Account::delegatesFee(this->netManager, _arkAddress); };

          /*  /api/accounts/delegates?address=arkAddress  */
          String delegates(String _arkAddress)
          { return ARK::API::Account::delegates(this->netManager, _arkAddress); };

          /*  /api/accounts?address=arkAddress  */
          String accounts(String _arkAddress)
          { return ARK::API::Account::accounts(this->netManager, _arkAddress); };



      // Delegate:
      //   const String count_s = "/api/delegates/count";
      //   const String search_s = "/api/delegates/search";
      //   const String voters_s = "/api/delegates/voters";
      //   const String get_s = "/api/delegates/get";
      //   const String delegates_s = "/api/delegates";
      //   const String fee_s = "/api/delegates/fee";
      //   const String getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
      //   const String getNextForgers_s = "/api/delegates/getNextForgers";

      // Loader:
      //   const String status_s = "/api/loader/status";
      //   const String sync_s = "/api/loader/status/sync";
      //   const String autoconfigure_s = "/api/loader/autoconfigure";

      // Peer:
      //   const String get_s = "/api/peers/get";
      //   const String peers_s = "/api/peers";
      //   const String version_s = "/api/peers/version";

      // Signatures:
      //   const String fee_s = "/api/signatures/fee";

      // MultiSignatures:
      //   const String pending_s = "/api/multisignatures/pending";
      //   const String accounts_s = "/api/multisignatures/accounts";

      // Transaction:
      //   const String getSingle_s = "/api/transactions/get";
      //   const String transactions_s = "/api/transactions";
      //   const String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get"; //
      //   const String unconfirmed_s = "/api/transactions/unconfirmed";

      // Transport:
      //   const String list_s = "/peer/list";
      //   const String common_s = "/peer/blocks/common";
      //   const String block_s = "/peer/block";
      //   const String blocks_s = "/peer/blocks";
      //   const String transactions_s = "/peer/transactions";
      //   const String transactionsPost_s = "/peer/transactions"; // post
      //   const String transactionsFromIds_s = "/peer/transactionsFromIds";
      //   const String height_s = "/peer/height";
      //   const String status_s = "/peer/status";


      private:

        ARK::Utilities::Network::Manager netManager;

    };

  };
};

#endif
