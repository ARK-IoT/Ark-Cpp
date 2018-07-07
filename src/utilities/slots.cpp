#include "utilities/platform.h"  // include platform first to pick up patched STL std::to_string functions for IoT

#include "utilities/slots.h"

#undef round	// Undef round macro so IoT compiler doesn't confuse it with date's round template function
#include "date/date.h"

#include <cmath>

namespace ARK {
namespace Utilities {

uint64_t slots::get_epoch_time(uint64_t time) {
	const auto start = begin_epoch_time();
	return static_cast<uint64_t>(std::floor((time - start) / 1000));
}

uint64_t slots::begin_epoch_time() {
	//2017-03-21T13:00:00Z
	static const date::year_month_day epoch_date(date::year(2017), date::month(3), date::day(21));
	static const date::time_of_day<std::chrono::hours> epoch_time(std::chrono::hours(13));
	static const auto epoch_days = static_cast<date::sys_days>(epoch_date).time_since_epoch();
	
	return std::chrono::duration_cast<std::chrono::milliseconds>(epoch_days).count() + std::chrono::duration_cast<std::chrono::milliseconds>(epoch_time.to_duration()).count();
}

uint64_t slots::get_time(uint64_t time) {
	return get_epoch_time(time);
}

uint64_t slots::get_real_time(uint64_t epoch_time) {
	const auto start = std::floor(begin_epoch_time() / 1000) * 1000;
	return start + epoch_time * 1000;
}
/*
uint64_t slots::get_slot_number(uint64_t epoch_time) {
	return static_cast<uint64_t>(std::floor(epoch_time / get_constant<uint64_t>("blocktime")));
}

uint64_t slots::get_slot_time(uint64_t slot) {
	return slot * get_constant<uint64_t>("blocktime");
}

uint64_t slots::get_next_slot() {
	return get_slot_number() + 1;
}

uint64_t slots::get_last_slot(uint64_t next_slot) {
	return next_slot + get_constant<uint64_t>("activeDelegates");
}

bool slots::is_forging_allowed(uint64_t epoch_time) {
	return std::floor(epoch_time / get_constant<uint64_t>("blocktime")) == std::floor((epoch_time + get_constant<uint64_t>("blocktime") / 2) / get_constant<uint64_t>("blocktime"));
}
*/
}
}
