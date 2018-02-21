#include "gtest/gtest.h"

#include "api.h"

TEST(account, test_account) {

ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);

Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

const auto account_balance = arkManager.accountBalance(darkAddress);
ASSERT_STREQ("", account_balance.confirmed().ark());
ASSERT_STREQ("", account_balance.confirmed().arktoshi());
ASSERT_STREQ("", account_balance.unconfirmed().ark());
ASSERT_STREQ("", account_balance.unconfirmed().arktoshi());

ASSERT_STREQ("", arkManager.accountPublickey(darkAddress).description());

const auto delegates_fee = arkManager.accountDelegatesFee(darkAddress);
ASSERT_STREQ("", delegates_fee.ark());
ASSERT_STREQ("", delegates_fee.arktoshi());

const auto delegate = arkManager.accountDelegates(darkAddress);

ASSERT_STREQ("", delegate.username());
ASSERT_STREQ("", delegate.address().description());
ASSERT_STREQ("", delegate.public_key().description());
ASSERT_STREQ("", delegate.vote().arktoshi());
ASSERT_EQ(0, delegate.produced_blocks());
ASSERT_EQ(0, delegate.missed_blocks());
ASSERT_EQ(0, delegate.rate());
ASSERT_EQ(0, delegate.approval());
ASSERT_EQ(0, delegate.productivity());


const auto account = arkManager.account(darkAddress);
ASSERT_STREQ("", account.address().description());
ASSERT_STREQ("", account.unconfirmed_balance().arktoshi());
ASSERT_STREQ("", account.balance().arktoshi());
ASSERT_STREQ("", account.public_key().description());
ASSERT_EQ(0, account.unconfirmed_signature());
ASSERT_EQ(0, account.second_signature());
ASSERT_STREQ("", account.second_public_key().description());
ASSERT_STREQ("", account.multi_signatures().description());
ASSERT_STREQ("", account.u_multi_signatures().description());

}
