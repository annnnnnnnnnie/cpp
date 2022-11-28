#include <string>

class Solution {
public:
  int minOperations(std::string s) {
    return std::min(minOperationStarting(s, true), minOperationStarting(s, false));
  }
  int minOperationStarting(std::string_view s, bool start_with_zero){
    char current = start_with_zero ? '0' : '1';
    int n_operations {0};
    for(auto c : s) {
      if(c != current){
        n_operations++;
      }
      current = current == '0' ? '1' : '0';
    }
    return n_operations;
  }
};