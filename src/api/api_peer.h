

#ifndef api_peer_h
#define api_peer_h
    
namespace ARK {
  namespace API {
    namespace Peer {


      namespace Get {


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
        String peerfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::Peer peer = {
            jString.valueFor("ip"),
            jString.valueFor("port").toInt(),
            jString.valueFor("version"),
            jString.valueFor("errors").toInt(),
            jString.valueFor("os"),
            jString.valueFor("height").toInt(),
            jString.valueFor("status"),
            jString.valueFor("delay").toInt()
          };
          return peer.description();
        };
      
        /*  /api/delegates/fee  */
        String peer(ARK::Utilities::Network::Manager _netManager, String _ip, int _port) {
          String uri = ARK::API::Endpoints::Peer::get_s;
            uri += "?ip=";
            uri += _ip;
            uri += "&port=";
            uri += _port;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Peer::Get::peerfromJSON(callback);
        };





        /*
        { "success":true,
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
          ]
        }
        */
        // const String peers_s = "/api/peers";
        String peersfromJSON(String _jsonStr) {

          // int peerCount = ARK::API::Helpers::substringCount(_jsonStr, "ip");


          // ARK::Utilities::JSONString jString(_jsonStr);

          // ARK::Peer peer = {
          //   jString.valueFor("ip"),
          //   jString.valueFor("port").toInt(),
          //   jString.valueFor("version"),
          //   jString.valueFor("errors").toInt(),
          //   jString.valueFor("os"),
          //   jString.valueFor("height").toInt(),
          //   jString.valueFor("status"),
          //   jString.valueFor("delay").toInt()
          // };
          return _jsonStr;//peer.description();
        };
      
        /*  /api/peers  */
        String peers(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Peer::peers_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Peer::Get::peersfromJSON(callback);
        };







        /*
        {
          "success":true,
          "version":"1.1.1",
          "build":""
        }
        */
        String versionfromJSON(String _jsonStr) {
          ARK::Utilities::JSONString jString(_jsonStr);
          ARK::PeerVersion peerVersion = {
            jString.valueFor("version"),
            jString.valueFor("build")
          };
          return peerVersion.description();
        };
        /*  /api/peers/version  */
        String version(ARK::Utilities::Network::Manager _netManager) {
          String uri = ARK::API::Endpoints::Peer::version_s;
          String callback = _netManager.cb(uri);
          if (callback.indexOf("false") >= 0)
            return callback;
          return ARK::API::Peer::Get::versionfromJSON(callback);
        };





             // jString.valueFor("")
      //  ARK::Utilities::JSONString jString(_jsonStr);

      //     ARK::Delegate delegate = {
      //       jString.valueFor("username"),
      //       jString.valueFor("address"),
      //       jString.valueFor("publicKey"),
      //       jString.valueFor("vote"),
      //       jString.valueFor("producedblocks").toInt(),
      //       jString.valueFor("missedblocks").toInt(),
      //       jString.valueFor("rate").toInt(),
      //       jString.valueFor("approval").toFloat(),
      //       jString.valueFor("productivity").toFloat()
      //     };

      //     return delegate.description();
      // return jString.valueFor("publicKey");


      };
       
      namespace peer_cb {
    
        struct getPeerResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Peer peer;
        };
        
        struct getPeersResponse : virtual ARK::API::Helpers::Successable {
          public:
            ARK::Peer peers[];
        };
        
        struct versionResponse : virtual ARK::API::Helpers::Successable {
          public:
            String version;
            String build;
        };    

      };
      
        
    };
  };
};

#endif
