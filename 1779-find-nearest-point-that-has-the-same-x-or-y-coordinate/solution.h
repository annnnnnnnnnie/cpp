#include <algorithm>
#include <cmath>

class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    auto it =
        std::min_element(points.cbegin(), points.cend(),
                         [=](const auto &point, const auto &smallest) {
                           if (!is_valid(x, y, point)) {
                             return false;
                           } else if (!is_valid(x, y, smallest)) {
                             return true;
                           } else {
                             return compare_distance(x, y, point, smallest);
                           }
                         });
    if (!is_valid(x, y, *it)) {
      return -1;
    } else {
      return std::distance(points.cbegin(), it);
    }
  }
  bool is_valid(int x, int y, const vector<int> &point) {
    return point.at(0) == x || point.at(1) == y;
  }
  bool compare_distance(int x, int y, const vector<int> &point,
                        const vector<int> &smallest) {
    int point_to_xy = std::abs(x - point.at(0)) + std::abs(y - point.at(1));
    int smallest_to_xy =
        std::abs(x - smallest.at(0)) + std::abs(y - smallest.at(1));
    return point_to_xy < smallest_to_xy;
  }
};