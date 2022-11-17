#include <string>
#include <stdexcept>
#include <algorithm>

class Solution {
public:
  int magicalString(int n) {
    std::string s{generateMagicalString(n)};
    return std::count_if(s.cbegin(), s.cend(), [](const char c) {return c == '1';});
  }

  
  std::string generateMagicalString(int n){
    std::string s{"12211"};
    int starting_pos{3};
    char current_token{'2'};

    while (starting_pos < n) {
      const auto &c {s.at(starting_pos)};
      switch(c){
        case '1':
        s.push_back(current_token);
        current_token = current_token == '1' ? '2' : '1';
        break;
        case '2':
        s.push_back(current_token);
        s.push_back(current_token);
        current_token = current_token == '1' ? '2' : '1';
        break;
        default:
        throw std::runtime_error("s must contain only 1 or 2"); 
        break;
      }
      starting_pos++;
    }
    return s.substr(n);
  }
};