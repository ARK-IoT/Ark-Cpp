#include "gtest/gtest.h"

#include "utilities/slots.h"

TEST(utilities, slots_get_time) {
	ASSERT_EQ(10u, ARK::Utilities::slots::get_time(1490101210000u));
}

TEST(utilities, slots_begin_epoch_time) {
	ASSERT_EQ(1490101200u, ARK::Utilities::slots::begin_epoch_time());
}

TEST(utilities, slots_get_real_time) {
	ASSERT_EQ(1490101210000u, ARK::Utilities::slots::get_real_time(10));
}
/*
TEST(utilities, slots_get_slot_number) {
	ASSERT_EQ(1u, ARK::Utilities::slots::get_slot_number(10));
}

TEST(utilities, slots_get_slot_time) {
	ASSERT_EQ(156912u, ARK::Utilities::slots::get_slot_time(19614));
}

TEST(utilities, slots_get_last_slot) {
	ASSERT_EQ(52u, ARK::Utilities::slots::get_last_slot(1));
}
*/
