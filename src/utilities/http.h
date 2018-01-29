

#ifndef HTTP_H
#define HTTP_H


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
// #include <HttpClient.h>

namespace ARK
{
namespace Utilities
{
namespace Network
{


  class HTTPConnectable;


  class HTTP {

    public: 

      bool isReachable = false;

      HTTP(){};

     String get(String peer, int port, String request){


        HTTPClient http;

        if (this->isReachable == false)
        {
          http.setReuse(true);
          http.setTimeout(1000);
          http.begin(peer, port, request);

          this->isReachable = true;
        }
        else
        {
          http.begin(request);
        };

        int httpCode = http.GET();

        while (!http.connected())
        {
          delay(1000);
          Serial.println("waiting for HTTP connection");
        };

        this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());

        if (this->isReachable)
        {
          String streamStr = String(http.getStreamPtr()->readString());

          http.end();

          return streamStr;
        }
        else
        {
          http.end();

          // this->isConnected = false;

          return "Error: Connection to Peer could not be established";
        };

      };



    
  };





};
};
};



/*  ====================================  */
/*  ARK::Utilities::Network::Connectable  */
/*   Inheritable HTTPConnectable object   */

class ARK::Utilities::Network::HTTPConnectable
{
public:

  ARK::Utilities::Network::HTTP http;
};

/*  =====================================  */


#endif