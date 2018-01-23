
```
==================== Accounts ====================  

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

==================== /Accounts ====================
```

```
==================== Blocks ====================  

    /api/blocks/get?id=_blockID  
      String block(String _blockId)  

/*  ==========================================================================  */
// BROKEN: fix for large callbacks  
//     /api/blocks  
//       String blocks()  
/*  ==========================================================================  */

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

==================== /Blocks ====================  
```

```
==================== Delegates ====================  

    /api/delegates/count  
      String delegatesCount()  

    /api/delegates/search?q=sleepdeficit  
      String delegateSearch(String _username)  

    /api/delegates/voters?publicKey=_pubKey  
      String delegateVoters(String _publicKey)  

  
    /api/delegates/get?username=sleepdeficit  
    /api/delegates/get?publicKey=_pubKey  
      String delegate(String _parameter)  

/*  ==========================================================================  */
// BROKEN: fix for large callbacks  
// Delegates callback is ~13,564 bytes  
//    /api/delegates  
//      String delegates()  
/*  ==========================================================================  */

    /api/delegates/fee  
      String delegateFee()  

    /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  
      String delegateForgedByAccount(String _generatorPublicKey)  

    /api/delegates/getNextForgers  
      String delegateNextForgers()  

==================== /Delegates ====================  
```

```
==================== Loader ====================  

    /api/loader/status  
      String loaderStatus()  

    /api/loader/status/sync  
      String loaderSync()  

    /api/loader/autoconfigure  
      String loaderAutoconfigure()  

==================== /Loader ====================  
```

```
==================== MultiSignatures ====================  

    /api/multisignatures/pending?publicKey=  
      String multisignaturesPending(String _publicKey)  

/*  ==========================================================================  */
// Only on Mainnet?  
//     /api/multisignatures/accounts?publicKey=  
//       String multisignaturesAccounts(String _publicKey)  
/*  ==========================================================================  */

==================== /MultiSignatures ====================  
```

```
==================== Peer ====================  

    /api/peers/get?ip=167.114.29.55&port=4002  
      String peer(String _ip, int _port)  

/*  ==========================================================================  */
// BROKEN: fix for large callbacks  
// Peers callback is ~10,792 bytes  
//     /api/peers  
//      String peers()  
/*  ==========================================================================  */

    /api/peers/version  
      String peerVersion()  

==================== /Peer ====================  
```

```
==================== Signatures ====================  

    /api/signatures/fee
      String signaturesFee()

==================== /Signatures ====================  
```

```
==================== Transaction ====================  

    /api/transactions/get?id=  
      String transaction(String _id)  

/*  ==========================================================================  */
//  BROKEN: fix for large callbacks  
//  Peers callback is ~28,908 bytes  
//    /api/transactions  
//      String transactions()  
/*  ==========================================================================  */

    /api/transactions/unconfirmed/get?id=  
      String transactionUnconfirmed(String _id)  

    /api/transactions/unconfirmed  
      String transactionsUnconfirmed()  
   
==================== /Transaction ====================  
```
