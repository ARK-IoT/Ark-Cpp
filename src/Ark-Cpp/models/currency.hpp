
#ifndef CURRENCY_HPP
#define CURRENCY_HPP

namespace ARK
{
namespace Model
{

/*************************************************/
struct Currency :
    public Printable
{
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
    };


		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
        size += p.print("ticker: ");
        size += p.print(this->ticker);

        size += p.print("\nname: ");
        size += p.print(this->name);

        size += p.print("\nsymbol: ");
        size += p.print(this->symbol);
			return size;
		}
		/*************************************************/
};
/*************************************************/

};
};

#endif /* currency_h */
