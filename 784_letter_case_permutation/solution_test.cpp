#include "solution.h"

#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <string>

TEST(UtilsTest, CanCountNumberOfAlphabets) {
  Solution sol;

  std::string s{"1a2b"};
  int result = sol.count_number_of_letters(s);
  int answer = 2;

  EXPECT_EQ(answer, result)
      << "1a2b should not contain " << result << " alphabets";
}

TEST(UtilsTest, CanCountNumberOfUpperCase) {
  Solution sol;

  std::string s{"1a2b3C4D"};
  int result = sol.count_number_of_letters(s);
  int answer = 4;

  EXPECT_EQ(answer, result)
      << "1a2b3C4D should not contain " << result << " alphabets";
}

TEST(UtilsTest, CanCountZero) {
  Solution sol;

  std::string s{"1234"};
  int result = sol.count_number_of_letters(s);
  int answer = 0;

  EXPECT_EQ(answer, result)
      << "1234 should not contain " << result << " alphabets";
}

TEST(CountTest, CorrectNumberOfItemsInResultAllDigits) {
  Solution sol;

  std::string s{"1234"};
  auto result{sol.letterCasePermutation(s)};
  int n_items = result.size();
  int answer = 1;
  EXPECT_EQ(n_items, answer)
      << "no of permutation of" << s << " should not be " << n_items;
}

TEST(CountTest, CorrectNumberOfItemsInResultAllAlpha) {
  Solution sol;

  std::string s{"abcd"};
  auto result{sol.letterCasePermutation(s)};
  int n_items = result.size();
  int answer = static_cast<int>(std::pow(2, 4));
  EXPECT_EQ(n_items, answer)
      << "no of permutation of " << s << " should not be " << n_items;
}

TEST(CountTest, CorrectNumberOfItemsInResultMixed) {
  Solution sol;

  std::string s{"1a2b"};
  auto result{sol.letterCasePermutation(s)};
  int n_items = result.size();
  int answer = static_cast<int>(std::pow(2, 2));
  EXPECT_EQ(n_items, answer)
      << "no of permutation of " << s << " should not be " << n_items;
}

TEST(CountTest, CorrectNumberOfItemsInResultUpperLowerMixed) {
  Solution sol;

  std::string s{"1a2B"};
  auto result{sol.letterCasePermutation(s)};
  int n_items = result.size();
  int answer = static_cast<int>(std::pow(2, 2));
  EXPECT_EQ(n_items, answer)
      << "no of permutation of " << s << " should not be " << n_items;
}

bool s_in_ss(std::string s, std::vector<std::string> ss) {
  return std::find(ss.cbegin(), ss.cend(), s) != ss.cend();
}

TEST(ItemTest, ExpectedItemsInResultUpperLowerMixed) {
  Solution sol;

  std::string s{"1a2B"};
  auto result{sol.letterCasePermutation(s)};
  
  std::string i1{"1a2b"};
  std::string i2{"1a2B"};
  std::string i3{"1A2b"};
  std::string i4{"1A2B"};
  std::vector<std::string> expected_items{i1, i2, i3, i4};
  EXPECT_PRED1(
      [&](std::vector<std::string> result) {
        return std::all_of(
            expected_items.cbegin(), expected_items.cend(),
            [result](auto item) { return s_in_ss(item, result); });
      },
      result);
}