

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

/**************************************************************************************************/

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

/**************************************************************************************************/

/*************************************************
* ARK::Utilities::Network::HTTP 
*
**************************************************/
const char* ARK::Utilities::Network::HTTP::get(const char* peer, int port, const char* request)
{
  HTTPClient http;
  http.setTimeout(2000);
    Serial.print("Opening HTTP connection to ");
    Serial.print(peer);
    Serial.print(":");
    Serial.print(port);
    Serial.print("\n");

  http.begin(peer, port, request);

  int httpCode = http.GET();

  while (!http.connected())
  {
    delay(1000);
      Serial.print("waiting for HTTP connection to: ");
      Serial.print(request);
      Serial.print("\n");
  };

  if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
  {
    int len = http.getSize();
    char* payload = new char[len + 1];

    WiFiClient * stream = http.getStreamPtr();

    while(http.connected() && (len > 0 || len == -1))
    {
      if(stream->available())
      {
        const char* temp = stream->readString().c_str();

        for (int i = 0; i <= len; i++)
        {
          payload[i] = (i != len) ? (temp[i]) : ('\0');
        };
      }
      delay(1);
    }
    return payload;
  }
  else
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
    http.end();
    return "Error: Connection to Peer could not be established";
  };

};
/*************************************************/


#endif