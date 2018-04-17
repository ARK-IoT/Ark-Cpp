#include "gtest/gtest.h"

#include "models/currency.h"

namespace {

const auto ark_symbol = u8"Ѧ";

}

TEST(model, construct_currency) {
    ARK::Model::Currency currency(
        "ARK",
        "ark",
        ark_symbol
    );

	ASSERT_STREQ("ARK", currency.ticker());
	ASSERT_STREQ("ark", currency.name());
	ASSERT_STREQ(ark_symbol, currency.symbol());
}

