#include "solution.h"

#include <gtest/gtest.h>

TEST(TestCases, TestCase_1) {
  Solution sol;
  struct TreeNode fifteen(15);
  struct TreeNode seven(7);
  struct TreeNode twenty(20, &fifteen, &seven);
  struct TreeNode nine(9);
  struct TreeNode three(3, &nine, &twenty);

  auto result = sol.levelOrder(&three);
  for (auto row : result) {
    for (auto e : row) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
