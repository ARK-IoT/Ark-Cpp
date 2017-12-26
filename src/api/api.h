

#ifndef api_h
#define api_h

#include "api_models.h"

namespace api_n {

  
    /* Accounts */
    namespace account_n {
      String getBalance_s = "/api/accounts/getBalance";
      String getPublickey_s = "/api/accounts/getPublickey";
      String delegatesFee_s = "/api/accounts/delegates/fee";
      String delegates_s = "/api/accounts/delegates";
      String accounts_s = "/api/accounts";
      String top_s = "/api/accounts/top";
    };
    

    /* Blocks */  
    namespace block_n {
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
    namespace delegate_n {
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
    namespace loader_n {
      String status_s = "/api/loader/status";
      String sync_s = "/api/loader/status/sync";
      String autoconfigure_s = "/api/loader/autoconfigure";
    };


    /* Peers */
    namespace peers_n {
      String get_s = "/api/peers/get";
      String peers_s = "/api/peers";
      String version_s = "/api/peers/version";
    };
    

    /* Signatures */
    namespace signatures_n {
      String fee_s = "/api/signatures/fee";
    };
    

    /* MultiSignatures */
    namespace multisignatures_n {
      String pending_s = "/api/multisignatures/pending";
      String accounts_s = "/api/multisignatures/accounts";
    };
    

    /* Transactions */
    namespace transactions_n {
      String getSingle_s = "/api/transactions/get";
      String transactions_s = "/api/transactions";
      String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get"; //
      String unconfirmed_s = "/api/transactions/unconfirmed";
    };
    
    
    /* Transport */
    namespace transport_n {
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

#endif
