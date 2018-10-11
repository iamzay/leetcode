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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N < 1) return vector<TreeNode*>(1, NULL);
        if(N == 1) return vector<TreeNode*>(1, new TreeNode(0));
        vector<TreeNode*> res;
        for(int k = 1; k < N - 1; k += 2) {
            auto leftRes = allPossibleFBT(k);
            auto rightRes = allPossibleFBT(N - 1 - k);
            for(auto left:leftRes) {
                for(auto right:rightRes) {
                    auto root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};