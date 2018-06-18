#include "gtest/gtest.h"

#include "models/transaction.h"

TEST(model, construct_transaction)
{
	ARK::Transaction transaction(
		"f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9",
		"14671461178414977683",
		"1696504",
		ARK::TransactionType::NORMAL,
		9656006,
		"51000",
		"10000000",
		"vendorField",
		"DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
		"D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD",
		"039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c",
		"3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b",
		"1868079"
	);
	ASSERT_STREQ("f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9", transaction.id());
	ASSERT_STREQ("14671461178414977683", transaction.block_id());
	ASSERT_STREQ("1696504", transaction.height());
	ASSERT_EQ(ARK::TransactionType::NORMAL, transaction.type());
	ASSERT_EQ(9656006, transaction.timestamp());
	ASSERT_STREQ("51000", transaction.amount().arktoshi());
	ASSERT_STREQ("10000000", transaction.fee().arktoshi());
	ASSERT_STREQ("vendorField", transaction.vendor_field());
	ASSERT_STREQ("DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR", transaction.sender_id().getValue());
	ASSERT_STREQ("D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD", transaction.recipient_id().getValue());
	ASSERT_STREQ("039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c", transaction.sender_publickey().getValue());
	ASSERT_STREQ("3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b", transaction.signature().getValue());
	ASSERT_STREQ("1868079", transaction.confirmations());
}

TEST(model, transaction_get_transaction_bytes) {
      	ARK::Transaction transaction(
		"13987348420913138422",
		"",
		"",
		ARK::TransactionType::NORMAL, 
		141738,
		std::to_string(1000).c_str(), 
		std::to_string(2000).c_str(),
		"",
		"",
		"AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff", 
		"5d036a858ce89f844491762eb89e2bfbd50a4a0a0da658e4b2628b25b117ae09",
		"618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a",
		""		
	);
	uint8_t buffer[512] = {};
	auto length = t.get_transaction_bytes(buffer);
	ASSERT_EQ(202u, length);
    });
/*
    it("should return Buffer of transaction with second signature and buffer must be 266 length", function () {
      var transaction = {
        type: 0,
        amount: 1000,
        fee: 2000,
        recipientId: "AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff",
        timestamp: 141738,
        asset: {},
        senderPublicKey: "5d036a858ce89f844491762eb89e2bfbd50a4a0a0da658e4b2628b25b117ae09",
        signature: "618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a",
        signSignature: "618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a",
        id: "13987348420913138422"
      };

      bytes = getBytes(transaction);
      (bytes).should.be.ok;
      (bytes).should.be.type("object");
      (bytes.length).should.be.equal(266);
    });
  });
	*/
}

TEST(model, transaction_get_id) {
	/*
	describe("#getId", function () {
    var getId = crypto.getId;

    it("should be ok", function () {
      (getId).should.be.ok;
    });

    it("should be a function", function () {
      (getId).should.be.type("function");
    });

    it("should return string id and be equal to 619fd7971db6f317fdee3675c862291c976d072a0a1782410e3a6f5309022491", function () {
      var transaction = {
        type: 0,
        amount: 1000,
        fee: 2000,
        recipientId: "AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff",
        timestamp: 141738,
        asset: {},
        senderPublicKey: "5d036a858ce89f844491762eb89e2bfbd50a4a0a0da658e4b2628b25b117ae09",
        signature: "618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a"
      };

      var id = getId(transaction);
      (id).should.be.type("string").and.equal("952e33b66c35a3805015657c008e73a0dee1efefd9af8c41adb59fe79745ccea");
    });
  });

	*/
}

TEST(model, transaction_get_hash) {
	/*
	describe("#getHash", function () {
    var getHash = crypto.getHash;

    it("should be ok", function () {
      (getHash).should.be.ok;
    });

    it("should be a function", function () {
      (getHash).should.be.type("function");
    })

    it("should return Buffer and Buffer most be 32 bytes length", function () {
      var transaction = {
        type: 0,
        amount: 1000,
        fee: 2000,
        recipientId: "AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff",
        timestamp: 141738,
        asset: {},
        senderPublicKey: "5d036a858ce89f844491762eb89e2bfbd50a4a0a0da658e4b2628b25b117ae09",
        signature: "618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a",
      };

      var result = getHash(transaction);
      (result).should.be.ok;
      (result).should.be.type("object");
      (result.length).should.be.equal(32);
    });
  });

  describe("#getId", function () {
    var getId = crypto.getId;

    it("should be ok", function () {
      (getId).should.be.ok;
    });

    it("should be a function", function () {
      (getId).should.be.type("function");
    });

    it("should return string id and be equal to 619fd7971db6f317fdee3675c862291c976d072a0a1782410e3a6f5309022491", function () {
      var transaction = {
        type: 0,
        amount: 1000,
        fee: 2000,
        recipientId: "AJWRd23HNEhPLkK1ymMnwnDBX2a7QBZqff",
        timestamp: 141738,
        asset: {},
        senderPublicKey: "5d036a858ce89f844491762eb89e2bfbd50a4a0a0da658e4b2628b25b117ae09",
        signature: "618a54975212ead93df8c881655c625544bce8ed7ccdfe6f08a42eecfb1adebd051307be5014bb051617baf7815d50f62129e70918190361e5d4dd4796541b0a"
      };

      var id = getId(transaction);
      (id).should.be.type("string").and.equal("952e33b66c35a3805015657c008e73a0dee1efefd9af8c41adb59fe79745ccea");
    });
  });
	*/
}
