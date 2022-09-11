//recursion

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            } else {
                TreeNode *cur = root->right;
                while (cur->left) cur = cur->left;
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};

//recursion for all binary tree

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            if (!root->right) return root->left;
            else {
                TreeNode *cur = root->right;
                while (cur->left) cur = cur->left;
                swap(root->val, cur->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};

//iteration

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (!pre) return del(cur);
        if (pre->left && pre->left->val == key) pre->left = del(cur);
        else pre->right = del(cur);
        return root;
    }
    TreeNode* del(TreeNode* node) {
        if (!node) return nullptr;
        if (!node->right) return node->left;
        TreeNode *t = node->right;
        while (t->left) t = t->left;
        t->left = node->left;
        return node->right;
    }
};

//https://www.cnblogs.com/grandyang/p/6228252.html

