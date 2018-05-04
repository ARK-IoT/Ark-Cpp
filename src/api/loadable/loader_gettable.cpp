

#include "api/loadable/loader_gettable.h"

namespace ARK
{
namespace API
{
namespace Loader
{
/*************************************************
* ARK::API::Loader::Gettable::autoconfigure
* /api/loader/autoconfigure
*
*	{
*		"success":true,
*		"network":
*		{
*			"nethash":  "Hash",
*			"token":  "const char*",
*			"symbol": "const char*,
*			"explorer": "const char*",
*			"version":  int
*		}
*	}
**************************************************/
ARK::Network ARK::API::Loader::Gettable::autoconfigure(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Loader::autoconfigure_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueIn("network", "nethash").c_str(),
		parser->valueIn("network", "token").c_str(),
		parser->valueIn("network", "symbol").c_str(),
		parser->valueIn("network", "explorer").c_str(),
		convert_to_int(parser->valueIn("network", "version").c_str())
	};
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Loader::Gettable::status
*	/api/loader/status
*
*	{ 
*		"success":true,
*		"loaded": bool,
*		"now":  int,
*		"blocksCount":  const char*
*	}
**************************************************/
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::status(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Loader::status_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("loaded") != "false",
		convert_to_int(parser->valueFor("now")),
		convert_to_int(parser->valueFor("blocksCount").c_str())
	};
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Loader::Gettable::sync
* /api/loader/status/sync
*
*	{ 
*		"success":true,
*		"syncing":  bool,
*		"blocks": int,
*		"height": const char*,
*		"id": "const char*"
*	}
**************************************************/
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::sync(
		ARK::Utilities::Network::Connector &netConnector
)
{
	auto callback = netConnector.callback(ARK::API::Paths::Loader::sync_s);
	auto parser = ARK::Utilities::make_json_string(callback);
	return {
		parser->valueFor("syncing") != "false",
		convert_to_int(parser->valueFor("blocks")),
		parser->valueFor("height").c_str(),
		parser->valueFor("id").c_str()
	};
}
/*************************************************/

};
};
};
