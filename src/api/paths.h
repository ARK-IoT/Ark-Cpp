

#ifndef PATHS_H
#define PATHS_H

namespace ARK
{
namespace API
{

namespace Paths
{

/*  ==========================================================================  */

/* Accounts */
namespace Account
{
const char* getBalance_s = "/api/accounts/getBalance";
const char* getPublickey_s = "/api/accounts/getPublickey";
const char* delegatesFee_s = "/api/accounts/delegates/fee";
const char* delegates_s = "/api/accounts/delegates";
const char* accounts_s = "/api/accounts";
};

/*  ==========================================================================  */

/* Blocks */
namespace Block
{
const char* get_s = "/api/blocks/get"; //using ID
const char* blocks_s = "/api/blocks";
const char* getEpoch_s = "/api/blocks/getEpoch";
const char* getHeight_s = "/api/blocks/getHeight";
const char* getNethash_s = "/api/blocks/getNethash";
const char* getFee_s = "/api/blocks/getFee";
const char* getFees_s = "/api/blocks/getFees";
const char* getMilestone_s = "/api/blocks/getMilestone";
const char* getReward_s = "/api/blocks/getReward";
const char* getSupply_s = "/api/blocks/getSupply";
const char* getStatus_s = "/api/blocks/getStatus";
};

/*  ==========================================================================  */

/* Delegates */
namespace Delegate
{
const char* count_s = "/api/delegates/count";
const char* search_s = "/api/delegates/search";
const char* voters_s = "/api/delegates/voters";
const char* get_s = "/api/delegates/get";
const char* delegates_s = "/api/delegates";
const char* fee_s = "/api/delegates/fee";
const char* getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
const char* getNextForgers_s = "/api/delegates/getNextForgers";
};

/*  ==========================================================================  */

/* Loader */
namespace Loader
{
const char* status_s = "/api/loader/status";
const char* sync_s = "/api/loader/status/sync";
const char* autoconfigure_s = "/api/loader/autoconfigure";
};

/*  ==========================================================================  */

/* Peers */
namespace Peer
{
const char* get_s = "/api/peers/get";
const char* peers_s = "/api/peers";
const char* version_s = "/api/peers/version";
};

/*  ==========================================================================  */

/* Signatures */
namespace Signatures
{
const char* fee_s = "/api/signatures/fee";
};

/*  ==========================================================================  */

/* MultiSignatures */
namespace MultiSignatures
{
const char* pending_s = "/api/multisignatures/pending";
const char* accounts_s = "/api/multisignatures/accounts";
};

/*  ==========================================================================  */

/* Transactions */
namespace Transaction
{
const char* getSingle_s = "/api/transactions/get";
const char* transactions_s = "/api/transactions";
const char* getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get";
const char* unconfirmed_s = "/api/transactions/unconfirmed";
};

/*  ==========================================================================  */

// /* Transport */
// namespace Transport {
//   const char* list_s = "/peer/list";
//   const char* common_s = "/peer/blocks/common";
//   const char* block_s = "/peer/block";
//   const char* blocks_s = "/peer/blocks";
//   const char* transactions_s = "/peer/transactions";
//   const char* transactionsPost_s = "/peer/transactions"; // post
//   const char* transactionsFromIds_s = "/peer/transactionsFromIds";
//   const char* height_s = "/peer/height";
//   const char* status_s = "/peer/status";
// };
};
};
};

#endif
