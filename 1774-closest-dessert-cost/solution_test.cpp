#include "solution.h"

#include <gtest/gtest.h>
#include <set>
#include <vector>

TEST(TestCases, TestCase_1) { Solution sol; }

TEST(TestHelper, CanFindAllToppingCosts) {
  Solution sol;
  std::vector<int> toppingCosts{2, 3};
  auto allToppingCosts = sol.allPossibleCostsFromToppings(toppingCosts);
  int expected{9}; // 0 2 3 4 6 5 7 8 10
  EXPECT_EQ(allToppingCosts.size(), expected);
}
