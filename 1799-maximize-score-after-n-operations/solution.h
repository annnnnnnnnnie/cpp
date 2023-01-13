#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int maxScore(std::vector<int> &nums) {
    int currentMaxScore {0};
    std::sort(nums.begin(), nums.end());
    do {
      int score = findScore(nums);
      currentMaxScore = std::max(score, currentMaxScore);
    } while (std::next_permutation(nums.begin(), nums.end()));
    return currentMaxScore;
  }

  int findScore(const std::vector<int> &nums) {
    int score {0};
    auto n = nums.size() / 2;
    for(auto i = 0; i < n; i++) {
      auto x = nums.at(2 * i);
      auto y = nums.at(2 * i + 1);
      score += (i + 1) * std::gcd(x, y);
    }
    return score;
  }
};