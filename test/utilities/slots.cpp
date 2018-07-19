#include "gtest/gtest.h"

#include "utilities/platform.h"
#include "utilities/slots.h"

TEST(utilities, slots_get_time) {
	//ASSERT_EQ(10ull, ARK::Utilities::slots::get_time(1490101210000));
	// IoT does not support 64 bit in unit tests yet
#ifdef USE_IOT
	ASSERT_TRUE(ARK::Utilities::slots::get_time(1490101210000) == 10ull);
#else
	ASSERT_EQ(10ull, ARK::Utilities::slots::get_time(1490101210000));
#endif
}

TEST(utilities, slots_begin_epoch_time) {
	//ASSERT_EQ(1490101200ull, ARK::Utilities::slots::begin_epoch_time());
	// IoT does not support 64 bit in unit tests yet
#ifdef USE_IOT
	ASSERT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::milliseconds(ARK::Utilities::slots::begin_epoch_time())).count() == 1490101200ull);
#else
	ASSERT_EQ(1490101200ull, std::chrono::duration_cast<std::chrono::seconds>(std::chrono::milliseconds(ARK::Utilities::slots::begin_epoch_time())).count());
#endif
}

TEST(utilities, slots_get_real_time) {
	//ASSERT_EQ(1490101210000ull, ARK::Utilities::slots::get_real_time(10));
	// IoT does not support 64 bit in unit tests yet
#ifdef USE_IOT
	ASSERT_TRUE(ARK::Utilities::slots::get_real_time(10) == 1490101210000ull);
#else
	ASSERT_EQ(1490101210000ull, ARK::Utilities::slots::get_real_time(10));
#endif
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
