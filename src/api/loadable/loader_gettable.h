

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
    ARK::API::Loader::Respondable::Status status(ARK::Utilities::Network::Connector _netConnector);
    ARK::API::Loader::Respondable::Status statusfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/status/sync  */
    ARK::API::Loader::Respondable::Sync sync(ARK::Utilities::Network::Connector _netConnector);
    ARK::API::Loader::Respondable::Sync syncfromJSON(String _jsonStr);
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/loader/autoconfigure  */
    ARK::Network autoconfigure(ARK::Utilities::Network::Connector _netConnector);
    ARK::Network autoconfigurefromJSON(String _jsonStr);
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
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::status(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Loader::status_s;

  String callback = _netConnector.cb(uri);

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
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::statusfromJSON(String _jsonStr)
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
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::sync(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Loader::sync_s;

  String callback = _netConnector.cb(uri);

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
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::syncfromJSON(String _jsonStr)
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
ARK::Network ARK::API::Loader::Gettable::autoconfigure(ARK::Utilities::Network::Connector _netConnector)
{
  String uri = ARK::API::Paths::Loader::autoconfigure_s;

  String callback = _netConnector.cb(uri);

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
ARK::Network ARK::API::Loader::Gettable::autoconfigurefromJSON(String _jsonStr)
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
