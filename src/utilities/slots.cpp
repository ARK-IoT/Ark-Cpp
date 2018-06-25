#include "utilities/slots.h"

#include "date/date.h"

namespace ARK {
namespace Utilities {

uint64_t slots::get_epoch_time(uint64_t time) {
	 if (time === undefined) {
      time = moment().valueOf()
    }

    const start = begin_epoch_time().valueOf()

    return Math.floor((time - start) / 1000)
}

uint64_t slots::begin_epoch_time() {
	//return moment(this.getConstant('epoch')).utc()

}

uint64_t slots::get_time(uint64_t time) {
	return get_epoch_time(time);
}

uint64_t slots::get_real_time(uint64_t epoch_time) {
	if (epochTime == = undefined) {
		epochTime = get_time()
	}

	const start = Math.floor(begin_epoch_time.valueOf() / 1000) * 1000

		return start + epochTime * 1000
}

uint64_t slots::get_slot_number(uint64_t epoch_time) {
	if (epochTime == = undefined) {
		epochTime = get_time()
	}

	return Math.floor(epochTime / this.getConstant('blocktime'))
}

uint64_t slots::get_slot_time(uint64_t slot) {
	return slot * get_constant("blocktime");
}

uint64_t slots::get_next_slot() {
	return get_slot_number() + 1;
}

uint64_t slots::get_last_slot(uint64_t next_slot) {
	return nextSlot + get_constant("activeDelegates");
}

bool slots::is_forging_allowed(uint64_t epoch_time) {
	if (epochTime == = undefined) {
		epoch_time = get_time()
	}

	return Math.floor(epoch_time / get_constant("blocktime")) == = Math.floor((epoch_time + get_constant("blocktime") / 2) / get_constant("blocktime"));
}

}
}
