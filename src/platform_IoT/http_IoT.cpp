#include "utilities/platform.h"

#if (defined ESP32 || defined ESP8266)

#include "utilities/http.h"
#include "utilities/json.h"

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
class HTTP : public HTTPInterface {
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
	) override {
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

	bool post(
		const Hash& nethash,
		const char *const peer,
		uint16_t port,
		const char *const request_str,
		const char* const data
	) override {
		HTTPClient http;
		if (!http.begin(peer, port, request_str)) {
			// error
			Serial.println("bad HTTP begin");
		}

		const auto json = std::string("{\"transactions\": [") + data + "]} ";

		http.addHeader("Content-Length", std::to_string(json.length()).c_str());
		http.addHeader("Content-Type", "application/json; charset=utf-8");
		http.addHeader("nethash", nethash.getValue());
		http.addHeader("version", "1.6.0");
		http.addHeader("port", "1");
		http.addHeader("os", "Ark-Cpp");

		const auto code = http.POST(json.c_str());
		if (code != HTTP_CODE_OK) { return false; }

		const auto s = std::string(http.getString().c_str());
		auto json_parser = ARK::Utilities::make_json_string(s);
		Serial.print("HTTP POST Response: ");
		Serial.println(s.c_str());
		if (json_parser->valueFor("success") == "true") { return true; }
		Serial.print("HTTP response error: ");
		Serial.println(json_parser->valueFor("message").c_str());
		Serial.println(json_parser->valueFor("error").c_str());
		return false;
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
