#include "solution.h"

#include <algorithm>
#include <iostream>

int main() {
  Solution sol;
  std::vector<std::vector<int>> boxTypes{{1, 3}, {2, 2}, {3, 1}, {4, 4}};
  int truckSize{4};
  int result = sol.maximumUnits(boxTypes, 4);
  std::for_each(boxTypes.cbegin(), boxTypes.cend(), [](auto bt) {
    std::cout << bt.at(0) << bt.at(1) << std::endl;
  });
  return 0;
}
