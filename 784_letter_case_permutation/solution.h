#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCasePermutation(std::string s) {
    std::vector<std::string> result;

    int n_letters = count_number_of_letters(s);
    for (int i{static_cast<int>(std::pow(2, n_letters)) - 1}; i >= 0; i--) {
      std::string word;
      int j{i};
      for (const auto &c : s) {
        if (std::isalpha(c)) {
          if (j & 1) {
            word.push_back(std::toupper(c));
          } else {
            word.push_back(std::tolower(c));
          }
          j >>= 1;
        } else {
          assert(std::isdigit(c));
          word.push_back(c);
        }
      }
      result.push_back(word);
    }
    return result;
  }

  /**
   * Count the number of letters in the string s
   */
  int count_number_of_letters(std::string s) {
    return std::count_if(s.cbegin(), s.cend(),
                         [](char c) { return std::isalpha(c); });
  }
};