#include "solution.h"

#include <algorithm>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TestCases, Test_h_gt_N) {
  Solution sol;
  const double in[]{1, 2, 3, 4};
  double out[4];
  int N{4};
  int h{5};
  double expected = 2.5;
  sol.smooth(in, out, N, h);
  std::for_each(out, out + N,
                [=](const auto d) { EXPECT_DOUBLE_EQ(d, expected); });
}

TEST(TestCases, Test_zero_h) {
  Solution sol;
  const double in[]{1, 2, 3, 4};
  double out[4];
  int N{4};
  int h{0};
  sol.smooth(in, out, N, h);
  EXPECT_THAT(out, testing::ElementsAre(1, 2, 3, 4));
}

TEST(TestCases, Test_some_h) {
  Solution sol;
  const double in[]{1, 2, 3, 4};
  double out[4];
  int N{4};
  int h{1};
  sol.smooth(in, out, N, h);
  EXPECT_THAT(out, testing::ElementsAre(1, 2, 3, static_cast<double>(7)/3));
}