 
 
 #ifndef loader_h
 #define loader_h
 
 
 
 
 namespace ARK {
   
   struct Loader {
     public:
      struct StatusResponse;
      struct SyncResponse;
   };
 
};

struct ARK::Loader::Loader::StatusResponse {
  public:
    bool loaded;
    int now;
    int blocksCount;
    StatusResponse();
    StatusResponse(bool _loaded, int _now, int _blocksCount);
    String description();
};



ARK::Loader::StatusResponse::StatusResponse() {
  this->loaded = false;
  this->now = 0;
  this->blocksCount = 0;
};

ARK::Loader::StatusResponse::StatusResponse(bool _loaded, int _now, int _blocksCount) {
  this->loaded =_loaded;
  this->now = _now;
  this->blocksCount = _blocksCount;
};

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



struct ARK::Loader::Loader::SyncResponse {
  public:
    bool syncing;
    int blocks;
    int height;
    int id;
    SyncResponse();
    SyncResponse(bool _syncing, int _blocks, int _height, int _id);
    String description();
};

ARK::Loader::SyncResponse::SyncResponse() {
  this->syncing = false;
  this->blocks = 0;
  this->height = 0;
  this->id = 0;
};

ARK::Loader::SyncResponse::SyncResponse(bool _syncing, int _blocks, int _height, int _id) {
  this->syncing = _syncing;
  this->blocks = _blocks;
  this->height = _height;
  this->id = _id;
};

String ARK::Loader::SyncResponse::SyncResponse::description() {
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


#endif
