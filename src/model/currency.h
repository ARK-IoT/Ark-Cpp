
#ifndef CURRENCY_H
#define CURRENCY_H

namespace ARK
{
namespace Model
{

/*************************************************/
struct Currency {
  public:
    char ticker[5] = {'\0' }; //TODO: review sizes
    char name[20] = { '\0' };
    char symbol[4] = { '\0' };  //TODO:  single character, unicode???, multi-byte chars??? 

    Currency(
        const char* const newTicker,
        const char* const newName,
        const char* const newSymbol
    ) : ticker(), name(), symbol()
    {
      strncpy(ticker, newTicker, sizeof(ticker) / sizeof(ticker[0]));
      strncpy(name, newName, sizeof(name) / sizeof(name[0]));
      strncpy(symbol, newSymbol, sizeof(symbol) / sizeof(symbol[0]));
    }

};
/*************************************************/


};
};

#endif /* currency_h */
