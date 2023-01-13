#include <string>

class Solution {
public:
  int minimumLength(std::string s) {
    auto fwd = s.begin();
    auto bwd = s.end() - 1;
    auto current_c = *fwd;

    while (*bwd == current_c) {
      if (bwd == fwd) {
        return 0;
      } else {
        bwd--;
      }
    }
    while (*)
  }
};