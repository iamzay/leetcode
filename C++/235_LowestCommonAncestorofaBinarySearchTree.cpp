#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val >= root->val && q->val <= root->val || p->val <= root->val && q->val >= root->val) return root;
        if(p->val <= root->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p , q);
    }
};

class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val - p->val) * (root->val - q->val) > 0) {
            root = root->val > p->val ? root->left : root->right;
        }     
        return root;
    }
};