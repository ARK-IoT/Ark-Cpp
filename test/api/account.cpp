#include "gtest/gtest.h"

#include "api/api.h"

TEST(account, test_account) {

ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);

Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

const auto account_balance = arkManager.accountBalance(darkAddress);
ASSERT_STRNE("0.0", account_balance.confirmed().ark());
ASSERT_STRNE("0", account_balance.confirmed().arktoshi());
ASSERT_STRNE("0.0", account_balance.unconfirmed().ark());
ASSERT_STRNE("0", account_balance.unconfirmed().arktoshi());

ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", arkManager.accountPublickey(darkAddress).getValue());

const auto delegates_fee = arkManager.accountDelegatesFee(darkAddress);
ASSERT_STREQ("25.00000000", delegates_fee.ark());
ASSERT_STREQ("2500000000", delegates_fee.arktoshi());

const auto delegate = arkManager.accountDelegates(darkAddress);

ASSERT_STREQ("sleepdeficit", delegate.username());
ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().getValue());
ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().getValue());
const auto vote = delegate.vote();
ASSERT_STRNE("0.0", vote.ark());
ASSERT_STRNE("0", vote.arktoshi());
ASSERT_NE(0, delegate.produced_blocks());
ASSERT_NE(0, delegate.missed_blocks());
ASSERT_NE(0, delegate.rate());
ASSERT_NE(0.0, delegate.approval());
ASSERT_NE(0.0, delegate.productivity());


const auto account = arkManager.account(darkAddress);
ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", account.address().getValue());
auto balance = account.unconfirmed_balance();
ASSERT_STRNE("0.0", balance.ark());
ASSERT_STRNE("0", balance.arktoshi());
balance = account.balance();
ASSERT_STRNE("0.0", balance.ark());
ASSERT_STRNE("0", balance.arktoshi());
ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", account.public_key().getValue());
ASSERT_EQ(1, account.unconfirmed_signature());
ASSERT_EQ(1, account.second_signature());
ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", account.second_public_key().getValue());
ASSERT_STREQ("[]", account.multi_signatures().getValue());
ASSERT_STREQ("[]", account.u_multi_signatures().getValue());

}
