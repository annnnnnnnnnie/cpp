#include "solution.h"

#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
  Solution sol;
  const double in[] {1,2,3};
  std::cout << std::accumulate(in, in + 0, 0) << std::endl;
  return 0;
}
