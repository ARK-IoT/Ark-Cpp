

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

		/*************************************************
		*		ARK::Utilities::JSONParser
		*		Constructor
		**************************************************/
		JSONParser( const char* const value, int size );
		/*************************************************/

		/*************************************************
		*		ARK::Utilities::JSONParser
		*		Deconstructor
		**************************************************/
		~JSONParser();
		/*************************************************/

/**************************************************************************************************/

		/*************************************************
		*			{ "key": "keyValue" }
		**************************************************/
		const char* valueFor( const char* key );
		/*************************************************/

		/*************************************************
		*		{ "key": { "subkey": "subkeyValue" } }
		**************************************************/
		const char* valueIn( const char* key, const char* subkey );
		/*************************************************/

		/*************************************************
		*		{ "key": [ "subkeyValue" ] }
		**************************************************/
		const char* subvalueFor( const char* key, int pos );
		/*************************************************/

		/*************************************************
		*		{ "key": [ { "subkey": "subkeyValue" } ] }
		**************************************************/
		const char* subarrayValueIn( const char* key, int pos, const char* subkey );
		/*************************************************/

};
/*************************************************/
  

};
};


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
ARK::Utilities::JSONParser::JSONParser(
		const char* const value,
		int size
) {
	this->size_ =  size;
	this->value_ = value;
};
/*************************************************/

/*************************************************
*		ARK::Utilities::JSONParser
*		Deconstructor
*
*   @description:
*			Deconstructs JSONParser/Deletes `value_` array.
* 
**************************************************/
ARK::Utilities::JSONParser::~JSONParser()
{
	delete [] value_;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::Utilities::JSONParser::valueFor
*
*   @parameters:
*			const char* key
*
*   @description:
*			{ "key": "keyValue" }
* 
**************************************************/
const char* ARK::Utilities::JSONParser::valueFor(
	const char* key
) {
	const size_t capacity = this->size_;
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject &root = jsonBuffer.parseObject(this->value_);
	jsonBuffer.clear();
	return root[key];
}
/*************************************************/


/*************************************************
*		ARK::Utilities::JSONParser::valueIn
*
*   @parameters:
*			const char* key
*			const char* subkey
*
*   @description:
*			{ "key": { "subkey": "subkeyValue" } }
* 
**************************************************/
const char* ARK::Utilities::JSONParser::valueIn(
		const char* key,
		const char* subkey
) {
	const size_t capacity = this->size_;
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject &root = jsonBuffer.parseObject(this->value_);
	jsonBuffer.clear();
	return root[key][subkey];
}
/*************************************************/


/*************************************************
*		ARK::Utilities::JSONParser::subvalueFor
*
*   @parameters:
*			const char* key
*			int pos
*
*   @description:
*			{ "key": [ "subkeyValue" ] }
* 
**************************************************/
const char* ARK::Utilities::JSONParser::subvalueFor(
		const char* key,
		int pos
) {
	const size_t capacity = this->size_;
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject &root = jsonBuffer.parseObject(this->value_);
	jsonBuffer.clear();
	return root[key][pos];
}
/*************************************************/


/*************************************************
*		ARK::Utilities::JSONParser::subarrayValueIn
*
*   @parameters:
*			const char* key
*			int pos
*
*   @description:
*			{ "key": [ { "subkey": "subkeyValue" } ] }
* 
**************************************************/
const char* ARK::Utilities::JSONParser::subarrayValueIn(
		const char* key,
		int pos,
		const char* subkey
) {
	const size_t capacity = this->size_;
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject &root = jsonBuffer.parseObject(this->value_);
	jsonBuffer.clear();
	return root[key][pos][subkey];
}
/*************************************************/


#endif
