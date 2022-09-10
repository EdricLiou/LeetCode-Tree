/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool _isValidBST(TreeNode *node, TreeNode *max_node, TreeNode *min_node) {
      if (!node)
        return true;
      if (max_node && node->val >= max_node->val)
        return false;
      if (min_node && node->val <= min_node->val)
        return false;
      return _isValidBST(node->left, node, min_node) &&
             _isValidBST(node->right, max_node, node);
    }
    bool isValidBST(TreeNode* root) {
      return _isValidBST(root, nullptr, nullptr);
    }
};
//https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FBkgKmiIdO
