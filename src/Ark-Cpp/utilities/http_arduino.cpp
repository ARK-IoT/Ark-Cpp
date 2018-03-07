#include "http.h"

//#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace ARK {
namespace Utilities {
namespace Network {

namespace {

class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	String get(const String& peer, int port, const String& request) override {
		HTTPClient http;

		// if (this->isReachable == false)
		//  {
		//   http.setReuse(true);
		http.setTimeout(1000);
		Serial.println("Opening HTTP connection to " + peer + ":" + String(port));
		http.begin(peer, port, request);
		//   this->isReachable = true;
		// }
		// else
		// {
		//   http.begin(request);
		// };

		int httpCode = http.GET();

		while (!http.connected())
		{
			delay(1000);
			Serial.println("waiting for HTTP connection for " + request);
		};

		//this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());

		//if (this->isReachable)
		if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
		{
			String streamStr = String(http.getStreamPtr()->readString());

			http.end();

			return streamStr;
		}
		else
		{
			http.end();

			return "Error: Connection to Peer could not be established";
		}
	}
};

}

// HTTP object factory
std::unique_ptr<HTTPInterface> make_http() {
	return std::unique_ptr<HTTPInterface>(new HTTP());
}

}
}
}
