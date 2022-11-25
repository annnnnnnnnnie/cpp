#include "solution.h"

#include <gtest/gtest.h>

TEST(TestCases, TestCase_1) {
  Solution sol;
  int n{1};
  int a{2};
  int b{3};
  int result = sol.nthMagicalNumber(n, a, b);
  int expected = 2;
  EXPECT_EQ(expected, result);
}

TEST(TestCases, TestCase_2) {
  Solution sol;
  int n{4};
  int a{2};
  int b{3};
  int result = sol.nthMagicalNumber(n, a, b);
  int expected = 6;
  EXPECT_EQ(expected, result);
}
