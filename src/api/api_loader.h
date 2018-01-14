

#ifndef api_loader_h
#define api_loader_h

namespace ARK {
  namespace API {
    namespace Loader {

      namespace Get {

        /*  /api/loader/status  */
        String status(ARK::Utilities::Network::Manager _netManager);
        String statusfromJSON(String _jsonStr);


        /*  /api/loader/status/sync  */
        String sync(ARK::Utilities::Network::Manager _netManager);
        String syncfromJSON(String _jsonStr);
      

        /*  /api/loader/autoconfigure  */
        String autoconfigure(ARK::Utilities::Network::Manager _netManager);
        String autoconfigurefromJSON(String _jsonStr);

      };

    };
  };
};




/*
{ "success":true,
  "loaded":false,
  "now":1912029,
  "blocksCount":0
}
*/
String ARK::API::Loader::Get::statusfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Loader::StatusResponse status = {
    jString.valueFor("loaded"),
    jString.valueFor("now").toInt(),
    jString.valueFor("blocksCount").toInt()
  };
  return status.description();
};

/*  /api/loader/status  */
String ARK::API::Loader::Get::status(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::status_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Loader::Get::statusfromJSON(callback);
};



/*
{ 
  "success":true,
  "syncing":false,
  "blocks":-16,
  "height":2313438,
  "id":"16889110256993862505"
}
*/
String ARK::API::Loader::Get::syncfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Loader::SyncResponse sync = {
    jString.valueFor("syncing"),
    jString.valueFor("blocks").toInt(),
    jString.valueFor("height").toInt(),
    jString.valueFor("id").toInt()
  };
  return sync.description();
};

/*  /api/loader/status/sync  */
String ARK::API::Loader::Get::sync(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::sync_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Loader::Get::syncfromJSON(callback);
};




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
String ARK::API::Loader::Get::autoconfigurefromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Network network = {
    jString.valueIn("network", "nethash"),
    jString.valueIn("network", "token"),
    jString.valueIn("network", "symbol"),
    jString.valueIn("network", "explorer"),
    jString.valueIn("network", "version").toInt()
  };
  return network.description();
};

/*  /api/loader/autoconfigure  */
String ARK::API::Loader::Get::autoconfigure(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Loader::autoconfigure_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Loader::Get::autoconfigurefromJSON(callback);
};


#endif
