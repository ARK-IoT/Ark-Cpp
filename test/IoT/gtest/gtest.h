#ifndef __GTEST_H__
#define __GTEST_H__

#include <AUnit.h>

#define TEST(category, name) test(category##__##name)

#define ASSERT_EQ assertEqual
#define ASSERT_NE assertNotEqual
#define ASSERT_STREQ assertEqual
#define ASSERT_STRNE assertNotEqual
#define ASSERT_TRUE(x) assertNotEqual(static_cast<unsigned>(x), 0u)
#define ASSERT_FALSE(x) assertEqual(static_cast<unsigned>(x), 0u)

#endif
