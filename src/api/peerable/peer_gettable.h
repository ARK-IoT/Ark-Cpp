

#ifndef peer_gettable_h
#define peer_gett able_h
    
namespace ARK {
  namespace API {

    /*  =================================  */
    /*  PROTECTED: ARK::API::PeerGettable  */

    class PeerGettable {
      protected:

/*  ==========================================================================  */

        /*  /api/delegates/fee  */
        ARK::Peer peer(ARK::Utilities::Network::Manager _netManager, String _ip, int _port);
        ARK::Peer peerfromJSON(String _jsonStr);

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~11,000 bytes  */
        // ARK::Peer::PeersResponse peersfromJSON(String _jsonStr);
        // ARK::Peer::PeersResponse peers(ARK::Utilities::Network::Manager _netManager);
/*  ==========================================================================  */

        /*  /api/peers/version  */
        ARK::Peer::Version version(ARK::Utilities::Network::Manager _netManager);
        ARK::Peer::Version versionfromJSON(String _jsonStr);

/*  ==========================================================================  */

    };
    /*  =================================  */

  };
};

/*  ==========================================================================  */

/*  ============================  */
/*  ARK::API::PeerGettable::peer  */

/*  /api/delegates/fee  */
ARK::Peer ARK::API::PeerGettable::peer(ARK::Utilities::Network::Manager _netManager, String _ip, int _port) {
  String uri = ARK::API::Endpoints::Peer::get_s;
    uri += "?ip=";
    uri += _ip;
    uri += "&port=";
    uri += _port;
  String callback = _netManager.cb(uri);
  return ARK::API::PeerGettable::peerfromJSON(callback);
}

/*
{ 
  "success":true,
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
ARK::Peer ARK::API::PeerGettable::peerfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueIn("peer", "ip"),
    jString.valueIn("peer", "port").toInt(),
    jString.valueIn("peer", "version"),
    jString.valueIn("peer", "errors").toInt(),
    jString.valueIn("peer", "os"),
    jString.valueIn("peer", "height"),
    jString.valueIn("peer", "status"),
    jString.valueIn("peer", "delay").toInt()
  };
}
/*  ============================  */

/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~11,000 bytes  */
/*  =============================  */
/*  ARK::API::PeerGettable::peers  */
/*  /api/peers  */
// ARK::Peer::PeersResponse ARK::API::PeerGettable::peers(ARK::Utilities::Network::Manager _netManager) {
//   String uri = ARK::API::Endpoints::Peer::peers_s;
//   String callback = _netManager.cb(uri);
//   return ARK::API::PeerGettable::peersfromJSON(callback);
// };
/*
{ 
  "success":true,
  "peers":[
    {
      "ip":"138.68.21.196",
      "port":4002,
      "version":"1.1.1",
      "errors":0,
      "os":"linux4.4.0-93-generic",
      "height":2315528,
      "status":"OK",
      "delay":154
    },
    ...
    {
      "ip":"45.33.86.168",
      "port":4002,
      "version":"1.1.1",
      "errors":0,
      "os":"linux4.9.68-x86_64-linode89",
      "height":2315543,
      "status":"OK",
      "delay":35
    }
  ],
  "count":"_count"
}
*/
// ARK::Peer::PeersResponse ARK::API::PeerGettable::peersfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   int peersCount = 10; // limited to 10
//   ARK::Peer::PeersResponse peersResponse(peersCount);
//   // for (int i = 0; i < peersCount; i++) {
//   //   ARK::Peer peer = {
//   //     jString.subarrayValueIn("peers", i, "ip"),
//   //     jString.subarrayValueIn("peers", i, "port").toInt(),
//   //     jString.subarrayValueIn("peers", i, "version"),
//   //     jString.subarrayValueIn("peers", i, "errors").toInt(),
//   //     jString.subarrayValueIn("peers", i, "os"),
//   //     jString.subarrayValueIn("peers", i, "height"),
//   //     jString.subarrayValueIn("peers", i, "status"),
//   //     jString.subarrayValueIn("peers", i, "delay").toInt()
//   //   };
//   //   peersResponse.list[i] = peer;
//   // };
//   return peersResponse;
// }
/*  =============================  */
/*  ==========================================================================  */

/*  ==========================================================================  */

/*  ===============================  */
/*  ARK::API::PeerGettable::version  */

/*  /api/peers/version  */
ARK::Peer::Version ARK::API::PeerGettable::version(ARK::Utilities::Network::Manager _netManager) {
  String uri = ARK::API::Endpoints::Peer::version_s;
  String callback = _netManager.cb(uri);
  return ARK::API::PeerGettable::versionfromJSON(callback);
};

/*
{
  "success":true,
  "version":"1.1.1",
  "build":""
}
*/
ARK::Peer::Version ARK::API::PeerGettable::versionfromJSON(String _jsonStr) {
  ARK::Utilities::JSONString jString(_jsonStr);
  return {
    jString.valueFor("version"),
    jString.valueFor("build")
  };
};
/*  ===============================  */


#endif