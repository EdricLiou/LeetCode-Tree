//recursion

class Solution {
public:    
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
};

//https://www.cnblogs.com/grandyang/p/4045660.html
