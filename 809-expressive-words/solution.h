#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int expressiveWords(std::string s, std::vector<std::string> &words) {
    auto g1 = splitIntoGroups(s);
    int result =
        std::count_if(words.cbegin(), words.cend(), [this, g1](auto const &word) {
          auto g2 = splitIntoGroups(word);
          return compareGroups(g1, g2);
        });
    return result;
  }
  std::vector<std::string> splitIntoGroups(std::string_view s) {
    int start{0};
    std::vector<std::string> result;
    for (int end = start; end <= s.size(); end++) {
      if (end == s.size() || s.at(end) != s.at(start)) {
        result.emplace_back(std::string(s.substr(start, end - start)));
        start = end;
      }
    }
    return result;
  }
  bool compareGroups(std::vector<std::string> grps1,
                     std::vector<std::string> grps2) {
    if (grps1.size() != grps2.size()) {
      return false;
    }
    for (int i = 0; i < grps1.size(); i++) {
      auto grp1 = grps1.at(i);
      auto grp2 = grps2.at(i);
      auto sameCharForGroup = grp1.at(0) == grp2.at(0);
      auto groupSizeDiffOk = grp1.size() == grp2.size() ||
                             grp1.size() > grp2.size() && grp1.size() >= 3;
      if (!(sameCharForGroup && groupSizeDiffOk)) {
        return false;
      }
    }
    return true;
  }
};