#include "utilities/platform.h"


#if !defined USE_IOT

namespace {

uint32_t generate_random_number_with_fresh_seed(uint32_t min, uint32_t max) {
	std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> distribution(min, max);
	return distribution(generator);
}

uint32_t generate_random_number_with_static_seed(uint32_t min, uint32_t max) {
	static std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> distribution(min, max);
	return distribution(generator);
}

}

uint32_t generate_random_number(uint32_t min, uint32_t max, bool static_seed /* = false */) {
	return static_seed ? generate_random_number_with_static_seed(min, max) : generate_random_number_with_fresh_seed(min, max);
}

#endif