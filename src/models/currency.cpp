

#include "models/currency.h"

namespace ARK
{
namespace Model
{
/*************************************************
*
**************************************************/
Currency::Currency(
		const char* const newTicker,
		const char* const newName,
		const char* const newSymbol
)
{
	strncpy(ticker_, newTicker, sizeof(ticker_) / sizeof(ticker_[0]));
	strncpy(name_, newName, sizeof(name_) / sizeof(name_[0]));
	strncpy(symbol_, newSymbol, sizeof(symbol_) / sizeof(symbol_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Currency::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("ticker: ");
		size += p.print(this->ticker_);

		size += p.print("\nname: ");
		size += p.print(this->name_);

		size += p.print("\nsymbol: ");
		size += p.print(this->symbol_);
	return size;
}
/*************************************************/

};
};
