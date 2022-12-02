#include <cctype>
#include <set>
#include <string>

class Solution {
public:
  int secondHighest(std::string s) {
    std::set<int> seen;
    for (const char c : s) {
      if (std::isdigit(static_cast<unsigned char>(c))) {
        int i = std::stoi(std::string{c});
        seen.insert(i);
      }
    }
    auto it = seen.crbegin();
    if (it == seen.crend()) {
      return -1;
    }
    it++;
    if (it == seen.crend()) {
      return -1;
    } else {
      return *it;
    }
  }
};