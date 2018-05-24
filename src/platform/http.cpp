

#include "utilities/platform.h"

#ifndef USE_IOT

#include "utilities/http.h"

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include <cstring>
#include <sstream>
#include <iostream>

namespace ARK
{
namespace Utilities
{
namespace Network
{

namespace
{
class HTTP :
		public HTTPInterface
{
	public: 
		HTTP() = default;

		std::string get(
				const char *const	peer,
				int								port,
				const char *const	request_str
		) override
		{
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

#endif

