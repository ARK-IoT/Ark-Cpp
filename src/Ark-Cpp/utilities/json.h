

#ifndef JSON_H
#define JSON_H

#include "../../../include/include.h"
#include "../helpers/helpers.h"

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
class JSONParser
		: public Bufferable
{
private:
	int size_;

public:
	JSONParser(const char *const value, int size);

	const char *valueFor(const char *key);
	const char *valueIn(const char *key, const char *subkey);
	const char *subvalueFor(const char *key, int pos);
	const char *subarrayValueIn(const char *key, int pos, const char *subkey);

};
/*************************************************/

};
};

#endif
