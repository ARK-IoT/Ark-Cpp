

#ifndef JSON_H
#define JSON_H

<<<<<<< HEAD
#include "platform.h"

#include <memory>

namespace ARK {
namespace Utilities {

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
class JSONInterface {
protected:
	JSONInterface() { }

public:
    virtual String valueFor(const String& _key) = 0;
    virtual String valueIn(const String& _key, const String& _subkey) = 0;
    virtual String subvalueFor(const String& _key, int _pos) = 0;
    virtual String subvalueIn(const String& _key, const String& _subkey) = 0;
    virtual String subarrayValueIn(const String& _key, int _pos, const String& _subkey) = 0;
};
/*  ==========================================================================  */

// JSON object factory
std::unique_ptr<JSONInterface> make_json_string(const String& str);

}
}
=======
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
>>>>>>> master

#endif
