

#ifndef api_h
#define api_h

#include "api_model.h"

namespace ARK {
  namespace API {

    namespace Endpoints {

      /* Accounts */
      namespace Account {
        String getBalance_s = "/api/accounts/getBalance";
        String getPublickey_s = "/api/accounts/getPublickey";
        String delegatesFee_s = "/api/accounts/delegates/fee";
        String delegates_s = "/api/accounts/delegates";
        String accounts_s = "/api/accounts";
        String top_s = "/api/accounts/top";
      };
      

      /* Blocks */  
      namespace Block {
        String get_s = "/api/blocks/get"; //using ID
        String blocks_s = "/api/blocks";
        String getEpoch_s = "/api/blocks/getEpoch";
        String getHeight_s = "/api/blocks/getHeight";
        String getNethash_s = "/api/blocks/getNethash";
        String getFee_s = "/api/blocks/getFee";
        String getFees_s = "/api/blocks/getFees";
        String getMilestone_s = "/api/blocks/getMilestone";
        String getReward_s = "/api/blocks/getReward";
        String getSupply_s = "/api/blocks/getSupply";
        String getStatus_s = "/api/blocks/getStatus";
      };


      /* Delegates */
      namespace Delegate {
        String count_s = "/api/delegates/count";
        String search_s = "/api/delegates/search";
        String voters_s = "/api/delegates/voters";
        String get_s = "/api/delegates/get";
        String delegates_s = "/api/delegates";
        String fee_s = "/api/delegates/fee";
        String getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
        String getNextForgers_s = "/api/delegates/getNextForgers";
      };


      /* Delegates */
      namespace Loader {
        String status_s = "/api/loader/status";
        String sync_s = "/api/loader/status/sync";
        String autoconfigure_s = "/api/loader/autoconfigure";
      };


      /* Peers */
      namespace Peer {
        String get_s = "/api/peers/get";
        String peers_s = "/api/peers";
        String version_s = "/api/peers/version";
      };
      

      /* Signatures */
      namespace Signatures {
        String fee_s = "/api/signatures/fee";
      };
      

      /* MultiSignatures */
      namespace MultiSignatures {
        String pending_s = "/api/multisignatures/pending";
        String accounts_s = "/api/multisignatures/accounts";
      };
      

      /* Transactions */
      namespace Transaction {
        String getSingle_s = "/api/transactions/get";
        String transactions_s = "/api/transactions";
        String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get"; //
        String unconfirmed_s = "/api/transactions/unconfirmed";
      };
      
      
      /* Transport */
      namespace Transport {
        String list_s = "/peer/list";
        String common_s = "/peer/blocks/common";
        String block_s = "/peer/block";
        String blocks_s = "/peer/blocks";
        String transactions_s = "/peer/transactions";
        String transactionsPost_s = "/peer/transactions"; // post
        String transactionsFromIds_s = "/peer/transactionsFromIds";
        String height_s = "/peer/height";
        String status_s = "/peer/status";
      };
      
    };

  };
};

#endif
