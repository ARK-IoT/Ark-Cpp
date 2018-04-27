

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
