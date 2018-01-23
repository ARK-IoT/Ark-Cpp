 
 
 #ifndef loader_h
 #define loader_h
 
 
 
 
namespace ARK {
  namespace Loader {


    /*  ============  */
    /*  ARK::Loader::Loader::StatusResponse  */
    struct StatusResponse {
      public:
        bool loaded;
        int now;
        String blocksCount;
        StatusResponse();
        StatusResponse(bool _loaded, int _now, String _blocksCount);
        String description();
    };
    /*  ============  */


    /*  ============  */
    /*  ARK::Loader::Loader::SyncResponse  */
    struct SyncResponse {
      public:
        bool syncing;
        int blocks;
        String height;
        String id;
        SyncResponse();
        SyncResponse(bool _syncing, int _blocks, String _height, String _id);
        String description();
    };
    /*  ============  */


   };
};




/*  ============  */
/*  ARK::Loader::StatusResponse  */

/*  Constructor  */
ARK::Loader::StatusResponse::StatusResponse() {
  this->loaded = false;
  this->now = 0;
  this->blocksCount = "";
};

/*  =====  */

/*  Constructor  */
ARK::Loader::StatusResponse::StatusResponse(bool _loaded, int _now, String _blocksCount) {
  this->loaded =_loaded;
  this->now = _now;
  this->blocksCount = _blocksCount;
};

/*  =====  */

/*  Description  */
String ARK::Loader::StatusResponse::StatusResponse::description() {
  String resp;
    resp += "loaded: ";
      resp += this->loaded; resp += "\n";
    resp += "now: ";
      resp += this->now; resp += "\n";
    resp += "blocksCount: ";
      resp += this->blocksCount;
  return resp;
};
/*  ============  */


/*  ================================================  */


/*  ============  */
/*  ARK::Loader::Loader::SyncResponse  */

/*  Constructor  */
ARK::Loader::SyncResponse::SyncResponse() {
  this->syncing = false;
  this->blocks = 0;
  this->height = "";
  this->id = "";
};

/*  =====  */

/*  Constructor  */
ARK::Loader::SyncResponse::SyncResponse(bool _syncing, int _blocks, String _height, String _id) {
  this->syncing = _syncing;
  this->blocks = _blocks;
  this->height = _height;
  this->id = _id;
};

/*  =====  */

/*  Description  */
String ARK::Loader::SyncResponse::description() {
  String resp;
    resp += "syncing: ";
      resp += this->syncing; resp += "\n";           
    resp += "blocks: ";
      resp += this->blocks; resp += "\n";
    resp += "height: ";
      resp += this->height; resp += "\n";
    resp += "id: ";
      resp += this->id;
  return resp;
};
/*  ============  */


#endif
