<<<<<<< HEAD
#include "http.h"

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"

#include <string>
#include <sstream>
#include <iostream>

namespace ARK {
namespace Utilities {
namespace Network {

namespace {

class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	std::string get(const std::string& peer, int port, const std::string& request_str) override {
		std::ostringstream ss;
		ss << peer << ":" << port;
		Poco::Net::HTTPClientSession session(Poco::Net::SocketAddress(ss.str()));
		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, request_str, Poco::Net::HTTPMessage::HTTP_1_1);
		Poco::Net::HTTPResponse response;
		try {
		session.sendRequest(request);
		auto& rs = session.receiveResponse(response);
		if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
		{
			
			std::ostringstream ofs;
			Poco::StreamCopier::copyStream(rs, ofs);
			return ofs.str();
		}
		} catch (const Poco::Exception& ex) {
			std::cout << "Exception in http::get: " << ex.displayText() << std::endl;
			throw;
		}
		throw std::runtime_error("Error: Connection to Peer could not be established");
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
=======


#include "http.h"

/*************************************************
* ARK::Utilities::Network::HTTP::HTTP()
**************************************************/
ARK::Utilities::Network::HTTP::HTTP(){};
/*************************************************/

/*************************************************
* ARK::Utilities::Network::HTTP::printConnection(const char*, int)
**************************************************/
void ARK::Utilities::Network::HTTP::printConnection(
    const char *peer,
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
void ARK::Utilities::Network::HTTP::printDelay(const char *request)
{
  delay(1000);
  Serial.print("waiting for HTTP connection to: ");
  Serial.println(request);
}
/*************************************************/

/*************************************************
* ARK::Utilities::Network::HTTP::get(const char*, int, const char*)
**************************************************/
const char *ARK::Utilities::Network::HTTP::get(
    const char *const peer,
    int port,
    const char *const request
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
  char *payload = new char[payloadSize];

  if (httpCode > 0 && httpCode == HTTP_CODE_OK && http.connected())
  {

    WiFiClient *stream = http.getStreamPtr();

    while (http.connected() && (httpSize > 0 || httpSize == -1))
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
>>>>>>> master
