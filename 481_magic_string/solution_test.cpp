#include "solution.h"

#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <string>

TEST(TestMagicalStringGen, TestGenSome) {
    Solution sol;
    int n {10};
    auto s = sol.generateMagicalString(n);
    std::string expected {"1221121221"};
    EXPECT_EQ(s, expected);
}