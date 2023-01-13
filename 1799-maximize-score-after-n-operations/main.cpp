#include "solution.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  Solution sol;
  // std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> nums{7, 5, 3, 4, 2, 6, 1, 8};
  std::vector<int> results;
  std::sort(nums.begin(), nums.end());
  do {
    int score = sol.findScore(nums);
    results.push_back(score);
    std::for_each(nums.cbegin(), nums.cend(),
                  [](const auto &n) { std::cout << n << ", "; });
    std::cout << std::endl;
  } while (std::next_permutation(nums.begin(), nums.end()));
  // std::cout << *std::max_element(results.cbegin(), results.cend()) << std::endl;
  return 0;
}
