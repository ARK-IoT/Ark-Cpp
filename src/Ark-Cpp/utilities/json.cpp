<<<<<<< HEAD
#include "json.h"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include <string>

namespace ARK
{
namespace Utilities
{

namespace {

struct JSON : public JSONInterface
{

private:
	json _json;

public:
	JSON(const std::string& jsonStr) : _json(json::parse(jsonStr)) {
	}

	/**************************************************
	* valueFor(key)
	*
	* { "key1": value1, "key2": value2 }
	**************************************************/
	String valueFor(const String& key) override {
		return get_value(_json[key]);
	}

	/**************************************************
	* valueIn(key, subkey)
	**************************************************/
	String valueIn(const String& key, const String& subkey) override {
		return get_value(_json[key][subkey]);
	}

	/**************************************************
	* subvalueFor(key, position)
	*
	* { "key": { subValue1, subvalue2 } }
	**************************************************/
	String subvalueFor(const String& key, int pos) override {
		return get_value(_json[key][pos]);
	}

	/**************************************************
	* subvalueIn(key, subkey)
	**************************************************/
	String subvalueIn(const String& key, const String& subkey) override {
		const json new_root(_json[key]);
		return get_value(new_root[subkey]);
	}
	
	/**************************************************
	* subarrayValueIn(key, position, subkey)
	**************************************************/
	String subarrayValueIn(const String& key, int pos, const String& subkey) override {
		return get_value(_json[key][pos][subkey]);
	}

private:
	std::string get_value(const json& j) const {
		if (j.is_string()) {
			return j.get<std::string>();
		}
		std::ostringstream ss;
		ss << j;
		return ss.str();
	}
};

}

std::unique_ptr<JSONInterface> make_json_string(const String& json_str) {
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}

/*  ==========================================================================  */
/*  ==========================================================================  */
// /**************************************************
// * ARK::Utilities::JSONChar 
// *
// * The purpose of this class is to serve as an
// *   entry point for integrating and simplifying
// *   integration of a JSON library
// **************************************************/
// struct JSONChar
// {
//   private:
//     char *jsonChars;
//   public:
//     JSONChar(const char *_jsonChars);
//     const char *subvalueIn(const char *_key, const char *_subkey);
//     const char *subarrayValueIn(const char *_key, int _pos, const char *_subkey);
// };
// ARK::Utilities::JSONChar::JSONChar(const char *_jsonChars)
// {
//   strcpy(this->jsonChars, _jsonChars);
// };
// const char *ARK::Utilities::JSONChar::subvalueIn(const char *key, const char *subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   jsonBuffer.clear();
//   JsonObject &newRoot = root[key];
//   return newRoot[subkey];
// }
// const char *ARK::Utilities::JSONChar::subarrayValueIn(const char *_key, int _pos, const char *_subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   jsonBuffer.clear();
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   // JsonArray& root = jsonBuffer.parseArray(this->jsonChars);
//   return root[_key][_pos][_subkey];
// }
/*  ==========================================================================  */
/*  ==========================================================================  */

}
}
=======


#include "json.h"

/*************************************************
*		ARK::Utilities::JSONParser
*   @constructor:	JSONParser(const char* const value, int size)
*   @param:	const char* const value, int size
*   @brief: Constructs JSONParser with Value and Size.
**************************************************/
ARK::Utilities::JSONParser::JSONParser(
    const char *const value,
    int size
) : size_(size)
{
  this->buffer = value;
};
/*************************************************/

/*************************************************
*		ARK::Utilities::JSONParser::valueFor
*   @param:	const char* key
*   @brief:	{ "key": "keyValue" }
**************************************************/
const char *ARK::Utilities::JSONParser::valueFor(
    const char *key
)
{
  const size_t capacity = this->size_;
  ArduinoJson::DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
  jsonBuffer.clear();
  return root[key];
};
/*************************************************/

/*************************************************
*		ARK::Utilities::JSONParser::valueIn
*   @param:	const char* key, const char* subkey
*   @brief:	{ "key": { "subkey": "subkeyValue" } }
**************************************************/
const char *ARK::Utilities::JSONParser::valueIn(
    const char *key,
    const char *subkey
)
{
  const size_t capacity = this->size_;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
  jsonBuffer.clear();
  return root[key][subkey];
};
/*************************************************/

/*************************************************
*		ARK::Utilities::JSONParser::subvalueFor
*   @parameters:	const char* key, int pos
*   @brief:	{ "key": [ "subkeyValue" ] }
**************************************************/
const char *ARK::Utilities::JSONParser::subvalueFor(
    const char *key,
    int pos
)
{
  const size_t capacity = this->size_;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
  jsonBuffer.clear();
  return root[key][pos];
};
/*************************************************/

/*************************************************
*		ARK::Utilities::JSONParser::subarrayValueIn
*   @param:	const char* key, int pos
*   @brief:	{ "key": [ { "subkey": "subkeyValue" } ] }
**************************************************/
const char *ARK::Utilities::JSONParser::subarrayValueIn(
    const char *key,
    int pos,
    const char *subkey
)
{
  const size_t capacity = this->size_;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
  jsonBuffer.clear();
  return root[key][pos][subkey];
};
/*************************************************/
>>>>>>> master
