#include "gtest/gtest.h"

#include "api.h"

TEST(loader, test_loader) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	const auto status = _arkManager.loaderStatus();
	ASSERT_TRUE(status.loaded());
	ASSERT_EQ(0, status.now());
	ASSERT_STREQ("", status.blocks_count());

	const auto sync = _arkManager.loaderSync();
	ASSERT_TRUE(sync.syncing());
	ASSERT_EQ(0, sync.blocks());
	ASSERT_STREQ("", sync.height());
	ASSERT_STREQ("", sync.id());

	const auto configure = _arkManager.loaderAutoconfigure();
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", configure.nethash());
	ASSERT_STREQ("DARK", configure.token());
	ASSERT_STREQ("DѦ", configure.symbol());
	ASSERT_STREQ("http://dexplorer.ark.io", configure.explorer());
	ASSERT_EQ(30, configure.version());

}
