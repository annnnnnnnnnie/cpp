#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
  std::vector<int> minOperations(std::string boxes) {
    std::vector<int> result(boxes.size());
    for(int i = 0; i < boxes.size(); i++){
      auto c = boxes.at(i);
      if(c == '1'){
        addForBox(result, i);
      }
    }
    return result;
  }

  void addForBox(std::vector<int> &operations, int boxIndex){
    for(int i = 0; i < operations.size(); i++){
      int n = std::abs(i - boxIndex);
      operations.at(i) += n;
    }
  }
};