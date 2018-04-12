
#ifndef CURRENCY_H
#define CURRENCY_H

#include "utilities/platform.h"

#include <cstddef>

namespace ARK
{
namespace Model
{
/*************************************************
*
**************************************************/
struct Currency :
    public Printable
{
  public:
    char ticker_[5] = {'\0' }; //TODO: review sizes
    char name_[20] = { '\0' };
    char symbol_[4] = { '\0' };  //TODO:  single character, unicode???, multi-byte chars??? 

		/*************************************************
		*	Constructor
		**************************************************/
    Currency(
        const char* const newTicker,
        const char* const newName,
        const char* const newSymbol
    );
    /*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const char* ticker() const noexcept { return ticker_; }
		const char* name() const noexcept { return name_; }
		const char* symbol() const noexcept { return symbol_; }
    /*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const;
		/*************************************************/

};
/*************************************************/

};
};

#endif /* currency_h */
