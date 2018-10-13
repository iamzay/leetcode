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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> res;
        queue<TreeNode*> q;
        int rowMax = root->val;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if(cur == NULL) {
                res.push_back(rowMax);
                if(!q.empty()) {
                    q.push(NULL);
                    rowMax = q.front()->val;
                } 
                continue;
            }

            rowMax = max(rowMax, cur->val);
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right != NULL)
                q.push(cur->right);
        }
        return res;
    }
};