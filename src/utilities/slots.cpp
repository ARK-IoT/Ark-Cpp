#include "utilities/slots.h"

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
	static const date::year_month_day epoch(date::year(2017), date::month(3), date::day(21));
	date::time_of_day<
	return moment(get_constant<uint64_t>("epoch")).utc()
}

uint64_t slots::get_time(uint64_t time) {
	return get_epoch_time(time);
}

uint64_t slots::get_real_time(uint64_t epoch_time) {
	const auto start = static_cast<uint64_t>(std::floor(begin_epoch_time() / 1000)) * 1000;

	return start + epoch_time * 1000;
}

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

}
}
