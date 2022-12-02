#include "solution.h"

#include <gtest/gtest.h>
#include <string>

TEST(TestCases, ZeroToNine) {
  Solution sol;
  std::string s {"1234567890"};
  int result = sol.secondHighest(s);
  int expected = 8;
  EXPECT_EQ(expected, result);
}

TEST(TestCases, DuplicateNumber) {
  Solution sol;
  std::string s {"11223344556677889900"};
  int result = sol.secondHighest(s);
  int expected = 8;
  EXPECT_EQ(expected, result);
}

TEST(TestCases, OnlyOneDigit) {
  Solution sol;
  std::string s {"1111111111111"};
  int result = sol.secondHighest(s);
  int expected = -1;
  EXPECT_EQ(expected, result);
}

TEST(TestCases, DigitsAndChars) {
  Solution sol;
  std::string s {"1a2b3c4d4d3c2b1a"};
  int result = sol.secondHighest(s);
  int expected = 3;
  EXPECT_EQ(expected, result);
}