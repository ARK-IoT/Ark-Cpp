

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
    ARK::Transaction transaction(ARK::Utilities::Network::Connector& netConnector, const Hash& id);
    ARK::Transaction transactionfromJSON(const char* const jsonStr);
    ARK::Transaction transactionfromJSON(const String& _jsonStr) {
        return transactionfromJSON(_jsonStr.c_str());
    }
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
        ARK::Utilities::Network::Connector& netConnector,
        const Hash& id);
        
    String transactionUnconfirmedfromJSON(const char* const jsonStr);
    String transactionUnconfirmedfromJSON(const String& _jsonStr) {
        return transactionUnconfirmedfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/transactions/unconfirmed  */
    String transactionsUnconfirmed(ARK::Utilities::Network::Connector& netConnector);
    String transactionsUnconfirmedfromJSON(const char* const jsonStr);
    String transactionsUnconfirmedfromJSON(const String& _jsonStr) {
        return transactionsUnconfirmedfromJSON(_jsonStr.c_str());
    }
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
    ARK::Utilities::Network::Connector& netConnector, 
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

    return ARK::Transaction(
        jString.valueIn("transaction", "id").c_str(),
        jString.valueIn("transaction", "blockid").c_str(),
        jString.valueIn("transaction", "height").c_str(),
        jString.valueIn("transaction", "type").toInt(),
        jString.valueIn("transaction", "timestamp").c_str(),
        jString.valueIn("transaction", "amount").c_str(),
        jString.valueIn("transaction", "fee").c_str(),
        jString.valueIn("transaction", "vendorField").c_str(),
        // jString.valueIn("transaction", "senderId").c_str(),
        temp,
        // jString.valueIn("transaction", "recipientId").c_str(),
        temp2,
        jString.valueIn("transaction", "senderPublicKey").c_str(),
        jString.valueIn("transaction", "signature").c_str(),
        jString.valueIn("transaction", "confirmations").c_str()
    );
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
    ARK::Utilities::Network::Connector& netConnector, 
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
  if (strstr(jsonStr, "Transaction not found") != nullptr) {
    resp += "There are currently No unconfirmed transactions by that transactionID";
  } else {
    ARK::Transaction transaction(
      jString.valueIn("transaction", "id").c_str(),
      jString.valueIn("transaction", "blockid").c_str(),
      jString.valueIn("transaction", "height").c_str(),
      jString.valueIn("transaction", "type").toInt(),
      jString.valueIn("transaction", "timestamp").c_str(),
      jString.valueIn("transaction", "amount").c_str(),
      jString.valueIn("transaction", "fee").c_str(),
      jString.valueIn("transaction", "vendorField").c_str(),
      jString.valueIn("transaction", "senderId").c_str(),
      jString.valueIn("transaction", "recipientId").c_str(),
      jString.valueIn("transaction", "senderPublicKey").c_str(),
      jString.valueIn("transaction", "signature").c_str(),
      jString.valueIn("transaction", "confirmations").c_str()
    );
    char buf[128] = {};
    transaction.description(buf, sizeof(buf) / sizeof(buf[0]));
    resp += buf;
  }
  return resp;
}
/*  =====================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================================  */
/*  ARK::API::Transaction::Gettable::transactionsUnconfirmed  */
/*  /api/transactions/unconfirmed  */
String ARK::API::Transaction::Gettable::transactionsUnconfirmed(
    ARK::Utilities::Network::Connector& netConnector
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

      ARK::Transaction transaction(
        jString.subarrayValueIn("transaction", i, "id").c_str(),
        jString.subarrayValueIn("transaction", i,  "blockid").c_str(),
        jString.subarrayValueIn("transaction", i,  "height").c_str(),
        jString.subarrayValueIn("transaction", i,  "type").toInt(),
        jString.subarrayValueIn("transaction", i,  "timestamp").c_str(),
        jString.subarrayValueIn("transaction", i,  "amount").c_str(),
        jString.subarrayValueIn("transaction", i,  "fee").c_str(),
        jString.subarrayValueIn("transaction", i,  "vendorField").c_str(),
        jString.subarrayValueIn("transaction", i,  "senderId").c_str(),
        jString.subarrayValueIn("transaction", i,  "recipientId").c_str(),
        jString.subarrayValueIn("transaction", i,  "senderPublicKey").c_str(),
        jString.subarrayValueIn("transaction", i,  "signature").c_str(),
        jString.subarrayValueIn("transaction", i,  "confirmations").c_str()
      );

      resp += "\ntransaction ";
      resp += i + 1;
      resp += ":\n";
      char buf[128] = {};
      transaction.description(buf, sizeof(buf) / sizeof(buf[0]));
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
