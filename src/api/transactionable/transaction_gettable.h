

#ifndef transaction_gettable_h
#define transaction_gettable_h

namespace ARK {
  namespace API {

    /*  ========================================  */
    /*  PROTECTED: ARK::API::TransactionGettable  */
    class TransactionGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/transactions/get?id=  */
        ARK::Transaction transaction(ARK::Utilities::Network::Manager _netManager, Hash _id);
        ARK::Transaction transactionfromJSON(String _jsonStr);

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks  */
    /*    Peers callback is ~28,000 bytes  */
        /*  /api/transactions  */
        // String transactions(ARK::Utilities::Network::Manager _netManager);
        // String transactionsfromJSON(String _jsonStr);
/*  ==========================================================================  */

        /*  /api/transactions/unconfirmed/get?id=  */
        ARK::Transaction transactionUnconfirmed(ARK::Utilities::Network::Manager _netManager, Hash _id);
        ARK::Transaction transactionUnconfirmedfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/transactions/unconfirmed  */
        ARK::Transaction transactionsUnconfirmed(ARK::Utilities::Network::Manager _netManager);
        ARK::Transaction transactionsUnconfirmedfromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  ========================================  */

  };
};

/*  ==========================================================================  */

/*  ==========================================  */
/*  ARK::API::TransactionGettable::transaction  */

/*  /api/transactions/get?id=  */
ARK::Transaction ARK::API::TransactionGettable::transaction(ARK::Utilities::Network::Manager _netManager, Hash _id) {
  String uri = ARK::API::Endpoints::Transaction::getSingle_s;
    uri += "?id=";
    uri += _id.description();
  String callback = _netManager.cb(uri);
  return ARK::API::TransactionGettable::transactionfromJSON(callback);
}

/*
{ "success":true,
  "transaction":{
    "id":"_txID",
    "blockid":"_blockID",
    "height":_height,
    "type":_type,
    "timestamp":_timestamp,
    "amount":_amount,
    "fee":_fee,
    "vendorField":"_vendorField",
    "senderId":"_senderID",
    "recipientId":"_recipientID",
    "senderPublicKey":"_senderPubkey",
    "signature":"_txSig",
    "confirmations":_confirmations
  }
}
*/
ARK::Transaction ARK::API::TransactionGettable::transactionfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  return {
    jString.valueIn("transaction", "id"),
    jString.valueIn("transaction", "blockid"),
    jString.valueIn("transaction", "height"),
    jString.valueIn("transaction", "type").toInt(),
    jString.valueIn("transaction", "timestamp"),
    jString.valueIn("transaction", "amount"),
    jString.valueIn("transaction", "fee"),
    jString.valueIn("transaction", "vendorField"),
    jString.valueIn("transaction", "senderId"),
    jString.valueIn("transaction", "recipientId"),
    jString.valueIn("transaction", "senderPublicKey"),
    jString.valueIn("transaction", "signature"),
    jString.valueIn("transaction", "confirmations")
  };
}
/*  ==========================================  */

/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
/*  ===========================================  */
/*  ARK::API::TransactionGettable::transactions  */
// /*  /api/transactions */
// String ARK::API::TransactionGettable::transactions(ARK::Utilities::Network::Manager _netManager) {
//   String uri = ARK::API::Endpoints::Transaction::transactions_s;
//   String callback = _netManager.cb(uri);
//   if (callback.indexOf("true") <= 0)
//     return callback;
//   return ARK::API::TransactionGettable::transactionsfromJSON(callback);
// }
// /*
// {
//   "success":true,
//   "transactions":[
//     {
//       "id":"_txID",
//       "blockid":"_blockID",
//       "type":_type,
//       "timestamp":_timestamp,
//       "amount":_amount,
//       "fee":_fee,
//       "vendorField":"_vendorField",
//       "senderId":"_senderID",
//       "recipientId":"_recipientID",
//       "senderPublicKey":"_senderPubkey",
//       "signature":"_txSig",
//       "confirmations":_confirmations
//     },
//     {
//       "id":"_txID",
//       "blockid":"_blockID",
//       "type":_type,
//       "timestamp":_timestamp,
//       "amount":_amount,
//       "fee":_fee,
//       "vendorField":"_vendorField",
//       "senderId":"_senderID",
//       "recipientId":"_recipientID",
//       "senderPublicKey":"_senderPubkey",
//       "signature":"_txSig",
//       "confirmations":_confirmations
//     }
//   ],
//   "count":"193015"
// }
// */
// String ARK::API::TransactionGettable::transactionsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr); 
//   // ARK::Transaction transactions[50];
//   String resp;
//   for (int i = 0; i < 50; i++) {
//     String transactionSubstring = jString.subvalueFor("transactions", i);
//     ARK::Utilities::JSONString transactionJString(transactionSubstring); 
//     ARK::Transaction transaction = {
//       transactionJString.valueFor("id"),
//       transactionJString.valueFor("blockid"),
//       transactionJString.valueFor("height"),
//       transactionJString.valueFor("type").toInt(),
//       transactionJString.valueFor("timestamp"),
//       transactionJString.valueFor("amount"),
//       transactionJString.valueFor("fee"),
//       transactionJString.valueFor("vendorField"),
//       transactionJString.valueFor("senderId"),
//       transactionJString.valueFor("recipientId"),
//       transactionJString.valueFor("senderPublicKey"),
//       transactionJString.valueFor("signature"),
//       transactionJString.valueFor("confirmations")
//     };
//     // String transactionSubstring = jString.subvalueFor(transaction, i);
//     // ARK::Utilities::JSONString transactionJString(transactionSubstring); 
//     // ARK::Transaction transaction = {
//     //   jString.subarrayValueIn("transactions", i, "id"),
//     //   jString.subarrayValueIn("transactions", i, "blockid"),
//     //   jString.subarrayValueIn("transactions", i, "height"),
//     //   jString.subarrayValueIn("transactions", i, "type").toInt(),
//     //   jString.subarrayValueIn("transactions", i, "timestamp"),
//     //   jString.subarrayValueIn("transactions", i, "amount"),
//     //   jString.subarrayValueIn("transactions", i, "fee"),
//     //   jString.subarrayValueIn("transactions", i, "vendorField"),
//     //   jString.subarrayValueIn("transactions", i, "senderId"),
//     //   jString.subarrayValueIn("transactions", i, "recipientId"),
//     //   jString.subarrayValueIn("transactions", i, "senderPublicKey"),
//     //   jString.subarrayValueIn("transactions", i, "signature"),
//     //   jString.subarrayValueIn("transactions", i, "confirmations")
//     // };
//     // transactions[i] = transaction;
//     resp += "transaction ";
//     resp += i + 1;
//     resp += ":\n";
//     resp += transaction.description();
//   };
//   // for (int i = 0; i < 50; i++) {
//   //   resp += "transaction ";
//   //   resp += i + 1;
//   //   resp += ":\n";
//   //   resp += transactions[i].description();
//   // };
//   resp += "\n";
//   return resp;
// }
/*  ===========================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */

/*  =====================================================  */
/*  ARK::API::TransactionGettable::transactionUnconfirmed  */

/*  /api/transactions/unconfirmed/get?id=  */
ARK::Transaction ARK::API::TransactionGettable::transactionUnconfirmed(ARK::Utilities::Network::Manager _netManager, Hash _id) {
  String uri = ARK::API::Endpoints::Transaction::getSingleUnconfirmed_s;
    uri += "?id=";
    uri += _id.description();
  String callback = _netManager.cb(uri);
  return ARK::API::TransactionGettable::transactionUnconfirmedfromJSON(callback);
}

/*
{ 
  "success":true,
  "transaction":{
    "id":"_txID",
    "blockid":"_blockID",
    "height":_height,
    "type":_type,
    "timestamp":_timestamp,
    "amount":_amount,
    "fee":_fee,
    "vendorField":_vendorField,
    "senderId":"_senderId",
    "recipientId":"_recipientId",
    "senderPublicKey":_senderPubkey,
    "signature":"_txSig",
    "confirmations":_confirmations
  }
}
||
{
  "success":false,
  "error":"Transaction not found"
}
*/
ARK::Transaction ARK::API::TransactionGettable::transactionUnconfirmedfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  return {
    jString.valueIn("transaction", "id"),
    jString.valueIn("transaction", "blockid"),
    jString.valueIn("transaction", "height"),
    jString.valueIn("transaction", "type").toInt(),
    jString.valueIn("transaction", "timestamp"),
    jString.valueIn("transaction", "amount"),
    jString.valueIn("transaction", "fee"),
    jString.valueIn("transaction", "vendorField"),
    jString.valueIn("transaction", "senderId"),
    jString.valueIn("transaction", "recipientId"),
    jString.valueIn("transaction", "senderPublicKey"),
    jString.valueIn("transaction", "signature"),
    jString.valueIn("transaction", "confirmations")
  };
}
/*  =====================================================  */

/*  ==========================================================================  */

/*  ======================================================  */
/*  ARK::API::TransactionGettable::transactionsUnconfirmed  */

/*  /api/transactions/unconfirmed  */
ARK::Transaction ARK::API::TransactionGettable::transactionsUnconfirmed(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Transaction::unconfirmed_s;
  String callback = _netManager.cb(uri);
  return ARK::API::TransactionGettable::transactionsUnconfirmedfromJSON(callback);
}

/*
{
  "success":true,
  "transactions":[]
}
*/
ARK::Transaction ARK::API::TransactionGettable::transactionsUnconfirmedfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  if (jString.valueFor("transactions").length() == 2)
    {  return ARK::Transaction(); };
  return {
    jString.valueIn("transaction", "id"),
    jString.valueIn("transaction", "blockid"),
    jString.valueIn("transaction", "height"),
    jString.valueIn("transaction", "type").toInt(),
    jString.valueIn("transaction", "timestamp"),
    jString.valueIn("transaction", "amount"),
    jString.valueIn("transaction", "fee"),
    jString.valueIn("transaction", "vendorField"),
    jString.valueIn("transaction", "senderId"),
    jString.valueIn("transaction", "recipientId"),
    jString.valueIn("transaction", "senderPublicKey"),
    jString.valueIn("transaction", "signature"),
    jString.valueIn("transaction", "confirmations")
  };
}
/*  ======================================================  */


#endif
