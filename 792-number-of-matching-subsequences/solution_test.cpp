#include "solution.h"

#include <gtest/gtest.h>

#include <string>

TEST(TestAuxiliary, TestCanRecognizeSubseq) {
  Solution sol;
  std::string s{"abcdefg"};
  std::string sub1{"bcdefg"};
  std::string sub2{"aceg"};
  std::string sub3{"f"};
  std::string sub4{""};
  EXPECT_TRUE(sol.isSubsequence(s, sub1));
  EXPECT_TRUE(sol.isSubsequence(s, sub2));
  EXPECT_TRUE(sol.isSubsequence(s, sub3));
  EXPECT_TRUE(sol.isSubsequence(s, sub4));
}

TEST(TestAuxiliary, TestCanFailNonSubseq) {
  Solution sol;
  std::string s{"abcdefg"};
  std::string sub1{"bbcdefg"};
  std::string sub2{"aecg"};
  std::string sub3{"gf"};
  std::string sub4{"h"};
  EXPECT_FALSE(sol.isSubsequence(s, sub1));
  EXPECT_FALSE(sol.isSubsequence(s, sub2));
  EXPECT_FALSE(sol.isSubsequence(s, sub3));
  EXPECT_FALSE(sol.isSubsequence(s, sub4));
}

TEST(TestCases, TestCase_1) {
  Solution sol;
  std::string s{"abcde"};
  std::vector<std::string> words{"a", "bb", "acd", "ace"};

  int result = sol.numMatchingSubseq(s, words);
  int expected = 3;
  EXPECT_EQ(result, expected);
}

TEST(TestCases, TestCase_2) {
  Solution sol;
  std::string s{"dsahjpjauf"};
  std::vector<std::string> words{"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};

  int result = sol.numMatchingSubseq(s, words);
  int expected = 2;
  EXPECT_EQ(result, expected);
}