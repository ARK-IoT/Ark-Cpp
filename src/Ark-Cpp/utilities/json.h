

#ifndef JSON_H
#define JSON_H

namespace ARK
{
namespace Utilities
{
/**************************************************
* ARK::Utilities::JSONParser
*
* 	@brief The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
struct JSONParser
		: public Bufferable
{

	private:
		int size_;

	public:

		/*************************************************
		*		ARK::Utilities::JSONParser
		*		Constructor
		*
		*   @constructor:	JSONParser(const char* const value, int size)
		*   @parameters:
		*			const char* const value
		*			int size
		*
		*   @description:
		*			Constructs JSONParser with Value and Size.
		* 
		**************************************************/
		JSONParser(
				const char* const value,
				int size
		)	: size_(size)
		{
			this->buffer = value;
		};
		/*************************************************/


		/*************************************************
		*		ARK::Utilities::JSONParser::valueFor
		*
		*   @param:	const char* key
		*
		*   @brief:	{ "key": "keyValue" }
		**************************************************/
		const char* valueFor(
				const char* key
		)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
			jsonBuffer.clear();
			return root[key];
		}
		/*************************************************/


		/*************************************************
		*		ARK::Utilities::JSONParser::valueIn
		*
		*   @param:	const char* key, const char* subkey
		*
		*   @brief:	{ "key": { "subkey": "subkeyValue" } }
		**************************************************/
		const char* valueIn(
				const char* key,
				const char* subkey
		)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
			jsonBuffer.clear();
			return root[key][subkey];
		}
		/*************************************************/


		/*************************************************
		*		ARK::Utilities::JSONParser::subvalueFor
		*
		*   @parameters:	const char* key, int pos
		*
		*   @brief:	{ "key": [ "subkeyValue" ] }
		**************************************************/
		const char* subvalueFor(
				const char* key,
				int pos
		)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
			jsonBuffer.clear();
			return root[key][pos];
		}
		/*************************************************/


		/*************************************************
		*		ARK::Utilities::JSONParser::subarrayValueIn
		*
		*   @param:	const char* key, int pos
		*
		*   @brief:	{ "key": [ { "subkey": "subkeyValue" } ] }
		**************************************************/
		const char* subarrayValueIn(
				const char* key,
				int pos,
				const char* subkey
		)
		{
			const size_t capacity = this->size_;
			DynamicJsonBuffer jsonBuffer(capacity);
			JsonObject &root = jsonBuffer.parseObject(this->buffer.get());
			jsonBuffer.clear();
			return root[key][pos][subkey];
		};
		/*************************************************/

};
/*************************************************/
  
};
};

#endif
