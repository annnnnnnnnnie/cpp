#include "solution.h"

#include <gtest/gtest.h>
#include <vector>

TEST(TestCases, TestCase_1) {
  Solution sol;
  std::vector<std::vector<int>> boxTypes{{1, 3}, {2, 2}, {3, 1}};
  int truckSize{4};
  int result = sol.maximumUnits(boxTypes, 4);

  int expected = 8;
  EXPECT_EQ(result, expected);
}
