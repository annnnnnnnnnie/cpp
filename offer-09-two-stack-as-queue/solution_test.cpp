#include "solution.h"

#include <gtest/gtest.h>

TEST(TestCases, OneElement) {
  CQueue q;
  q.appendTail(1);
  auto r1 = q.deleteHead();
  EXPECT_EQ(r1, 1);
}

TEST(TestCases, ZeroDeque) {
  CQueue q;
  auto r1 = q.deleteHead();
  EXPECT_EQ(r1, -1);
}

TEST(TestCases, MultipleElements) {
  CQueue q;
  q.appendTail(1);
  q.deleteHead();

  q.appendTail(2);
  q.appendTail(3);

  auto r1 = q.deleteHead();
  EXPECT_EQ(r1, 2);

  auto r2 = q.deleteHead();
  EXPECT_EQ(r2, 3);
}