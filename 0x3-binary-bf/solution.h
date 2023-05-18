/**
 * Definition for a binary tree node.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (!root){
      return std::vector<std::vector<int>> {{}};
    }
    std::vector<TreeNode *> currentLevel{root};
    std::vector<std::vector<int>> result;
  
    while (!currentLevel.empty()) {
      std::vector<int> vals(currentLevel.size());
      std::for_each(currentLevel.cbegin(), currentLevel.cend(), [](const auto *node) {
          assert(node);
      });
      std::transform(currentLevel.cbegin(), currentLevel.cend(), vals.begin(),
                     [](const auto *node) { return node->val; });
      result.push_back(vals);

      std::for_each(currentLevel.cbegin(), currentLevel.cend(), [](const auto *node) {
          assert(node);
      });
      std::vector<TreeNode *> nextLevel;
      for (const auto *node : currentLevel) {
        if (node->left) {
          nextLevel.push_back(node->left);
        }
        if (node->right) {
          nextLevel.push_back(node->right);
        }
      }
      currentLevel = nextLevel;
    }
    return result;
  }
};
