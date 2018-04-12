

#ifndef JSON_H
#define JSON_H

#include "platform.h"
#include <memory>

namespace ARK
{
namespace Utilities
{
/**************************************************
* ARK::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
*	entry point for integrating and simplifying
*	integration of a JSON library
**************************************************/
class JSONInterface
{
	protected:
		JSONInterface() { }

	public:
			virtual ~JSONInterface() { }

			virtual const char* valueFor(const char *const _key) = 0;
			virtual const char* valueIn(const char *const _key, const char *const _subkey) = 0;
			virtual const char* subvalueFor(const char *const _key, int _pos) = 0;
			virtual const char* subvalueIn(const char *const _key, const char *const _subkey) = 0;
			virtual const char* subarrayValueIn(const char *const _key, int _pos, const char *const _subkey) = 0;
};
/*************************************************/

/**************************************************************************************************/

/**************************************************
*	JSON object factory
**************************************************/
std::unique_ptr<JSONInterface> make_json_string(const char *const str);
/*************************************************/

};
};

#endif
