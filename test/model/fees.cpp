#include "gtest/gtest.h"

#include "models/fees.h"

TEST(model, construct_fees)
{
	ARK::Fees fees(
		0.10000000,
		1.00000000,
		5.00000000,
		25.00000000,
		5.00000000
	);
	ASSERT_EQ(0.1, fees.send().getValue());
	ASSERT_EQ(1.0, fees.vote().getValue());
	ASSERT_EQ(5.0, fees.delegate().getValue());
	ASSERT_EQ(25.0, fees.second_signature().getValue());
	ASSERT_EQ(5.0, fees.multi_signature().getValue());
}
