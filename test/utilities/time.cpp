#include "gtest/gtest.h"

#include "utilities/time.h"

TEST(utilities, get_time) {
	auto d = 1490101210000u;
	auto time = ARK::Utilities::get_time(&d);
	ASSERT_EQ(10u, time);
}
