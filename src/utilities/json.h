

#ifndef JSON_H
#define JSON_H

#include "platform.h"

namespace ARK
{
namespace Utilities
{

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONString 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
  struct JSONString
  {

    private:
      String jsonStr;

    public:
      JSONString(const String& _jsonStr);
      String valueFor(const String& _key);
      String valueIn(const String& _key, const String& _subkey);
      String subvalueFor(const String& _key, int _pos);
      String subvalueIn(const String& _key, const String& _subkey);
      String subarrayValueIn(const String& _key, int _pos, const String& _subkey);
  };
/*  ==========================================================================  */


};
};

#endif
