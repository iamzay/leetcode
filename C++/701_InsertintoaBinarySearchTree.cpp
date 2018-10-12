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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        if(root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

class Solution1 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        auto cur = root;
        for(;;) {
            if(cur->val > val) {
                if(cur->left == NULL) {
                    cur->left = new TreeNode(val);
                    break;
                } else {
                    cur = cur->left;
                }
            } else if (cur->val < val) {
                if(cur->right == NULL) {
                    cur->right = new TreeNode(val);
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};