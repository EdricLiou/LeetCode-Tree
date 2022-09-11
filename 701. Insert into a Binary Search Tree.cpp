//recursion

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};

//iteration

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *cur = root;
        while (true) {
            if (cur->val > val) {
                if (!cur->left) {cur->left = new TreeNode(val); break;}
                cur = cur->left;
            } else {
                if (!cur->right) {cur->right = new TreeNode(val); break;}
                cur = cur->right;
            }
        }
        return root;
    }
};

//https://www.cnblogs.com/grandyang/p/9914546.html
