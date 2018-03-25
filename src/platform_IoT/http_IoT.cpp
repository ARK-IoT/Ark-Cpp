#include "utilities/http.h"

#include <HttpClient.h>

#if (defined ESP8266 || defined ESP32)

#include <WiFiClient.h>

typedef WiFiClient NetworkClient;

#else

#include <EthernetClient.h>

typedef EthernetClient NetworkClient;

#endif

namespace ARK {
namespace Utilities {
namespace Network {

namespace {

class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	String get(const String& peer, int port, const String& request) override {
		NetworkClient c;
		HttpClient http(c);

		auto error = http.get(peer.c_str(), port, request.c_str());

		if (error != 0) {
			// error
			String errStr = String("HTTP Error") + String(error);
			Serial.println(errStr);
			return errStr;
		}
		auto httpCode = http.responseStatusCode();

		if (httpCode > 0 /*&& httpCode == 200*/ /*&& http.connected()*/) {
			http.skipResponseHeaders();
			String response = http.readString();
			http.stop();
			return response;
		}
		else
		{
			http.stop();
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
