

// #include "utilities/platform.h"
#include "utilities/http.h"
#include <HttpClient.h>

#if (defined ESP8266 || defined ESP32)

#include <WiFiClient.h>

typedef WiFiClient NetworkClient;

#else

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
		/*************************************************
		*
		**************************************************/
		HTTP() = default;
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		int tryConnection(
				HttpClient &client,
				const char *const peer,
				int port,
				const char *const request
		)
		{
			client.stop();
			auto error = client.get(peer, port, request);
			return error;
		}
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		int checkConnection(
				HttpClient &client,
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

		/*************************************************
		*
		**************************************************/
		std::string get(
				const char *const peer,
				int port,
				const char *const request
		)
		{
			NetworkClient c;
			HttpClient http(c);
			auto check = checkConnection(http, peer, port, request);
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
			return payload;
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
