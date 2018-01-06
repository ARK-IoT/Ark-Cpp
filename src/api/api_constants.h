

#ifndef api_constants_h
#define api_constants_h

namespace ARK {
  namespace API {


    namespace Endpoints {
      /* Accounts */
      namespace Account {
        const String getBalance_s = "/api/accounts/getBalance";
        const String getPublickey_s = "/api/accounts/getPublickey";
        const String delegatesFee_s = "/api/accounts/delegates/fee";
        const String delegates_s = "/api/accounts/delegates";
        const String accounts_s = "/api/accounts";
      };
      
      /* Blocks */  
      namespace Block {
        const String get_s = "/api/blocks/get"; //using ID
        const String blocks_s = "/api/blocks";
        const String getEpoch_s = "/api/blocks/getEpoch";
        const String getHeight_s = "/api/blocks/getHeight";
        const String getNethash_s = "/api/blocks/getNethash";
        const String getFee_s = "/api/blocks/getFee";
        const String getFees_s = "/api/blocks/getFees";
        const String getMilestone_s = "/api/blocks/getMilestone";
        const String getReward_s = "/api/blocks/getReward";
        const String getSupply_s = "/api/blocks/getSupply";
        const String getStatus_s = "/api/blocks/getStatus";
      };
      /* Delegates */
      namespace Delegate {
        const String count_s = "/api/delegates/count";
        const String search_s = "/api/delegates/search";
        const String voters_s = "/api/delegates/voters";
        const String get_s = "/api/delegates/get";
        const String delegates_s = "/api/delegates";
        const String fee_s = "/api/delegates/fee";
        const String getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
        const String getNextForgers_s = "/api/delegates/getNextForgers";
      };
      /* Delegates */
      namespace Loader {
        const String status_s = "/api/loader/status";
        const String sync_s = "/api/loader/status/sync";
        const String autoconfigure_s = "/api/loader/autoconfigure";
      };
      /* Peers */
      namespace Peer {
        const String get_s = "/api/peers/get";
        const String peers_s = "/api/peers";
        const String version_s = "/api/peers/version";
      };
      /* Signatures */
      namespace Signatures {
        const String fee_s = "/api/signatures/fee";
      };
      /* MultiSignatures */
      namespace MultiSignatures {
        const String pending_s = "/api/multisignatures/pending";
        const String accounts_s = "/api/multisignatures/accounts";
      };
      /* Transactions */
      namespace Transaction {
        const String getSingle_s = "/api/transactions/get";
        const String transactions_s = "/api/transactions";
        const String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get"; //
        const String unconfirmed_s = "/api/transactions/unconfirmed";
      };
      /* Transport */
      namespace Transport {
        const String list_s = "/peer/list";
        const String common_s = "/peer/blocks/common";
        const String block_s = "/peer/block";
        const String blocks_s = "/peer/blocks";
        const String transactions_s = "/peer/transactions";
        const String transactionsPost_s = "/peer/transactions"; // post
        const String transactionsFromIds_s = "/peer/transactionsFromIds";
        const String height_s = "/peer/height";
        const String status_s = "/peer/status";
      };
    };


  };
};

#endif
