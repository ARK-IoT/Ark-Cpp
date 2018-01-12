

#ifndef api_loader_h
#define api_loader_h

namespace ARK {
  namespace API {
    namespace Loader {


      namespace Get {

        struct statusResponse : virtual ARK::API::Helpers::Successable {
          public:
            bool loaded;
            int now;
            int blocksCount;

            statusResponse() {
              this->loaded = false;
              this->now = 0;
              this->blocksCount = 0;
            };

            statusResponse(bool _loaded, int _now, int _blocksCount) {
              this->loaded =_loaded;
              this->now = _now;
              this->blocksCount = _blocksCount;
            };

            String description() {
              String resp;
                resp += "loaded: ";
                resp += this->loaded; resp += "\n";
                resp += "now: ";
                resp += this->now; resp += "\n";
                resp += "blocksCount: ";
                resp += this->blocksCount; resp += "\n";
              return resp;
            };
        };
        /*
        { "success":true,
          "loaded":false,
          "now":1912029,
          "blocksCount":0
        }
        */
        String statusfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          statusResponse status = {
            jString.valueFor("loaded"),
            jString.valueFor("now").toInt(),
            jString.valueFor("blocksCount").toInt()
          };
          return status.description();
        };
      
        /*  /api/loader/status  */
        String status(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Loader::status_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Loader::Get::statusfromJSON(callback);
        };




        struct syncResponse : virtual ARK::API::Helpers::Successable {
          public:
            bool syncing;
            int blocks;
            int height;
            int id;

            syncResponse() {
              this->syncing = false;
              this->blocks = 0;
              this->height = 0;
              this->id = 0;
            };

            syncResponse(bool _syncing, int _blocks, int _height, int _id) {
              this->syncing = _syncing;
              this->blocks = _blocks;
              this->height = _height;
              this->id = _id;
            };

            String description() {
              String resp;
                resp += "syncing: ";
                  resp += this->syncing; resp += "\n";           
                resp += "blocks: ";
                  resp += this->blocks; resp += "\n";
                resp += "height: ";
                  resp += this->height; resp += "\n";
                resp += "id: ";
                  resp += this->id; resp += "\n";
              return resp;
            };
        };
        /*
        { "success":true,
          "syncing":false,
          "blocks":-16,
          "height":2313438,
          "id":"16889110256993862505"
        }
        */
        String syncfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);

          syncResponse sync = {
            jString.valueFor("syncing"),
            jString.valueFor("blocks").toInt(),
            jString.valueFor("height").toInt(),
            jString.valueFor("id").toInt()
          };

          return sync.description();
        };
      
        /*  /api/loader/status/sync  */
        String sync(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Loader::sync_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
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
        String autoconfigurefromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::Network network = {
            jString.valueFor("nethash"),
            jString.valueFor("token"),
            jString.valueFor("symbol"),
            jString.valueFor("explorer"),
            jString.valueFor("version").toInt()
          };
          return network.description();
        };
      
        /*  /api/loader/autoconfigure  */
        String autoconfigure(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Loader::autoconfigure_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Loader::Get::autoconfigurefromJSON(callback);
        };




      };

    };
  };
};

#endif
