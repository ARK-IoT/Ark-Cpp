#include "utilities/json.h"

#include "ArduinoJson.h"

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

		String jsonStr;

	public:
		/**************************************************
		*
		**************************************************/
		JSON(const char *const _jsonStr)
		{
			this->jsonStr = _jsonStr;
		}
		/*************************************************/

		/**************************************************
		* valueFor(key)
		*
		* { "key1": value1, "key2": value2 }
		**************************************************/
		const char* valueFor(const char *const _key) override {
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
			return root[_key];
		}
		/*************************************************/

		/**************************************************
		* valueIn(key, subkey)
		**************************************************/
		const char* valueIn(const char *const _key, const char *const _subkey) override {
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
			return root[_key][_subkey];
		}
		/*************************************************/

		/**************************************************
		* subvalueFor(key, position)
		*
		* { "key": { subValue1, subvalue2 } }
		**************************************************/
		const char* subvalueFor(const char *const _key, int _pos) override {
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
			return root[_key][_pos];
		}
		/*************************************************/

		/**************************************************
		* subvalueIn(key, subkey)
		**************************************************/
		const char* subvalueIn(const char *const _key, const char *const _subkey) override {
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
			JsonObject &newRoot = root[_key];
			return newRoot[_subkey];
		}
		/*************************************************/
		
		/**************************************************
		* subarrayValueIn(key, position, subkey)
		**************************************************/
		const char* subarrayValueIn(const char *const _key, int _pos, const char *const _subkey) override {
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
			// JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
			return root[_key][_pos][_subkey];
		}
		/*************************************************/

};

}

/**************************************************
* subarrayValueIn(key, position, subkey)
**************************************************/
std::unique_ptr<JSONInterface> make_json_string(const char *const json_str)
{
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};
