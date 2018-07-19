

#ifndef JSON_H
#define JSON_H

#include "utilities/platform.h"
#include <cstring>
#include <memory>

namespace ARK
{

class Transaction;

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
		/**************************************************
		*	Constructor
		**************************************************/
		JSONInterface() { }
		/*************************************************/

	public:
		/**************************************************
		*	Deconstructor
		**************************************************/
		virtual ~JSONInterface() { }
		/*************************************************/

		/**************************************************
		*	valueFor
		**************************************************/
		virtual std::string valueFor(
				const char *const key
		) = 0;
		/*************************************************/

		/**************************************************
		*	valueIn
		**************************************************/
		virtual std::string valueIn(
				const char *const key,
				const char *const subkey
		) = 0;
		/*************************************************/

		/**************************************************
		*	subvalueFor
		**************************************************/
		virtual std::string subvalueFor(
				const char *const key,
				int pos
		) = 0;
		/*************************************************/

		/**************************************************
		*	subarrayValueIn
		**************************************************/
		virtual std::string subarrayValueIn(
				const char *const key,
				int pos,
				const char *const subkey
		) = 0;
		/*************************************************/

		virtual std::string transactionToJson(const ARK::Transaction& transaction) = 0;
};
/*************************************************/

/**************************************************************************************************/

/**************************************************
*	JSON object factory
**************************************************/
std::unique_ptr<JSONInterface> make_json_string(std::string str = std::string());
/*************************************************/

};
};

#endif
