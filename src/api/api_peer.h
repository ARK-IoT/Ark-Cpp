

#ifndef api_peer_h
#define api_peer_h
    
namespace ARK {
  namespace API {
    namespace Peer {

      namespace Get {

        /*  /api/delegates/fee  */
        String peer(ARK::Utilities::Network::Manager _netManager, String _ip, int _port);
        String peerfromJSON(String _jsonStr);


/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~10,792 bytes  */
        // /*
        // { "success":true,
        //   "peers":[
        //     {
        //       "ip":"138.68.21.196",
        //       "port":4002,
        //       "version":"1.1.1",
        //       "errors":0,
        //       "os":"linux4.4.0-93-generic",
        //       "height":2315528,
        //       "status":"OK",
        //       "delay":154
        //     },
        //     ...
        //     {
        //       "ip":"45.33.86.168",
        //       "port":4002,
        //       "version":"1.1.1",
        //       "errors":0,
        //       "os":"linux4.9.68-x86_64-linode89",
        //       "height":2315543,
        //       "status":"OK",
        //       "delay":35
        //     }
        //   ]
        // }
        // */
        // String peersfromJSON(String _jsonStr) {
        //   int peerCount = ARK::API::Helpers::substringCount(_jsonStr, "ip");
        //   ARK::Utilities::JSONString jString(_jsonStr);
        //   ARK::Peer peers[peerCount];
        //   for (int i = 0; i < peerCount; i++) {
        //     ARK::Peer peer = {
        //       jString.largeSubarrayValueIn("peers", i, "ip", 11000),
        //       jString.largeSubarrayValueIn("peers", i, "port", 11000).toInt(),
        //       jString.largeSubarrayValueIn("peers", i, "version", 11000),
        //       jString.largeSubarrayValueIn("peers", i, "errors", 11000).toInt(),
        //       jString.largeSubarrayValueIn("peers", i, "os", 11000),
        //       jString.largeSubarrayValueIn("peers", i, "height", 11000).toInt(),
        //       jString.largeSubarrayValueIn("peers", i, "status", 11000),
        //       jString.largeSubarrayValueIn("peers", i, "delay", 11000).toInt()
        //     };
        //     peers[i] = peer;
        //   };
        //   String resp;
        //   for (int i = 0; i < peerCount; i++) {
        //     resp += "\npeer "; resp += i + 1; resp += ":\n";
        //       resp += peers[i].description(); resp += "\n";
        //   };
        //   return resp;
        // };
        // /*  /api/peers  */
        // String peers(ARK::Utilities::Network::Manager _netManager) {
        //   String uri = ARK::API::Endpoints::Peer::peers_s;
        //   String callback = _netManager.cb(uri);
        //   if (callback.indexOf("true") <= 0)
        //     return callback;
        //   return ARK::API::Peer::Get::peersfromJSON(callback);
        // };


        /*  /api/peers/version  */
        String version(ARK::Utilities::Network::Manager _netManager);
        String versionfromJSON(String _jsonStr);

      };
       
    };
  };
};




/*
{ "success":true,
  "peer":{
    "ip":"167.114.29.55",
    "port":4002,
    "version":"1.1.1",
    "errors":0,
    "os":"linux4.4.0-79-generic",
    "height":2315448,
    "status":"OK",
    "delay":11
  }
}
*/
String ARK::API::Peer::Get::peerfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Peer peer = {
    jString.valueIn("peer", "ip"),
    jString.valueIn("peer", "port").toInt(),
    jString.valueIn("peer", "version"),
    jString.valueIn("peer", "errors").toInt(),
    jString.valueIn("peer", "os"),
    jString.valueIn("peer", "height").toInt(),
    jString.valueIn("peer", "status"),
    jString.valueIn("peer", "delay").toInt()
  };
  return peer.description();
}

/*  /api/delegates/fee  */
String ARK::API::Peer::Get::peer(ARK::Utilities::Network::Manager _netManager, String _ip, int _port) {
  String uri = ARK::API::Endpoints::Peer::get_s;
    uri += "?ip=";
    uri += _ip;
    uri += "&port=";
    uri += _port;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Peer::Get::peerfromJSON(callback);
}




/*
{
  "success":true,
  "version":"1.1.1",
  "build":""
}
*/
String ARK::API::Peer::Get::versionfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  ARK::Peer::Version peerVersion = {
    jString.valueFor("version"),
    jString.valueFor("build")
  };
  return peerVersion.description();
};

/*  /api/peers/version  */
String ARK::API::Peer::Get::version(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Peer::version_s;
  String callback = _netManager.cb(uri);
  if (callback.indexOf("true") <= 0)
    return callback;
  return ARK::API::Peer::Get::versionfromJSON(callback);
};


#endif
