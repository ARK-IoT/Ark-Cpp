#include "utilities/platform.h"

#if (defined ESP32 || defined ESP8266)

#include "utilities/http.h"

#ifdef ESP8266

#include <ESP8266HTTPClient.h>

#else

#include <HTTPClient.h>

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
		/*************************************************
		*
		**************************************************/
		HTTP() = default;
		/*************************************************/
#if 0
		/*************************************************
		*
		**************************************************/
		bool tryConnection(
				HTTPClient &client,
				const char *const peer,
				int port,
				const char *const request
		)
		{
			client.stop();
			auto error = client.begin(peer, port, request);
			return error;
		}
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		int checkConnection(
				HTTPClient &client,
				const char *const peer,
				int port,
				const char *const request
		)
		{
			auto error = tryConnection(client, peer, port, request);
			if (error < 0)
			{
				Serial.println("Error: Connection to Peer could not be established");
				return error;
			};
			error = client.responseStatusCode();
			if (error < 0)
			{
				Serial.println("Getting response failed");
				return error;
			};
			error = client.skipResponseHeaders();
			if (error < 0)
			{
				Serial.println("Failed to skip response headers");
				return error;
			};
			return error;
		}
		/*************************************************/
#endif
		/*************************************************
		*
		**************************************************/
		std::string get(
				const char *const peer,
				int port,
				const char *const request
		)
		{
			HTTPClient http;
			http.begin(peer, port, request);
			auto code = http.GET();
			if (code != HTTP_CODE_OK) {
				//error
				Serial.println("bad GET");
			}
			auto payload = http.getString();
			return payload.c_str();
			/*auto check = checkConnection(http, peer, port, request);
			while ( check < 0 )
			{	
				check = checkConnection(http, peer, port, request);
				Serial.print("Retrying connection."); delay(200);
				Serial.print("."); delay(200);
				Serial.print(".\n"); delay(200);
			};
			std::string payload;
			while (	http.connected() || http.available() )
			{
				payload = http.readString().c_str();
			}
			http.stop();
			return payload;*/
		};
		/*************************************************/

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

#endif