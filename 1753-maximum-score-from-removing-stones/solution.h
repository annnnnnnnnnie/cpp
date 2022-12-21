#include <algorithm>

class Solution {
public:
  int maximumScore(int a, int b, int c) {
    int biggest{std::max({a, b, c})};
    if (a + b + c - biggest <= biggest) {
      return a + b + c - biggest;
    } else {
      return (a + b + c) / 2;
    }
  }
};