//stack
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
class BSTIterator {
public:
  BSTIterator(TreeNode* root) : root_(root) {}
 
  int next() {
    while (root_) {
      s_.push(root_);
      root_ = root_->left;
    }
    TreeNode* t = s_.top(); s_.pop();
    root_ = t->right;
    return t->val;
  }
 
  bool hasNext() {
    return (root_ || !s_.empty());
  }
private:
  TreeNode* root_;
  stack<TreeNode*> s_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//https://zxi.mytechroad.com/blog/tree/leetcode-173-binary-search-tree-iterator/
