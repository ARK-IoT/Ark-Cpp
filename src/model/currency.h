
#ifndef CURRENCY_H
#define CURRENCY_H

#include <cstddef>

namespace ARK {
  namespace Model {

/*  ================================================  */
    struct Currency {
      public:
        char ticker_[8]; //TODO: review sizes
        char name_[32];
        char symbol_[4];  //TODO:  single character, unicode???, multi-byte chars??? 


		Currency(const char* const t, const char* const n, const char* const s);

		const char* ticker() const noexcept { return ticker_; }
		const char* name() const noexcept { return name_; }
		const char* symbol() const noexcept { return symbol_; }

		void description(char* const buf, size_t /*size*/);
    };
/*  ================================================  */


  };
};

#endif /* currency_h */
