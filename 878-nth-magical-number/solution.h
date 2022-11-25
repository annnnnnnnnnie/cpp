#include <algorithm>
//#include <iterator>

class Solution {
private:
  constexpr static int modulus{static_cast<int>(1e9 + 7)};

public:
  int nthMagicalNumber(int n, int a, int b) {
    long long a_cur{a};
    long long b_cur{b};
    long long cur{std::min(a_cur, b_cur)};
    while (--n > 0) {
      // increment a b to > cur
      a_cur = a_cur <= cur ? a * (cur / a + 1) : a_cur;
      b_cur = b_cur <= cur ? b * (cur / b + 1) : b_cur;

      // set cur to min of two
      cur = std::min(a_cur, b_cur);
    }
    return cur % modulus;
  }
};