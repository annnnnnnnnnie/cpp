#include "solution.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(TestCases, TestCase_1) { Solution sol; }

TEST(TEST_HELPER, TestCanSplitHello) {
  Solution sol;
  std::string s{"hello"};
  auto grps = sol.splitIntoGroups(s);
  std::vector<std::string> expected{"h", "e", "ll", "o"};
  EXPECT_EQ(grps.size(), expected.size())
      << "incorrect groups of word sections returned";
  EXPECT_PRED2(
      [](auto v1, auto v2) {
        for (int i = 0; i < v1.size(); i++) {
          if (v1.at(i) != v2.at(i)) {
            return false;
          }
        }
        return true;
      },
      grps, expected)
      << "unmatched results";
}