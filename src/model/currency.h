
#ifndef CURRENCY_H
#define CURRENCY_H

namespace ARK {
  namespace Model {

/*  ================================================  */
    struct Currency {
      public:
        char ticker[8] = {'\0' }; //TODO: review sizes
        char name[32] = { '\0' };
        char symbol[4] = { '\0' };  //TODO:  single character, unicode???, multi-byte chars??? 

        void description(char* const buf, size_t size) {
			//TODO:  check len for sufficient size  
			strcpy(buf, "ticker: ");
			strcat(buf, ticker);
			strcpy(buf, ", name: ");
			strcat(buf, name);
			strcpy(buf, ", symbol: ");
			strcat(buf, symbol);
        };
    };
/*  ================================================  */


  };
};

#endif /* currency_h */
