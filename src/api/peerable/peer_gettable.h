

#ifndef PEER_GETTABLE_H
#define PEER_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Peer
{

/*  ==========================================================================  */
/*  ===================================  */
/*  PROTECTED: ARK::API::Peer::Gettable  */
class Gettable
{
  protected:
/*  ==========================================================================  */
    /*  /api/delegates/fee  */
    ARK::Peer peer(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _ip,
        int _port);

    ARK::Peer peerfromJSON(const char* const _jsonStr);
    ARK::Peer peerfromJSON(const String& _jsonStr) {
        return peerfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
  /*    BROKEN: fix for large callbacks  */
  /*    Peers callback is ~11,000 bytes  */
    // ARK::API::PeerGettablePeersResponse peersfromJSON(String _jsonStr);
    // ARK::API::PeerGettablePeersResponse peers(ARK::Utilities::Network::Connector _netConnector);
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
    /*  /api/peers/version  */
    ARK::API::Peer::Respondable::Version version(ARK::Utilities::Network::Connector& _netConnector);
    ARK::API::Peer::Respondable::Version versionfromJSON(const char* const _jsonStr);
    ARK::API::Peer::Respondable::Version versionfromJSON(const String& _jsonStr) {
        return versionfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ===================================  */
/*  ==========================================================================  */
};
};
};



/*  ==========================================================================  */
/*  ============================  */
/*  ARK::API::Peer::Gettable::peer  */
/*  /api/delegates/fee  */
ARK::Peer ARK::API::Peer::Gettable::peer(
    ARK::Utilities::Network::Connector& _netConnector,
    const char* const _ip,
    int _port)
{
    char uri[64] = { '\0' };  //TODO: review sizes
    strcpy(uri, ARK::API::Paths::Peer::get_s);
    strcat(uri, "?ip=");
    strcat(uri, _ip);
    strcat(uri, "&port=");
    const auto len = strlen(uri);
    sprintf(uri + len, "%d", _port);

    auto callback = _netConnector.cb(uri);

    return ARK::API::Peer::Gettable::peerfromJSON(callback);
}

/*
{ 
  "success":true,
  "peer":{
    "ip": "String",
    "port": int,
    "version":  "String",
    "errors": int,
    "os": "String",
    "height": String,
    "status": "String",
    "delay":  int
  }
}
*/
ARK::Peer ARK::API::Peer::Gettable::peerfromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {
      jString.valueIn("peer", "ip"),
      jString.valueIn("peer", "port").toInt(),
      jString.valueIn("peer", "version"),
      jString.valueIn("peer", "errors").toInt(),
      jString.valueIn("peer", "os"),
      jString.valueIn("peer", "height"),
      jString.valueIn("peer", "status"),
      jString.valueIn("peer", "delay").toInt()};
}
/*  ============================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~11,000 bytes  */
/*  =============================  */
/*  ARK::API::PeerGettable::peers  */
/*  /api/peers  */
// ARK::API::PeerGettablePeersResponse ARK::API::PeerGettable::peers(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Peer::peers_s;
//   String callback = _netConnector.cb(uri);
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
// ARK::API::PeerGettablePeersResponse ARK::API::PeerGettable::peersfromJSON(String _jsonStr) {
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




/*  ==========================================================================  */
/*  ===============================  */
/*  ARK::API::PeerGettable::version  */
/*  /api/peers/version  */
ARK::API::Peer::Respondable::Version ARK::API::Peer::Gettable::version(
    ARK::Utilities::Network::Connector& _netConnector
)
{
    auto callback = _netConnector.cb(ARK::API::Paths::Peer::version_s);

    return ARK::API::Peer::Gettable::versionfromJSON(callback);
};

/*
{
  "success":true,
  "version":  "String",
  "build":  "String"
}
*/
ARK::API::Peer::Respondable::Version ARK::API::Peer::Gettable::versionfromJSON(const char* const _jsonStr)
{
  ARK::Utilities::JSONString jString(_jsonStr);

  return {
      jString.valueFor("version"),
      jString.valueFor("build")};
};
/*  ===============================  */
/*  ==========================================================================  */

#endif