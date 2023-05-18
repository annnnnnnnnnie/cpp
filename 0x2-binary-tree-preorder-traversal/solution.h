/**
 * Definition for a binary tree node.
 */
struct TreeNode;
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

#include <vector>
class Solution {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    if (!root) {
      return std::vector<int>{};
    } else {
      auto v = root->val;
      std::vector<int> result{v};
      auto left = preorderTraversal(root->left);
      auto right = preorderTraversal(root->right);
      result.insert(result.end(), left.begin(), left.end());
      result.insert(result.end(), right.begin(), right.end());
      return result;
    }
  }
};