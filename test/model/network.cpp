#include "gtest/gtest.h"

#include "models/network.h"

TEST(model, construct_network) {
    ARK::Network network(
        "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
        "DARK",
        u8"DѦ",
        "http://dexplorer.ark.io",
        30
    );

	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", network.nethash());
	ASSERT_STREQ("DARK", network.token());
	ASSERT_STREQ(u8"DѦ", network.symbol());
	ASSERT_STREQ("http://dexplorer.ark.io", network.explorer());
	ASSERT_EQ(30, network.version());
}