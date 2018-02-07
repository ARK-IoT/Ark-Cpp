

#ifndef TRANSACTION_GETTABLE_H
#define TRANSACTION_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Transaction
{

/*  ==========================================================================  */
/*  ==========================================  */
/*  PROTECTED: ARK::API::Transaction::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/transactions/get?id=  */
    ARK::Transaction transaction(const ARK::Utilities::Network::Connector& netConnector, const Hash& id);
    ARK::Transaction transactionfromJSON(const char* const jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,000 bytes  */
    /*  /api/transactions  */
    // String transactions(ARK::Utilities::Network::Connector netConnector);
    // String transactionsfromJSON(String jsonStr);
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/transactions/unconfirmed/get?id=  */
    String transactionUnconfirmed(
        const ARK::Utilities::Network::Connector& netConnector,
        const Hash& id);
        
    String transactionUnconfirmedfromJSON(const char* const jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/transactions/unconfirmed  */
    String transactionsUnconfirmed(const ARK::Utilities::Network::Connector& netConnector);
    String transactionsUnconfirmedfromJSON(const char* const jsonStr);
/*  ==========================================================================  */

};
/*  ==========================================  */
/*  ==========================================================================  */

};
};
};




/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Transaction::Gettable::transaction  */
/*  /api/transactions/get?id=  */
ARK::Transaction ARK::API::Transaction::Gettable::transaction(
    const ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[64] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
    strcat(uri, "?id=");
    strcat(uri, id.description());

    auto callback = netConnector.cb(uri);
    return ARK::API::Transaction::Gettable::transactionfromJSON(callback);
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
ARK::Transaction ARK::API::Transaction::Gettable::transactionfromJSON(const char* const jsonStr) {
  ARK::Utilities::JSONString jString(jsonStr); 

  char temp[34];
  jString.valueIn("transaction", "senderId").toCharArray(temp, 34);

  char temp2[34];
  jString.valueIn("transaction", "recipientId").toCharArray(temp, 34);

  return {
    jString.valueIn("transaction", "id"),
    jString.valueIn("transaction", "blockid"),
    jString.valueIn("transaction", "height"),
    jString.valueIn("transaction", "type").toInt(),
    jString.valueIn("transaction", "timestamp"),
    jString.valueIn("transaction", "amount"),
    jString.valueIn("transaction", "fee"),
    jString.valueIn("transaction", "vendorField"),
    // jString.valueIn("transaction", "senderId"),
    temp,
    // jString.valueIn("transaction", "recipientId"),
    temp2,
    jString.valueIn("transaction", "senderPublicKey"),
    jString.valueIn("transaction", "signature"),
    jString.valueIn("transaction", "confirmations")
  };
}
/*  ============================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
/*  ===========================================  */
/*  ARK::API::Transaction::Gettable::transactions  */
// /*  /api/transactions */
// String ARK::API::Transaction::Gettable::transactions(ARK::Utilities::Network::Connector netConnector) {
//   String uri = ARK::API::Paths::Transaction::transactions_s;
//   String callback = netConnector.cb(uri);
//   if (callback.indexOf("true") <= 0)
//     return callback;
//   return ARK::API::Transaction::Gettable::transactionsfromJSON(callback);
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
// String ARK::API::Transaction::Gettable::transactionsfromJSON(String jsonStr) {
//   ARK::Utilities::JSONString jString(jsonStr); 
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




/*  ==========================================================================  */
/*  =====================================================  */
/*  ARK::API::Transaction::Gettable::transactionUnconfirmed  */
/*  /api/transactions/unconfirmed/get?id=  */
String ARK::API::Transaction::Gettable::transactionUnconfirmed(
    const ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[64] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
    strcat(uri, "?id=");
    strcat(uri, id.description());

    auto callback = netConnector.cb(uri);
    return ARK::API::Transaction::Gettable::transactionUnconfirmedfromJSON(callback);
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
String ARK::API::Transaction::Gettable::transactionUnconfirmedfromJSON(const char* const jsonStr) {
  ARK::Utilities::JSONString jString(jsonStr); 
  String resp;
  if (jsonStr.indexOf("Transaction not found")) {
    resp += "There are currently No unconfirmed transactions by that transactionID";
  } else {
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
    resp += transaction.description();
  };
  return resp;
}
/*  =====================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================================  */
/*  ARK::API::Transaction::Gettable::transactionsUnconfirmed  */
/*  /api/transactions/unconfirmed  */
String ARK::API::Transaction::Gettable::transactionsUnconfirmed(
    const ARK::Utilities::Network::Connector& netConnector
) {
    auto callback = netConnector.cb(ARK::API::Paths::Transaction::unconfirmed_s);

    return ARK::API::Transaction::Gettable::transactionsUnconfirmedfromJSON(callback);
}

/*
{
  "success":true,
  "transactions":[]
}
*/
String ARK::API::Transaction::Gettable::transactionsUnconfirmedfromJSON(const char* const jsonStr) {
  ARK::Utilities::JSONString jString(jsonStr); 

  int txCount = ARK::API::Helpers::substringCount(jsonStr, "id");

  String resp;
  if (txCount > 0) {

    for (int i = 0; i <= txCount; i++) {

      ARK::Transaction transaction = {
        jString.subarrayValueIn("transaction", i, "id"),
        jString.subarrayValueIn("transaction", i,  "blockid"),
        jString.subarrayValueIn("transaction", i,  "height"),
        jString.subarrayValueIn("transaction", i,  "type").toInt(),
        jString.subarrayValueIn("transaction", i,  "timestamp"),
        jString.subarrayValueIn("transaction", i,  "amount"),
        jString.subarrayValueIn("transaction", i,  "fee"),
        jString.subarrayValueIn("transaction", i,  "vendorField"),
        jString.subarrayValueIn("transaction", i,  "senderId"),
        jString.subarrayValueIn("transaction", i,  "recipientId"),
        jString.subarrayValueIn("transaction", i,  "senderPublicKey"),
        jString.subarrayValueIn("transaction", i,  "signature"),
        jString.subarrayValueIn("transaction", i,  "confirmations")
      };

      resp += "\ntransaction ";
      resp += i + 1;
      resp += ":\n";
      resp += transaction.description();
      resp += "\n";
    };

  } else {
    resp += "There are currently No Unconfirmed Transactions";
  };
  return resp;
}
/*  ======================================================  */
/*  ==========================================================================  */




#endif
