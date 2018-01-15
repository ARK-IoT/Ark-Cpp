

#ifndef api_h
#define api_h

#include "../utilities/utilities.h"

#include "api_helpers.h"
#include "api_constants.h"

#include "accountable.h"
#include "blockable.h"
#include "delegatable.h"
#include "errorable.h"
#include "loadable.h"
#include "multisignaturable.h"
#include "networkable.h"
#include "peerable.h"
#include "signaturable.h"
#include "transactionable.h"
#include "transportable.h"
#include "votable.h"


namespace ARK {
  namespace API {

    class Manager :
      public ARK::API::Accountable, 
      public ARK::API::Blockable,
      public Delegatable, 
      public Loadable,
      public MultiSignaturable,
      public Peerable,
      public Signaturable,
      public Transactionable,
      virtual ARK::Utilities::Network::Managable {

      public:

        Manager();
        Manager(ARK::Network _network);
        void connect(ARK::Network _network);

    };

  };
};


ARK::API::Manager::Manager() {
  ARK::Network _network;
  this->connect(_network);
};

ARK::API::Manager::Manager(ARK::Network _network) {          
  this->connect(_network);
};

void ARK::API::Manager::connect(ARK::Network _network) {
  this->netManager = ARK::Utilities::Network::Manager(_network);
};



/* ==================== Accounts ==================== */
  /*

    /api/accounts/getBalance?address=arkAddress
      String accountBalance(String _arkAddress)

    /api/accounts/getPublickey?address=arkAddress
      String accountPublickey(String _arkAddress)

    /api/accounts/delegates/fee?address=arkAddress
      String accountDelegatesFee(String _arkAddress)

    /api/accounts/delegates?address=arkAddress
      String accountDelegates(String _arkAddress)

    /api/accounts?address=arkAddress
      String account(String _arkAddress)

  */
/* ==================== /Accounts ====================  */


/* ==================== Blocks ==================== */
  /* 

    /api/blocks/get?id=_blockID
      String block(String _blockId)


// *    BROKEN: fix for large callbacks    *
    // /api/blocks
    //   String blocks()


    /api/blocks/getEpoch
      String blockEpoch()

    /api/blocks/getHeight
      String blockHeight()

    /api/blocks/getNethash
      String blockNethash()

    /api/blocks/getFee
      String blockFee()

    /api/blocks/getFees
      String blockFees()

    /api/blocks/getMilestone
      String blockMilestone()

    /api/blocks/getReward
      String blockReward()

    /api/blocks/getSupply
      String blockSupply()

    /api/blocks/getStatus
      String blockStatus()

  */
/* ==================== /Blocks ====================  */


/* ==================== Delegates ====================  */
  /*

    /api/delegates/count
      String delegatesCount()

    /api/delegates/search?q=sleepdeficit
      String delegateSearch(String _username)

    /api/delegates/voters?publicKey=_pubKey
      String delegateVoters(String _publicKey)

  
    /api/delegates/get?username=sleepdeficit
    /api/delegates/get?publicKey=_pubKey
      String delegate(String _parameter)


// *    BROKEN: fix for large callbacks    *
// *  Delegates callback is ~13,564 bytes  *
    // /api/delegates
    //   String delegates()


    /api/delegates/fee
      String delegateFee()

    /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
      String delegateForgedByAccount(String _generatorPublicKey)

    /api/delegates/getNextForgers
      String delegateNextForgers()

  */
/* ==================== /Delegates ====================*/


/* ==================== Loader ====================*/
  /*

    /api/loader/status
      String loaderStatus()

    /api/loader/status/sync
      String loaderSync()

    /api/loader/autoconfigure
      String loaderAutoconfigure()

  */
/* ==================== /Loader ====================*/


/* ==================== MultiSignatures ====================*/
  /*

    /api/multisignatures/pending?publicKey=
      String multisignaturesPending(String _publicKey)


// *  Only on Mainnet?  *
    // /api/multisignatures/accounts?publicKey=
    //   String multisignaturesAccounts(String _publicKey)


  */
/* ==================== /MultiSignatures ====================*/


/* ==================== Peer ====================*/
  /*

    /api/peers/get?ip=167.114.29.55&port=4002
      String peer(String _ip, int _port)


// *    BROKEN: fix for large callbacks  *
// *    Peers callback is ~10,792 bytes  *
    // /api/peers
    //  String peers()


    /api/peers/version
      String peerVersion()

  */
/* ==================== /Peer ====================*/


/* ==================== Signatures ====================*/
  /*
  
    /api/signatures/fee
      String signaturesFee()

  */
/* ==================== /Signatures ====================*/


/* ==================== Transaction ====================*/
  /*
  
    /api/transactions/get?id=
      String transaction(String _id)


// *    BROKEN: fix for large callbacks  *
// *    Peers callback is ~28,908 bytes  *
    /api/transactions
      String transactions()


    /api/transactions/unconfirmed/get?id=
      String transactionUnconfirmed(String _id)

    /api/transactions/unconfirmed
      String transactionsUnconfirmed()
        
  */
/* ==================== /Transaction ====================*/




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

/* ==================== Transport ====================*/
  /*
  
        
  */
/* ==================== /Transport ====================*/


#endif
