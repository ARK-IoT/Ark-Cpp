#include "types/passphrase.h"

#include "gtest/gtest.h"

TEST(types, construct_passphrase) {
	Passphrase passphrase("bullet parade snow bacon mutual deposit brass floor staff list concert ask");

	ASSERT_STREQ("950981CE17DF662DBC1D25305F8597A71309FB8F7232203A0944477E2534B021", passphrase.private_key());

}
