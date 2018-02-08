

#ifndef LOADER_GETTABLE_H
#define LOADER_GETTABLE_H

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




/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::Loader::Gettable::status  */
/*  /api/loader/status  */
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::status(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::status_s);

  return ARK::API::Loader::Gettable::statusfromJSON(callback);
}

/*
{ 
  "success":true,
  "loaded": bool,
  "now":  int,
  "blocksCount":  String
}
*/
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::statusfromJSON(const char* const _jsonStr)
{
    ARK::Utilities::JSONString jString(_jsonStr);

    return ARK::API::Loader::Respondable::Status(
        jString.valueFor("loaded").c_str(),
        jString.valueFor("now").toInt(),
        jString.valueFor("blocksCount").c_str()
    );
}
/*  ================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Loader::Gettable::sync  */
/*  /api/loader/status/sync  */
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::sync(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::sync_s);

  return ARK::API::Loader::Gettable::syncfromJSON(callback);
}

/*
{ 
  "success":true,
  "syncing":  bool,
  "blocks": int,
  "height": String,
  "id": "String"
}
*/
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::syncfromJSON(const char* const _jsonStr)
{
    ARK::Utilities::JSONString jString(_jsonStr);

    return ARK::API::Loader::Respondable::Sync(
        jString.valueFor("syncing").c_str(),
        jString.valueFor("blocks").toInt(),
        jString.valueFor("height").c_str(),
        jString.valueFor("id").c_str()
    );
}
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Loader::Gettable::autoconfigure  */
/*  /api/loader/autoconfigure  */
ARK::Network ARK::API::Loader::Gettable::autoconfigure(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::autoconfigure_s);

  return ARK::API::Loader::Gettable::autoconfigurefromJSON(callback);
}

/*
{
  "success":true,
  "network":{
    "nethash":  "Hash",
    "token":  "String",
    "symbol": "String,
    "explorer": "String",
    "version":  int
  }
}
*/
ARK::Network ARK::API::Loader::Gettable::autoconfigurefromJSON(const char* const _jsonStr)
{
    ARK::Utilities::JSONString jString(_jsonStr);

    return ARK::Network(
        jString.valueIn("network", "nethash").c_str(),
        jString.valueIn("network", "token").c_str(),
        jString.valueIn("network", "symbol").c_str(),
        jString.valueIn("network", "explorer").c_str(),
        jString.valueIn("network", "version").toInt()
    );
}
/*  =======================================  */
/*  ==========================================================================  */


#endif
