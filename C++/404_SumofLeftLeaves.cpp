#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return _sumOfLeftLeaves(root, false);
    }

    int _sumOfLeftLeaves(TreeNode* node, bool isLeft) {
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return isLeft ? node->val : 0;
        return _sumOfLeftLeaves(node->left, true) + _sumOfLeftLeaves(node->right, false);
    }
};