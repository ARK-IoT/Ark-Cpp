

#ifndef transactionable_h
#define transactionable_h

namespace ARK {
  namespace API {


    class TransactionGettable {
      protected:

        /*  /api/transactions/get?id=  */
        String transaction(ARK::Utilities::Network::Manager _netManager, String _id);
        String transactionfromJSON(String _jsonStr);


/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
        /*  /api/transactions  */
        // String transactions(ARK::Utilities::Network::Manager _netManager);
        // String transactionsfromJSON(String _jsonStr);


        /*  /api/transactions/unconfirmed/get?id=  */
        String transactionUnconfirmed(ARK::Utilities::Network::Manager _netManager, String _id);
        String transactionUnconfirmedfromJSON(String _jsonStr);

        /*  /api/transactions/unconfirmed  */
        String transactionsUnconfirmed(ARK::Utilities::Network::Manager _netManager);
        String transactionsUnconfirmedfromJSON(String _jsonStr);

    };


    class Transactionable : public TransactionGettable, virtual ARK::Utilities::Network::Managable {
      public: 

        /*  /api/transactions/get?id=  */
        String transaction(String _id)
        { return ARK::API::TransactionGettable::transaction(this->netManager, _id); };


/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
        /*  /api/transactions  */
        // String transactions()
        // { return ARK::API::TransactionGettable::transactions(this->netManager); };


        /*  /api/transactions/unconfirmed/get?id=  */
        String transactionUnconfirmed(String _id)
        { return ARK::API::TransactionGettable::transactionUnconfirmed(this->netManager, _id); };

        /*  /api/transactions/unconfirmed/  */
        String transactionsUnconfirmed()
        { return ARK::API::TransactionGettable::transactionsUnconfirmed(this->netManager); };


        /*    BROKEN: fix for large callbacks  */
        /*    Peers callback is ~28,908 bytes  */
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
        // /*  /api/transactions */
        // String ARK::API::TransactionGettable::transactions(ARK::Utilities::Network::Manager _netManager) {
        //   String uri = ARK::API::Endpoints::Transaction::transactions_s;
        //   String callback = _netManager.cb(uri);
        //   if (callback.indexOf("true") <= 0)
        //     return callback;
        //   return ARK::API::TransactionGettable::transactionsfromJSON(callback);
        // }


    };


  // namespace transaction_cb {
  //   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
  // };


  };
};




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
String ARK::API::TransactionGettable::transactionfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  ARK::Transaction transaction = {
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
  return transaction.description();
}

/*  /api/transactions/get?id=  */
String ARK::API::TransactionGettable::transaction(ARK::Utilities::Network::Manager _netManager, String _id) {
  String uri = ARK::API::Endpoints::Transaction::getSingle_s;
    uri += "?id=";
    uri += _id;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) { return callback; }
  else { return ARK::API::TransactionGettable::transactionfromJSON(callback); };
};




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
String ARK::API::TransactionGettable::transactionUnconfirmedfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  ARK::Transaction transaction = {
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
  return transaction.description();
}

/*  /api/transactions/unconfirmed/get?id=  */
String ARK::API::TransactionGettable::transactionUnconfirmed(ARK::Utilities::Network::Manager _netManager, String _id) {
  String uri = ARK::API::Endpoints::Transaction::getSingleUnconfirmed_s;
    uri += "?id=";
    uri += _id;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) {  return ARK::Utilities::JSONString(callback).valueFor("error"); }
  else { return ARK::API::TransactionGettable::transactionUnconfirmedfromJSON(callback); };
};




/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::TransactionGettable::transactionsUnconfirmedfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr); 
  if (jString.valueFor("transactions").length() == 2)
    {  return "No Unconfirmed Transactions Found"; }
  ARK::Transaction transaction = {
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
  return transaction.description();
}

/*  /api/transactions/unconfirmed  */
String ARK::API::TransactionGettable::transactionsUnconfirmed(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Transaction::unconfirmed_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("false") > 0) {  return callback; }
  else { return ARK::API::TransactionGettable::transactionsUnconfirmedfromJSON(callback); };
};


#endif
