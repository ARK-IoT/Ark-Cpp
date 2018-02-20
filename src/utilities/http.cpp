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
		std::cout << "Opening HTTP connection to " << peer << ":" << port << "with request" << std::endl << '\t' << request_str << std::endl;
		Poco::Net::HTTPClientSession session(peer, port);
		std::cout << "HTTPClientSession done" << std::endl;
		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, request_str, Poco::Net::HTTPMessage::HTTP_1_1);
		std::cout << "HTTPRequest done" << std::endl;
		Poco::Net::HTTPResponse response;

		session.sendRequest(request);
		std::cout << "HTTPRequest sent" << std::endl;
		auto& rs = session.receiveResponse(response);
		std::cout << "HTTPResponse: " << response.getStatus() << " " << response.getReason() << std::endl;
		if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
		{
			
			std::ostringstream ofs;
			Poco::StreamCopier::copyStream(rs, ofs);
			return ofs.str();
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
