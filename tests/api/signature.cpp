#include "gtest/gtest.h"

#include "api.h"

TEST(signature, test_signature) {
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Devnet::model);

	Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

	/*  ==================================  */
	const auto signatures_fee = _arkManager.signaturesFee();
	ASSERT_STREQ("", signatures_fee.ark());
	ASSERT_STREQ("", signatures_fee.arktoshi());


	/*  ==================================  */
	ASSERT_STREQ("", _arkManager.multisignaturesPending(darkPubkey).c_str());

	/*  ==================================  */
	/*  ==================================  */
	/*  Only on Mainnet?  */
	//  String multisignaturesAccounts = _arkManager.multisignaturesAccounts(darkHash);
	//    Serial.println("multisignaturesAccounts: ");
	//    Serial.println(multisignaturesAccounts);
	//    Serial.println("\n=====\n");
	//    delay(50);
	/*  ==================================  */
	/*  ==================================  */

}
