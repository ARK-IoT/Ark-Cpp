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
			if (!http.begin(peer, port, request)) {
				// error
				Serial.println("bad HTTP begin");
			}
			auto code = http.GET();
			if (code != HTTP_CODE_OK) {
				//error
				Serial.println("bad HTTP GET");
			}
			
			const auto content_length = http.getSize();
			// get tcp stream
			auto stream = http.getStreamPtr();
			auto bytes_read = 0;
			std::string payload(content_length, '\0');
			// read all data from server
			while (http.connected() && (content_length > 0 || content_length == -1) && bytes_read < content_length) {
				// get available data size
				auto size = stream->available();
				if (size) {
					// read up to 128 byte
					bytes_read += stream->readBytes(&payload[0], size);			
				}
				delay(1);
			}
			return payload;
		}
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

}
}
}

#endif
