#include <algorithm>
#include <vector>

class Solution {
public:
  int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
    std::sort(
        boxTypes.begin(), boxTypes.end(),
        [](const auto &bt1, const auto &bt2) { return bt1.at(1) > bt2.at(1); });

    int result{0};
    for (const auto &bt : boxTypes) {
      int n{bt.at(0)};
      int v{bt.at(1)};
      if (n <= truckSize) {
        truckSize -= n;
        result += n * v;
      } else {
        result += truckSize * v;
        break;
      }
    }
    return result;
  }
};