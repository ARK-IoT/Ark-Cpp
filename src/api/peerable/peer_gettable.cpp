

#include "api/peerable/peer_gettable.h"

namespace ARK
{
namespace API
{
namespace Peer
{
/*************************************************
* ARK::API::Peer::Gettable::peer
* /api/peers/get?ip=167.114.29.55&port=4002
*
*	{ 
*		"success":true,
*		"peer":
*		{
*			"ip": "String",
*			"port": int,
*			"version":  "String",
*			"errors": int,
*			"os": "String",
*			"height": String,
*			"status": "String",
*			"delay":  int
*		}
*	}
**************************************************/
ARK::Peer ARK::API::Peer::Gettable::peer(
		ARK::Utilities::Network::Connector& netConnector,
		const char* const ip,
		int port
)
{
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Peer::get_s);
		strcat(uri, "?ip=");
		strcat(uri, ip);
		strcat(uri, "&port=");
	const auto len = strlen(uri);
		sprintf(uri + len, "%d", port);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueIn("peer", "ip").c_str(),
		convert_to_int(parser->valueIn("peer", "port").c_str()),
		parser->valueIn("peer", "version").c_str(),
		convert_to_int(parser->valueIn("peer", "errors").c_str()),
		parser->valueIn("peer", "os").c_str(),
		parser->valueIn("peer", "height").c_str(),
		parser->valueIn("peer", "status").c_str(),
		convert_to_int(parser->valueIn("peer", "delay").c_str())
	};
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::PeerGettable::version
* /api/peers/version
*
*	{
*		"success":true,
*		"version":  "String",
*		"build":  "String"
*	}
**************************************************/
ARK::API::Peer::Respondable::Version ARK::API::Peer::Gettable::version(
		ARK::Utilities::Network::Connector& netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Peer::version_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("version").c_str(),
		parser->valueFor("build").c_str()
	};
};
/*************************************************/

};
};
};
