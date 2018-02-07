

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
    ARK::API::Loader::Respondable::Status status(const ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Loader::Respondable::Status statusfromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/status/sync  */
    ARK::API::Loader::Respondable::Sync sync(const ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/autoconfigure  */
    ARK::Network autoconfigure(const ARK::Utilities::Network::Connector& _netConnector);
    ARK::Network autoconfigurefromJSON(const char* const _jsonStr);
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
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::status(const ARK::Utilities::Network::Connector& _netConnector)
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

  return {
      jString.valueFor("loaded"),
      jString.valueFor("now").toInt(),
      jString.valueFor("blocksCount")};
}
/*  ================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Loader::Gettable::sync  */
/*  /api/loader/status/sync  */
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::sync(const ARK::Utilities::Network::Connector& _netConnector)
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

  return {
      jString.valueFor("syncing"),
      jString.valueFor("blocks").toInt(),
      jString.valueFor("height"),
      jString.valueFor("id")};
}
/*  ==============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Loader::Gettable::autoconfigure  */
/*  /api/loader/autoconfigure  */
ARK::Network ARK::API::Loader::Gettable::autoconfigure(const ARK::Utilities::Network::Connector& _netConnector)
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

  return {
      jString.valueIn("network", "nethash"),
      jString.valueIn("network", "token"),
      jString.valueIn("network", "symbol"),
      jString.valueIn("network", "explorer"),
      jString.valueIn("network", "version").toInt()};
}
/*  =======================================  */
/*  ==========================================================================  */


#endif
