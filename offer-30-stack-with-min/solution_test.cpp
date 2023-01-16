#include "solution.h"

#include <gtest/gtest.h>

TEST(TestCases, CanFindMinElement) {
  MinStack s;
  s.push(1);
  s.push(2);
  auto m = s.min();
  EXPECT_EQ(m, 1);
}


