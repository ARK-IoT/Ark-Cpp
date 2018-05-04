

#include "utilities/platform.h"
#include "utilities/json.h"
#include "ArduinoJson.h"
#include <cstring>
#include <memory>

namespace ARK
{
namespace Utilities
{

namespace
{
/**************************************************
*
**************************************************/
struct JSON :
		public JSONInterface
{
	private:
		static const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
		std::string jsonStr;

	public:
		/**************************************************
		*
		**************************************************/
		JSON(
				std::string _jsonStr
		)
		{
			jsonStr = _jsonStr;
		}
		/*************************************************/

		/**************************************************
		* valueFor(key)
		*
		* { "key1": value1, "key2": value2 }
		**************************************************/
		std::string valueFor(
				const char *const key
		) override
		{
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key].as<const char*>());
		}
		/*************************************************/

		/**************************************************
		* valueIn(key, subkey)
		*
		* { "key": { "subkey": subvalue } }
		**************************************************/
		std::string valueIn(
				const char *const key,
				const char *const subkey
		) override
		{
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][subkey].as<const char*>());
		}
		/*************************************************/

		/**************************************************
		* subvalueFor(key, position)
		*
		* { "key": { subValue1, subvalue2 } }
		**************************************************/
		std::string subvalueFor(
				const char *const key,
				int pos
		) override
		{
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][pos].as<const char*>());
		}
		/*************************************************/
		
		/**************************************************
		* subarrayValueIn(key, position, subkey)
		*
		* { "key": [ { "subkey": subvalue } ] }
		**************************************************/
		std::string subarrayValueIn(
				const char *const key,
				int pos,
				const char *const subkey
		) override
		{
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
			return std::string(root[key][pos][subkey].as<const char*>());
		}
		/*************************************************/

};

}

/**************************************************
* make_json_string
**************************************************/
std::unique_ptr<JSONInterface> make_json_string(
		std::string json_str
)
{
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};
