

#ifndef CURRENCIES_H
#define CURRENCIES_H

namespace ARK
{
namespace Constants
{
namespace Currencies
{

  namespace Crypto
  {
    ARK::Model::Currency ARK { "ARK", "Ark", "Ѧ" };
    ARK::Model::Currency BTC { "BTC", "Bitcoin", "฿" };
  };

  namespace Fiat
  {
    ARK::Model::Currency USD { "USD", "United States Dollar", "$" };
    ARK::Model::Currency EUR { "EUR", "Euro", "€" };
    ARK::Model::Currency GBT { "GBP", "British Pound", "£" };
  };

};
};
};

#endif
