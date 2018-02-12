

#ifndef HTTP_H
#define HTTP_H


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace ARK
{
namespace Utilities
{
namespace Network
{

/*************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
  class HTTPConnectable;
/*************************************************/



/*************************************************
* ARK::Utilities::Network::HTTP 
*   Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*   entry point for integrating the HTTPClient
*   library for different boards/chipsets
**************************************************/
  class HTTP {
    public: 
     // bool isReachable = false;

      HTTP(){};

     const char* get(const char* peer, int port, const char* request);
  };
/*************************************************/


};
};
};



/*************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
public:

  ARK::Utilities::Network::HTTP http;
};
/*************************************************/





/*************************************************
* ARK::Utilities::Network::HTTP 
**************************************************/
const char* ARK::Utilities::Network::HTTP::get(const char* peer, int port, const char* request)
{

  HTTPClient http;
  http.setTimeout(1000);

    Serial.print("Opening HTTP connection to ");
    Serial.print(peer);
    Serial.print(":");
    Serial.print(port);
    Serial.println();

  http.begin(peer, port, request);

  int httpCode = http.GET();

  while (!http.connected())
  {
    delay(1000);

      Serial.print("waiting for HTTP connection for ");
      Serial.print(request);
      Serial.println();
  };

  if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
  {
    const char* streamStr = http.getStreamPtr()->readString().c_str();
    
    http.end();

    return streamStr;
  }
  else
  {
    http.end();

    return "Error: Connection to Peer could not be established";
  };

};
/*************************************************/


#endif