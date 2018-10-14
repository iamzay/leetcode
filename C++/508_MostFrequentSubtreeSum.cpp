#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
private:
    map<int,int> sums;

    int _sum(TreeNode* root) {
        if(root == NULL) return 0;
        int leftSum = _sum(root->left);
        int rightSum = _sum(root->right);
        auto sum = leftSum + rightSum + root->val;
        if(sums.count(sum) == 0)
            sums[sum] = 1;
        else
            ++sums[sum];
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        _sum(root);
        vector<int> res;
        int max = sums.begin()->second;
        for(auto it = sums.begin(); it != sums.end(); ++it) {
            if(it->second > max) {
                max = it->second;
                res.assign(1, it->first);
            } else if(it->second == max) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
