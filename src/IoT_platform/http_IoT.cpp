#include "utilities/http.h"

#include <HttpClient.h>
#include <WiFiClient.h>

namespace ARK {
namespace Utilities {
namespace Network {

namespace {

class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	String get(const String& peer, int port, const String& request) override {
		WiFiClient c;
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
