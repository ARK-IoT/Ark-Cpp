#include "api/loadable/loader_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
namespace Loader
{

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
  auto callback = netConnector.cb(ARK::API::Paths::Loader::status_s);
  char buffer[75];
  strcpy(buffer, callback);
  
  Serial.print("buffer: ");
  Serial.println(buffer);

  auto parser = ARK::Utilities::make_json_string(buffer);

  return {
    parser->valueFor("loaded"),
    convert_to_int(parser->valueFor("now")),
    parser->valueFor("blocksCount")
  };
}
/*************************************************

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
  auto callback = netConnector.cb(ARK::API::Paths::Loader::sync_s);

  auto parser = ARK::Utilities::make_json_string(callback);

  return {
    parser->valueFor("syncing"),
    atoi(parser->valueFor("blocks")),
    parser->valueFor("height"),
    parser->valueFor("id")
  };
}
/*************************************************/

/**************************************************************************************************/

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
  auto callback = netConnector.cb(ARK::API::Paths::Loader::autoconfigure_s);

  auto parser = ARK::Utilities::make_json_string(callback);

  return {
    parser->valueIn("network", "nethash"),
    parser->valueIn("network", "token"),
    parser->valueIn("network", "symbol"),
    parser->valueIn("network", "explorer"),
    atoi(parser->valueIn("network", "version"))
  };
}
/*************************************************/

};
};
};
