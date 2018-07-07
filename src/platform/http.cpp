

#include "utilities/platform.h"

#ifndef USE_IOT

#include "utilities/http.h"
#include "utilities/json.h"

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include <cstring>
#include <iostream>

namespace ARK
{
namespace Utilities
{
namespace Network
{

namespace
{
class HTTP : public HTTPInterface {
public: 
	HTTP() = default;

	std::string get(
		const char *const peer,
		int port,
		const char *const request_str
	) override
	{
		Poco::Net::HTTPClientSession session(Poco::Net::SocketAddress(peer, port));
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

	bool post(
		const Hash& nethash,
		const char *const peer,
		uint16_t port,
		const char *const request_str,
		const char* const data
	) override {
		Poco::Net::HTTPClientSession session(Poco::Net::SocketAddress(/*peer, port*/"104.238.173.75:4001"));
		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/peer/transactions", Poco::Net::HTTPMessage::HTTP_1_1);
		request.setContentType("application/json; charset=utf-8");
		request.add("nethash", nethash.getValue());
		request.add("version", "1.6.0");
		request.add("port", "1");
		request.add("os", "Ark-Cpp");
		request.add("Accept", "application/json, text/plain, */*");
		session.setKeepAlive(true);
		// Set the request body
		const auto json = std::string("{\"transactions\": [") + data + "]} ";
		request.setContentLength(json.length());

		// sends request, returns open stream
		try {
			auto& os = session.sendRequest(request);
			os << json;  // sends the body
			os.flush();
		}
		catch (const Poco::Exception& ex) {
			std::cout << "Exception in http::post: " << ex.displayText() << std::endl;
			return false;
		}
		Poco::Net::HTTPResponse response;
		try {
			auto& rs = session.receiveResponse(response);
			if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
			{
				std::string s(static_cast<size_t>(response.getContentLength()), '\0');
				rs.read(&s[0], response.getContentLength());
				auto json_parser = ARK::Utilities::make_json_string(s);
				if (json_parser->valueFor("success") == "true") { return true; }
				std::cout << "HTTP response error: " << json_parser->valueFor("message") << '\n' << json_parser->valueFor("error") << std::endl;
				return false;
			}
		}
		catch (const Poco::Exception& ex) {
			std::cout << "Exception in http::get: " << ex.displayText() << std::endl;
			return false;
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

#endif

