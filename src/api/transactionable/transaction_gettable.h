

#ifndef TRANSACTION_GETTABLE_H
#define TRANSACTION_GETTABLE_H

#include "transaction.h"
#include "connector.h"
#include "hash.h"

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

#endif
