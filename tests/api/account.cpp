#include "gtest/gtest.h"

#include "api.h"

TEST(account, test_account) {

ARK::API::Manager arkManager(ARK::Constants::Networks::Devnet::model);

char buf[512] = {};
Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

arkManager.accountBalance(darkAddress).description(buf, sizeof(buf));
//Serial.println("balanceDescription: ");
//Serial.println(buf);
//Serial.println("\n=====\n");
//delay(50);

auto publicKeyDescription = arkManager.accountPublickey(darkAddress).description();
//Serial.println("publicKeyDescription: ");
//Serial.println(publicKeyDescription);
//Serial.println("\n=====\n");
//delay(50);

auto delegatesFeeArk = arkManager.accountDelegatesFee(darkAddress).ark();
//Serial.println("delegatesFeeArk: ");
//Serial.println(delegatesFeeArk);
//Serial.println("\n=====\n");
//delay(50);

arkManager.accountDelegates(darkAddress).description(buf, sizeof(buf));
//Serial.println("delegatesDescription: ");
//Serial.println(buf);
//Serial.println("\n=====\n");
//delay(50);

arkManager.account(darkAddress).description(buf, sizeof(buf));
//Serial.println("accountDescription: ");
//Serial.println(buf);


}
