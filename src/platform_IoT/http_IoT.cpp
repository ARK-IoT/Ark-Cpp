

#include "utilities/http.h"

#if defined ESP8266

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#else

#include <HttpClient.h>
typedef WiFiClient NetworkClient;

#include <EthernetClient.h>
typedef EthernetClient NetworkClient;

#endif

namespace ARK
{
namespace Utilities
{
namespace Network
{
namespace
{

/*************************************************
*
**************************************************/
class HTTP :
		public HTTPInterface
{
	public: 
		// HTTP() = default;

/**************************************************************************************************/
#ifdef ESP8266

		/*************************************************
		*	ESP8266
		**************************************************/

		HTTPClient http;

		HTTP()
		{
			http.setTimeout(2000);
		}

		void retryConnection(
				const char *const peer,
				int port,
				const char *const request,
				int &httpCode,
				int &increment
		)
		{
			Serial.print("Retrying peer connection.");
				delay(1000);
			http.end();
				Serial.print(".");
				delay(1000);
			http.begin(peer, port, request);
				Serial.println(".");
				delay(1000);
			httpCode = http.GET();
			increment = 0;
			delay(500);
		}

		const char *get(
				const char *const peer,
				int port,
				const char *const request
		) override
		{
			Serial.print("Opening HTTP connection to ");
				Serial.print(peer);
				Serial.print(":");
				Serial.print(port);
				Serial.println(request);

			http.begin(peer, port, request);

			int httpCode = http.GET();

			int increment = 0;
			while ( !http.connected() )
			{
				if (increment == 5)
				{
					retryConnection(peer, port, request, httpCode, increment);
				}
				delay(1000);
				Serial.print("waiting for HTTP connection to: ");
				Serial.println(request);
				increment++;			
			};

			int httpSize = http.getSize();

			int payloadSize = (httpSize > 0) ? (httpSize + 1) : (55);
			char *payload = new char[payloadSize];

			if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
			{
				WiFiClient *stream = http.getStreamPtr();
				while ( http.connected() && (httpSize > 0 || httpSize == -1) )
				{
					if ( stream->available() )
					{
						strcpy(payload, stream->readString().c_str());
					}
					delay(1);
				};
				return payload;
			}
			else
			{
				// Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
				http.end();
				strcpy(payload, "Error: Connection to Peer could not be established");
				strcat(payload, "\n[HTTP] GET... failed, error: %s\n");
				strcat(payload, http.errorToString(httpCode).c_str());
			};
			return payload;
		}
		/*************************************************/

#else	/**************************************************************************************************/

		HTTP() = default;

		/*************************************************
		*
		**************************************************/
		const char *get(
				const char *const peer,
				int port,
				const char *const request
		) override
		{
			NetworkClient c;
			HttpClient http(c);

			auto error = http.get(peer, port, request);

			if (error != 0) {
				// error
				String errStr = String("HTTP Error") + String(error);
				Serial.println(errStr);
				return errStr.c_str();
			}

			auto httpCode = http.responseStatusCode();

			if (httpCode > 0 /*&& httpCode == 200*/ /*&& http.connected()*/) {
				http.skipResponseHeaders();
				String response = http.readString();
				http.stop();
				return response.c_str();
			}
			else
			{
				http.stop();
				return "Error: Connection to Peer could not be established";
			}
		}
		/*************************************************/

#endif
/**************************************************************************************************/

};

}

/*************************************************
*		HTTP object factory
**************************************************/
std::unique_ptr<HTTPInterface> make_http() {
	return std::unique_ptr<HTTPInterface>(new HTTP());
}
/*************************************************/

};
};
};
