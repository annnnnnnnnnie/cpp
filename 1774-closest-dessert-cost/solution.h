#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
#include <vector>

class Solution {
public:
  int closestCost(std::vector<int> &baseCosts, std::vector<int> &toppingCosts,
                  int target) {
    std::set<int> allPossibleCosts;
    std::set<int> allToppingCosts = allPossibleCostsFromToppings(toppingCosts);
    for (auto bc : baseCosts) {
      for (auto tc : allToppingCosts) {
        allPossibleCosts.insert(bc + tc);
      }
    }
    auto best = std::min_element(
        allPossibleCosts.cbegin(), allPossibleCosts.cend(),
        [target](auto c, auto cbest) {
          return std::abs(c - target) == std::abs(cbest - target)
                     ? c < cbest
                     : std::abs(c - target) < std::abs(cbest - target);
        });
    return *best;
  }

  std::set<int>
  allPossibleCostsFromToppings(const std::vector<int> &toppingCosts) {
    std::set<int> result;
    std::vector<int> allToppingCosts{toppingCosts};
    allToppingCosts.insert(allToppingCosts.cend(), toppingCosts.cbegin(),
                           toppingCosts.cend());
    assert(toppingCosts.size() * 2 == allToppingCosts.size());
    for (int n = 0; n < static_cast<int>(std::pow(2, allToppingCosts.size()));
         n++) {
      int c = costOfToppingsAccordingToScheme(allToppingCosts, n);
      result.insert(c);
    }

    return result;
  }

  int costOfToppingsAccordingToScheme(const std::vector<int> &allToppingCosts,
                                      int scheme) {
    int result{0};
    for (int i{0}; i < allToppingCosts.size(); i++) {
      if (scheme & (1 << i)) {
        result += allToppingCosts.at(i);
      }
    }
    return result;
  }
};