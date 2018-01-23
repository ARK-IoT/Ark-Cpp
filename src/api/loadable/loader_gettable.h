

#ifndef loader_gettable_h
#define loader_gettable_h

namespace ARK {
  namespace API {

    /*  ===================================  */
    /*  PROTECTED: ARK::API::LoaderGettable  */
    class LoaderGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/loader/status  */
        ARK::Loader::StatusResponse status(ARK::Utilities::Network::Manager _netManager);
        ARK::Loader::StatusResponse statusfromJSON(String _jsonStr);

/*  ==========================================================================  */

        /*  /api/loader/status/sync  */
        ARK::Loader::SyncResponse sync(ARK::Utilities::Network::Manager _netManager);
        ARK::Loader::SyncResponse syncfromJSON(String _jsonStr);
      
/*  ==========================================================================  */

        /*  /api/loader/autoconfigure  */
        ARK::Network autoconfigure(ARK::Utilities::Network::Manager _netManager);
        ARK::Network autoconfigurefromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  ===================================  */

  };
};

/*  ==========================================================================  */

/*  ================================  */
/*  ARK::API::LoaderGettable::status  */

/*  /api/loader/status  */
ARK::Loader::StatusResponse ARK::API::LoaderGettable::status(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::status_s;
  String callback = _netManager.cb(uri);
  return ARK::API::LoaderGettable::statusfromJSON(callback);
}

/*
{ 
  "success":true,
  "loaded":false,
  "now":1912029,
  "blocksCount":0
}
*/
ARK::Loader::StatusResponse ARK::API::LoaderGettable::statusfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueFor("loaded"),
    jString.valueFor("now").toInt(),
    jString.valueFor("blocksCount")
  };
}
/*  ================================  */

/*  ==========================================================================  */

/*  ==============================  */
/*  ARK::API::LoaderGettable::sync  */

/*  /api/loader/status/sync  */
ARK::Loader::SyncResponse ARK::API::LoaderGettable::sync(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::sync_s;
  String callback = _netManager.cb(uri);
  return ARK::API::LoaderGettable::syncfromJSON(callback);
}

/*
{ 
  "success":true,
  "syncing":false,
  "blocks":-16,
  "height":2313438,
  "id":"16889110256993862505"
}
*/
ARK::Loader::SyncResponse ARK::API::LoaderGettable::syncfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueFor("syncing"),
    jString.valueFor("blocks").toInt(),
    jString.valueFor("height"),
    jString.valueFor("id")
  };
}
/*  ==============================  */

/*  ==========================================================================  */

/*  =======================================  */
/*  ARK::API::LoaderGettable::autoconfigure  */

/*  /api/loader/autoconfigure  */
ARK::Network ARK::API::LoaderGettable::autoconfigure(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::autoconfigure_s;
  String callback = _netManager.cb(uri);
  return ARK::API::LoaderGettable::autoconfigurefromJSON(callback);
}

/*
{
  "success":true,
  "network":{
    "nethash":"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
    "token":"DARK",
    "symbol":"DѦ",
    "explorer":"http://dexplorer.ark.io",
    "version":30
  }
}
*/
ARK::Network ARK::API::LoaderGettable::autoconfigurefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
   return {
    jString.valueIn("network", "nethash"),
    jString.valueIn("network", "token"),
    jString.valueIn("network", "symbol"),
    jString.valueIn("network", "explorer"),
    jString.valueIn("network", "version").toInt()
  };
}
/*  =======================================  */


#endif
