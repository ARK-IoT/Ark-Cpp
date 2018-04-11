#include "types/passphrase.h"

#include "gtest/gtest.h"

TEST(types, construct_passphrase) {
	Passphrase passphrase("bullet parade snow bacon mutual deposit brass floor staff list concert ask");

	ASSERT_TRUE(std::strncmp("950981ce17df662dbc1d25305f8597a71309fb8f7232203a0944477e2534b021", passphrase.private_key(), 64) == 0);

}
