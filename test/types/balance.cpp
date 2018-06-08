#include "types/balance.h"

#include "gtest/gtest.h"

TEST(types, construct_balance)
{
	Balance balance(129844030.0);
	ASSERT_EQ(129844030.0, balance.getValue());
    
	Balance balance2(1.0);
	ASSERT_EQ(1.0, balance2.getValue());
    
	Balance balance3(0.1);
	ASSERT_EQ(0.1, balance3.getValue());

	Balance balance4(0.0001);
	ASSERT_EQ(0.0001, balance4.getValue());
}
