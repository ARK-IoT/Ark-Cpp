#ifndef __GTEST_H__
#define __GTEST_H__

#include <AUnit.h>

#include <string>

inline bool isEqual_CaseInsensitive(const std::string& a, const std::string& b) {
	return 
		a.size() == b.size() && 
		std::equal(a.begin(), a.end(), b.begin(), [] (char cA, char cB) {
			return toupper(cA) == toupper(cB);
		}
	);
}

template <typename T>
inline bool isEqual_CaseInsensitive(const T* const a, const T* const b) {
	return isEqual_CaseInsensitive(std::basic_string<T>(a), std::basic_string<T>(b));
}

#define TEST(category, name) test(category##__##name)

#define ASSERT_EQ(e, a) assertEqual(static_cast<decltype(a)>(e), a)
#define ASSERT_NE(e, a) assertNotEqual(static_cast<decltype(a)>(e), a)
#define ASSERT_STREQ(e, a) assertEqual(static_cast<decltype(a)>(e), a)
#define ASSERT_STRNE(e, a) assertNotEqual(static_cast<decltype(a)>(e), a)
#define ASSERT_STRCASEEQ(e, a) assertEqual(isEqual_CaseInsensitive(e, a), true)
#define ASSERT_STRCASENE(e, a) assertNotEqual(isEqual_CaseInsensitive(e, a), true)

#define ASSERT_TRUE(x) assertNotEqual(static_cast<unsigned>(x), 0u)
#define ASSERT_FALSE(x) assertEqual(static_cast<unsigned>(x), 0u)

#endif
