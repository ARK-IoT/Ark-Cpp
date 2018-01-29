
#ifndef CURRENCY_H
#define CURRENCY_H

namespace ARK {
  namespace Model {

/*  ================================================  */
    struct Currency {
      public:
        String ticker;
        String name;
        String symbol;

        Currency(String _ticker, String _name, String _symbol) {
          ticker = _ticker;
          name = _name;
          symbol = _symbol;
        };

        String description() {
          return ("ticker: " + ticker + ", " + "name: " + name + ", " + "symbol: " + symbol);
        };
    };
/*  ================================================  */


  };
};

#endif /* currency_h */
