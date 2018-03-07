

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
class HTTP
{
	public: 
    
		HTTP() {};

		/*************************************************
		* ARK::Utilities::Network::HTTP::printConnection(const char*, int)
		**************************************************/
		void printConnection(
				const char* peer,
				int port
		)
		{
			Serial.print("Opening HTTP connection to ");
			Serial.print(peer);
			Serial.print(":");
			Serial.println(port);
		};
		/*************************************************/

		/*************************************************
		* ARK::Utilities::Network::HTTP::printDelay(const char*)
		**************************************************/
		void printDelay(const char* request)
		{
			delay(1000);
			Serial.print("waiting for HTTP connection to: ");
			Serial.println(request);
		}
		/*************************************************/

		/*************************************************
		* ARK::Utilities::Network::HTTP::get(const char*, int, const char*)
		**************************************************/
    const char* get(
				const char* const peer,
				int port,
				const char* const request
		)
		{
			HTTPClient http;
			http.setTimeout(2000);

			printConnection(peer, port);

			http.begin(peer, port, request);

			int httpCode = http.GET();

			while (!http.connected())
			{
				printDelay(request);
			};

				int httpSize = http.getSize();

				int payloadSize = (httpSize > 0) ? (httpSize + 1) : (55);
				char* payload = new char[payloadSize];

			if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
			{

				WiFiClient * stream = http.getStreamPtr();

				while( http.connected() && (httpSize > 0 || httpSize == -1) )
				{
					if (stream->available())
					{
						strcpy(payload, stream->readString().c_str());
					}
					delay(1);
				};
				return payload;
			}
			else
			{
				Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
				http.end();
				strcpy(payload, "Error: Connection to Peer could not be established");
			};
			return payload;
		};
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

#endif
