

#ifndef MULTISIGNATURE_GETTABLE_H
#define MULTISIGNATURE_GETTABLE_H

#include "connector.h"
#include "publickey.h"

namespace ARK
{
namespace API
{
namespace MultiSignature
{
/*  ==========================================================================  */
/*  =============================================  */
/*  PROTECTED: ARK::API::MultiSignature::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/multisignatures/pending?publicKey=  */
    String pending(ARK::Utilities::Network::Connector& _netConnector, const Publickey& _publicKey);
    String pendingfromJSON(const char* const _jsonStr);
    String pendingfromJSON(const String& _jsonStr) {
        return pendingfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
    /*  Only on Mainnet?  */
    // /*  /api/multisignatures/accounts?publicKey=  */
    // String accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey);
    // /*  ???  */
    // String accountsfromJSON(String _jsonStr);
/*  ==========================================================================  */
/*  ==========================================================================  */
};
/*  =============================================  */
/*  ==========================================================================  */
};
};
};

#endif
