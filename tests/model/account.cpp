#include "account.h"

#include "gtest/gtest.h"

TEST(account, construct_account) {
    ARK::Account account(
        "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
        "100000000",//Balance("100000000"),
        "100000000", //Balance("100000000"),
        "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", //Publickey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"),
        0,
        0,
        "", //Publickey(),
        "", //Signature(),
        "" //Signature()
    );

	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", account.address().description());
	ASSERT_STREQ("100000000", account.unconfirmed_balance().arktoshi());
	ASSERT_STREQ("100000000", account.balance().arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", account.public_key().description());
	ASSERT_EQ(0, account.unconfirmed_signature());
	ASSERT_EQ(0, account.second_signature());
	ASSERT_STREQ("", account.second_public_key().description());
	ASSERT_STREQ("", account.multi_signatures().description());
	ASSERT_STREQ("", account.u_multi_signatures().description());
}