
#ifndef CURRENCY_H
#define CURRENCY_H

namespace ARK {
  namespace Model {

/*************************************************/
    struct Currency {
      public:
        char ticker[8] = {'\0' }; //TODO: review sizes
        char name[32] = { '\0' };
        char symbol[4] = { '\0' };  //TODO:  single character, unicode???, multi-byte chars??? 


        Currency(const char* const t, const char* const n, const char* const s) : ticker(), name(), symbol() {
            strncpy(ticker, t, sizeof(ticker) / sizeof(ticker[0]));
            strncpy(name, n, sizeof(name) / sizeof(name[0]));
            strncpy(symbol, s, sizeof(symbol) / sizeof(symbol[0]));
        }

        void description(char* const buf, size_t /*size*/) {
			//TODO:  check len for sufficient size  
			strcpy(buf, "ticker: ");
			strcat(buf, ticker);
			strcat(buf, ", name: ");
			strcat(buf, name);
			strcat(buf, ", symbol: ");
			strcat(buf, symbol);
        };
    };
/*************************************************/


  };
};

#endif /* currency_h */
