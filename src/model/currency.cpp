#include "currency.h"

#include <cstring>

namespace ARK {
namespace Model {


Currency::Currency(const char* const t, const char* const n, const char* const s) : ticker_(), name_(), symbol_() {
	strncpy(ticker_, t, sizeof(ticker_) / sizeof(ticker_[0]));
	strncpy(name_, n, sizeof(name_) / sizeof(name_[0]));
	strncpy(symbol_, s, sizeof(symbol_) / sizeof(symbol_[0]));
}

void Currency::description(char* const buf, size_t /*size*/) {
	//TODO:  check len for sufficient size  
	strcpy(buf, "ticker: ");
	strcat(buf, ticker_);
	strcat(buf, ", name: ");
	strcat(buf, name_);
	strcat(buf, ", symbol: ");
	strcat(buf, symbol_);
}

}
}