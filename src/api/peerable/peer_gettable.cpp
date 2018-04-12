#include "api/peerable/peer_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>
#include <cstdio>

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
  char uri[64] = { '\0' };  //TODO: review sizes
    strcpy(uri, ARK::API::Paths::Peer::get_s);
    strcat(uri, "?ip=");
    strcat(uri, ip);
    strcat(uri, "&port=");
  const auto len = strlen(uri);
  sprintf(uri + len, "%d", port);

  auto callback = netConnector.cb(uri);

  auto parser = ARK::Utilities::make_json_string(callback);

  return {
    parser->valueIn("peer", "ip"),
    atoi(parser->valueIn("peer", "port")),
    parser->valueIn("peer", "version"),
    atoi(parser->valueIn("peer", "errors")),
    parser->valueIn("peer", "os"),
    parser->valueIn("peer", "height"),
    parser->valueIn("peer", "status"),
    atoi(parser->valueIn("peer", "delay"))
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
	auto callback = netConnector.cb(ARK::API::Paths::Peer::version_s);

  auto parser = ARK::Utilities::make_json_string(callback);

	return {
		parser->valueFor("version"),
		parser->valueFor("build")
	};
};
/*************************************************/

};
};
};
