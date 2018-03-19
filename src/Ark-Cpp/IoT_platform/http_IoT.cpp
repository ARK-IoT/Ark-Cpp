#include "utilities/http.h"

#include <HttpClient.h>
#include <Ethernet.h>
#include <EthernetClient.h>

namespace ARK {
namespace Utilities {
namespace Network {

namespace {

class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	String get(const String& peer, int port, const String& request) override {
		String url = peer + ":" + int_to_string(port) + "/" + request;
		HttpClient http;

		// if (this->isReachable == false)
		//  {
		//   http.setReuse(true);
		//http.setTimeout(1000);
		//Serial.println("Opening HTTP connection to " + peer + ":" + String(port));
		//http.begin(peer, port, request);
		//   this->isReachable = true;
		// }
		// else
		// {
		//   http.begin(request);
		// };
		String response;
		int httpCode = http.get(request.c_str(), &response);

		/*while (!http.connected())
		{
			delay(1000);
			Serial.println("waiting for HTTP connection for " + request);
		};*/

		//this->isReachable = (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected());

		//if (this->isReachable)
		if (httpCode > 0 && httpCode == 200 /*&& http.connected()*/)
		{
			//String streamStr = String(http.getStreamPtr()->readString());

			//http.end();

			//return streamStr;
			return response;
		}
		else
		{
			//http.end();

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
