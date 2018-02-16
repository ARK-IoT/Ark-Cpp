

#ifndef JSON_H
#define JSON_H

namespace ARK
{
namespace Utilities
{

/**************************************************
* ARK::Utilities::JSONParser
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
struct JSONParser
{
	#define PARSER_SIZE 2048

	private:

		int size_;
		const char *value_ = new char[PARSER_SIZE];

	public:

		JSONParser(const char* const value, int size) {
			this->size_ =  size;
			this->value_ = new char[size];
			this->value_ = value;
		};

		~JSONParser() {
			delete [] value_;
		};

		const char* valueIn(const char* key, const char* subkey)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->value_);
			jsonBuffer.clear();
			return root[key][subkey];
		}

		const char* valueFor(const char* key)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->value_);
			jsonBuffer.clear();
			return root[key];
		}

		const char* subvalueIn(const char* key, const char* subkey)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->value_);
			jsonBuffer.clear();
			JsonObject &newRoot = root[key];
			return newRoot[subkey];
		}

		const char* subarrayValueIn(const char* key, int pos, const char* subkey)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->value_);
			jsonBuffer.clear();
			return root[key][pos][subkey];
		}

		const char* subvalueFor(const char* key, int pos)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->value_);
			jsonBuffer.clear();
			return root[key][pos];
		}

  };
  
  
};
};

#endif

// /**************************************************
// * ARK::Utilities::JSONString 
// *
// * The purpose of this class is to serve as an
// *   entry point for integrating and simplifying
// *   integration of a JSON library
// **************************************************/
//   struct JSONString
//   {

//     private:
//       String jsonStr;

//     public:
//       JSONString(const String& _jsonStr);
//       String valueFor(const String& _key);
//       String valueIn(const String& _key, const String& _subkey);
//       String subvalueFor(const String& _key, int _pos);
//       String subvalueIn(const String& _key, const String& _subkey);
//       String subarrayValueIn(const String& _key, int _pos, const String& _subkey);
//   };
// ARK::Utilities::JSONString::JSONString(const String& _jsonStr)
// {
//   this->jsonStr = _jsonStr;
// };
// String ARK::Utilities::JSONString::valueFor(const String& _key)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
//   return root[_key];
// }
// String ARK::Utilities::JSONString::valueIn(const String& _key, const String& _subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
//   return root[_key][_subkey];
// }
// String ARK::Utilities::JSONString::subvalueFor(const String& _key, int _pos)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
//   return root[_key][_pos];
// }
// String ARK::Utilities::JSONString::subvalueIn(const String& _key, const String& _subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
//   JsonObject &newRoot = root[_key];
//   return newRoot[_subkey];
// }
// String ARK::Utilities::JSONString::subarrayValueIn(const String& _key, int _pos, const String& _subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
//   // JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
//   return root[_key][_pos][_subkey];
// }