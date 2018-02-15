#include "currency.h"

#include "gtest/gtest.h"

namespace ARK {
	namespace Model {

TEST( currency, construct_currency) {
    ARK::Model::Currency currency(
        "ARK",
        "ark",
        "Ѧ"
    );

	ASSERT_STREQ("ARK", currency.ticker());
	ASSERT_STREQ("ark", currency.name());
	ASSERT_STREQ("Ѧ", currency.symbol());
}

}
}
