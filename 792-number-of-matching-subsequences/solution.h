#include <algorithm>
#include <string>

class Solution {
public:
  int numMatchingSubseq(std::string s, std::vector<std::string> &words) {
    // Maybe use a trie as a cache to store all words results.
    return std::count_if(
        words.cbegin(), words.cend(),
        [s, this](auto const word) { return isSubsequence(s, word); });
  }

  bool isSubsequence(std::string_view const s, std::string_view const sub) {
    if (sub.empty()) {
      return true;
    }
    if (s.empty()) {
      return sub.empty();
    } else {
      if (s.at(0) == sub.at(0)) {
        return isSubsequence(s.substr(1), sub.substr(1));
      } else {
        return isSubsequence(s.substr(1), sub);
      }
    }
  }
};