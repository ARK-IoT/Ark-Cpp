

#ifndef LOADER_GETTABLE_H
#define LOADER_GETTABLE_H

#include "loader_respondable.h"
#include "connector.h"

namespace ARK
{
namespace API
{
namespace Loader
{

/*  ==========================================================================  */
/*  =====================================  */
/*  PROTECTED: ARK::API::Loader::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/loader/status  */
    ARK::API::Loader::Respondable::Status status(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Loader::Respondable::Status statusfromJSON(const char* const _jsonStr);
    ARK::API::Loader::Respondable::Status statusfromJSON(const String& _jsonStr) {
        return statusfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/status/sync  */
    ARK::API::Loader::Respondable::Sync sync(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const _jsonStr);
    ARK::API::Loader::Respondable::Sync syncfromJSON(const String& _jsonStr) {
        return syncfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/autoconfigure  */
    ARK::Network autoconfigure(ARK::Utilities::Network::Connector& _netConnector);
    ARK::Network autoconfigurefromJSON(const char* const _jsonStr);
    ARK::Network autoconfigurefromJSON(const String& _jsonStr) {
        return autoconfigurefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  =====================================  */
/*  ==========================================================================  */
};
};
};

#endif
