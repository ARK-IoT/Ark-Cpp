#include "gtest/gtest.h"

#include "models/currency.h"

TEST(model, construct_currency) {
	static const auto ark_symbol = u8"Ѧ";

    ARK::Model::Currency currency(
        "ARK",
        "ark",
        ark_symbol
    );

	ASSERT_STREQ("ARK", currency.ticker());
	ASSERT_STREQ("ark", currency.name());
	ASSERT_STREQ(ark_symbol, currency.symbol());
}

