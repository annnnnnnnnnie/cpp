#include "solution.h"

#include <gtest/gtest.h>
#include <string>

TEST(TestCases, TestCase_1) {
  Solution sol;
  std::string s {"0100"};
  int result = sol.minOperations(s);
  int expected = 1;
  EXPECT_EQ(result, expected);
}

TEST(TestCases, TestCase_2) {
  Solution sol;
  std::string s {"10"};
  int result = sol.minOperations(s);
  int expected = 0;
  EXPECT_EQ(result, expected);
}

TEST(TestCases, TestCase_3) {
  Solution sol;
  std::string s {"1111"};
  int result = sol.minOperations(s);
  int expected = 2;
  EXPECT_EQ(result, expected);
}
