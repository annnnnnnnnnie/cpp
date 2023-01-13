#include "solution.h"

#include <gtest/gtest.h>
#include <vector>

TEST(TestCases, ConsistencyCheck) {
  Solution sol;
  std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> other_nums {7, 5, 3, 4, 2, 6, 1, 8};
  int result = sol.maxScore(nums);
  int other_result = sol.maxScore(other_nums);
  EXPECT_EQ(result, other_result);
}

TEST(TestCases, TestCase_1) {
  Solution sol;
  std::vector<int> nums {1, 2};
  int result = sol.maxScore(nums);
  int expected = 1;
  EXPECT_EQ(result, expected);
}

TEST(TestCases, TestCase_2) {
  Solution sol;
  std::vector<int> nums {3, 4, 6, 8};
  int result = sol.maxScore(nums);
  int expected = 11;
  EXPECT_EQ(result, expected);
}

TEST(TestCases, TestCase_3) {
  Solution sol;
  std::vector<int> nums {1, 2, 3, 4, 5, 6};
  int result = sol.maxScore(nums);
  int expected = 14;
  EXPECT_EQ(result, expected);
}