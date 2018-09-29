#include <iostream>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double currentLevelSum = 0;    
        int currentLevelCnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1) {
            auto currentNode = q.front();
            q.pop();
            if(currentNode == NULL) {
                res.push_back(currentLevelSum / currentLevelCnt);
                currentLevelSum = 0;
                currentLevelCnt = 0;
                q.push(NULL);
                continue;
            }
            currentLevelSum += currentNode->val;
            ++currentLevelCnt;
            if(currentNode->left != NULL) {
                q.push(currentNode->left);
            }
            if(currentNode->right != NULL) {
                q.push(currentNode->right);
            }
        }
        res.push_back(currentLevelSum / currentLevelCnt);

        return res;
    }
};