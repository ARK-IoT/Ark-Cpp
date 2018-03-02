

#ifndef LOADER_GETTABLE_H
#define LOADER_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Loader
{
/*************************************************
*  PROTECTED: ARK::API::Loader::Gettable
**************************************************/
class Gettable
{
  protected:
		/*************************************************
		* ARK::API::Loader::Gettable::status
		*   /api/loader/status
		**************************************************/
		ARK::API::Loader::Respondable::Status status(ARK::Utilities::Network::Connector& netConnector)
		{
			auto callback = netConnector.cb(ARK::API::Paths::Loader::status_s);
			return statusfromJSON(callback);
		}
		/*************************************************
		*
		*	{ 
		*		"success":true,
		*		"loaded": bool,
		*		"now":  int,
		*		"blocksCount":  const char*
		*	}
		*
		**************************************************/
		ARK::API::Loader::Respondable::Status statusfromJSON(const char* const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
				parser.valueFor("loaded"),
				atoi(parser.valueFor("now")),
				parser.valueFor("blocksCount")
			};
		}
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		* ARK::API::Loader::Gettable::sync
		*   /api/loader/status/sync
		**************************************************/
		ARK::API::Loader::Respondable::Sync sync(ARK::Utilities::Network::Connector& netConnector)
		{
			auto callback = netConnector.cb(ARK::API::Paths::Loader::sync_s);
			return syncfromJSON(callback);
		}
		/*************************************************
		*
		*	{ 
		*		"success":true,
		*		"syncing":  bool,
		*		"blocks": int,
		*		"height": const char*,
		*		"id": "const char*"
		*	}
		*
		**************************************************/
		ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
				parser.valueFor("syncing"),
				atoi(parser.valueFor("blocks")),
				parser.valueFor("height"),
				parser.valueFor("id")
			};
		}
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		* ARK::API::Loader::Gettable::autoconfigure
		*   /api/loader/autoconfigure
		**************************************************/
		ARK::Network autoconfigure(ARK::Utilities::Network::Connector& netConnector)
		{
			auto callback = netConnector.cb(ARK::API::Paths::Loader::autoconfigure_s);
			return autoconfigurefromJSON(callback);
		}
		/*************************************************
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
		*
		**************************************************/
		ARK::Network autoconfigurefromJSON(const char* const jsonStr)
		{
			ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
			return {
				parser.valueIn("network", "nethash"),
				parser.valueIn("network", "token"),
				parser.valueIn("network", "symbol"),
				parser.valueIn("network", "explorer"),
				atoi(parser.valueIn("network", "version"))
			};
		}
		/*************************************************/
};
/*************************************************/

};
};
};

#endif
