#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        auto left = pruneTree(root->left);
        auto right = pruneTree(root->right);
        if(left == NULL && right == NULL && !root->val) return NULL;
        root->left = left;
        root->right = right;
        return root;
    }
};