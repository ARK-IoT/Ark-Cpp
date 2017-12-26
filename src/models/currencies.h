
#ifndef currencies_h
#define currencies_h



typedef struct Currency {
  public:
    String ticker;
    String name;
    String symbol;
    Currency(String _ticker, String _name, String _symbol) {
      ticker = _ticker;
      name = _name;
      symbol = _symbol;
    };
    String asString() {
      return ("ticker: " + ticker + ", " + "name: " + name + ", " + "symbol: " + symbol);
    };
} currency_t;

namespace Currencies {

  namespace Cryptocurrencies {
    Currency ARK { "ARK", "Ark", "Ѧ" };
    Currency BTC { "BTC", "Bitcoin", "฿" };
  };

  namespace Fiats {
      Currency USD { "USD", "United States Dollar", "$" };
      Currency EUR { "EUR", "Euro", "€" };
      Currency GBT { "GBP", "British Pound", "£" };
   };
  
};

#endif /* currencies_h */