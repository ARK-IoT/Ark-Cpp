

#ifndef api_h
#define api_h

#include "api_model.h"
#include "api_constants.h"

namespace ARK {
  namespace API {
    
    class API_Manager {

      public:

        API_Manager() {
          ARK::Network _network;
          this->connect(_network);
        };

        API_Manager(ARK::Network _network) {          
          this->connect(_network);
        };

        void connect(ARK::Network _network) {
          this->netManager = ARK::Utilities::Network::Manager(_network);
        };



          /*  /api/accounts/getBalance?address=arkAddress */
          String accountBalance(String _arkAddress)
          { return ARK::API::Account::Get::balance(this->netManager, _arkAddress); };

          /*  /api/accounts/getPublickey?address=arkAddress */
          String accountPublickey(String _arkAddress)
          { return ARK::API::Account::Get::publickey(this->netManager, _arkAddress); };

          /*  /api/accounts/delegates/fee?address=arkAddress  */
          String accountDelegatesFee(String _arkAddress)
          { return ARK::API::Account::Get::delegatesFee(this->netManager, _arkAddress); };

          /*  /api/accounts/delegates?address=arkAddress  */
          String accountDelegates(String _arkAddress)
          { return ARK::API::Account::Get::delegates(this->netManager, _arkAddress); };

          /*  /api/accounts?address=arkAddress  */
          String accounts(String _arkAddress)
          { return ARK::API::Account::Get::accounts(this->netManager, _arkAddress); };








          /*  /api/blocks/get?id=_blockID */
          String block(String _blockId)
          { return ARK::API::Block::Get::block(this->netManager, _blockId); };

/* needs stream->string size fix for large callbacks */
          // /*  /api/blocks */
          // String blocks()
          // { return ARK::API::Block::Get::blocks(this->netManager); };

          /*  /api/blocks/getEpoch  */
          String blockEpoch()
          { return ARK::API::Block::Get::epoch(this->netManager); };

          /*  /api/blocks/getHeight  */
          String blockHeight()
          { return ARK::API::Block::Get::height(this->netManager); };

          /*  /api/blocks/getNethash  */
          String blockNethash()
          { return ARK::API::Block::Get::nethash(this->netManager); };

          /*  /api/blocks/getFee  */
          String blockFee()
          { return ARK::API::Block::Get::fee(this->netManager); };

          /*  /api/blocks/getFees  */
          String blockFees()
          { return ARK::API::Block::Get::fees(this->netManager); };

          /*  /api/blocks/getMilestone  */
          String blockMilestone()
          { return ARK::API::Block::Get::milestone(this->netManager); };

          /*  /api/blocks/getReward  */
          String blockReward()
          { return ARK::API::Block::Get::reward(this->netManager); };

          /*  /api/blocks/getSupply  */
          String blockSupply()
          { return ARK::API::Block::Get::supply(this->netManager); };

          /*  /api/blocks/getStatus  */
          String blockStatus()
          { return ARK::API::Block::Get::status(this->netManager); };






          /*  /api/delegates/count  */
          String delegatesCount()
          { return ARK::API::Delegate::Get::count(this->netManager); };

          /*  /api/delegates/search?q=sleepdeficit  */
          String delegateSearch(String _username)
          { return ARK::API::Delegate::Get::search(this->netManager, _username); };

          // /*  /api/delegates/voters?publicKey=_pubKey  */
          // String delegateVoters(String _publicKey)
          // { return ARK::API::Delegate::Get::voters(this->netManager, _publicKey); };

          // /* 
          //   /api/delegates/get?username=sleepdeficit
          //   /api/delegates/get?publicKey=_pubKey
          // */
          // String delegate(String _parameter)
          // { return ARK::API::Delegate::Get::delegate(this->netManager, _parameter); };

          // /*  /api/delegates  */
          // String delegates()
          // { return ARK::API::Delegate::Get::delegates(this->netManager); };

          /*  /api/delegates/fee  */
          String delegateFee()
          { return ARK::API::Delegate::Get::fee(this->netManager); };

          /*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
          String delegateForgedByAccount(String _generatorPublicKey)
          { return ARK::API::Delegate::Get::forgedByAccount(this->netManager, _generatorPublicKey); };

          /*  /api/delegates/getNextForgers  */
          String delegateNextForgers()
          { return ARK::API::Delegate::Get::nextForgers(this->netManager); };







          /*  /api/loader/status  */
          String loaderStatus()
          { return ARK::API::Loader::Get::status(this->netManager); };

          /*  /api/loader/status/sync  */
          String loaderSync()
          { return ARK::API::Loader::Get::sync(this->netManager); };

          /*  /api/loader/autoconfigure  */
          String loaderAutoconfigure()
          { return ARK::API::Loader::Get::autoconfigure(this->netManager); };





          /*  /api/peers/get?ip=167.114.29.55&port=4002  */
          String peer(String _ip, int _port)
          { return ARK::API::Peer::Get::peer(this->netManager, _ip, _port); };

          /*  /api/peers  */
          String peers()
          { return ARK::API::Peer::Get::peers(this->netManager); };

          /*  /api/peers/version  */
          String peerVersion()
          { return ARK::API::Peer::Get::version(this->netManager); };







          /*  /api/signatures/fee  */
          String signaturesFee()
          { return ARK::API::Signatures::Get::fee(this->netManager); };






          /*  /api/multisignatures/pending?publicKey=  */
          String multisignaturesPending(String _publicKey)
          { return ARK::API::MultiSignatures::Get::pending(this->netManager, _publicKey); };

          /*  /api/multisignatures/accounts?publicKey=  */
          String multisignaturesAccounts(String _publicKey)
          { return ARK::API::MultiSignatures::Get::accounts(this->netManager, _publicKey); };





      // Transaction:
      //   const String getSingle_s = "/api/transactions/get";
    // http://167.114.29.55:4002/api/transactions/get?id=4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e

      //   const String transactions_s = "/api/transactions";
      //   const String getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get"; //
      //   const String unconfirmed_s = "/api/transactions/unconfirmed";


          // /*  /api/multisignatures/pending?publicKey=  */
          // String multisignaturesPending(String _publicKey)
          // { return ARK::API::MultiSignatures::Get::pending(this->netManager, _publicKey); };




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
