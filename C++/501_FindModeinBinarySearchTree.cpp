#include <iostream>
#include <algorithm>
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
    vector<int> findMode(TreeNode* root) {
        return _findMode(root).first;
    }

private:
    pair<vector<int>,int> _findMode(TreeNode* root) {
        if(root == NULL) return make_pair(vector<int>(), 0);
        auto modePair1 = _findMode(root->left);
        auto modePair2 = _findMode(root->right);
        auto val = root->val;
        // 合并结果
        auto res = make_pair(vector<int>(), 0);
        auto v1 = modePair1.first;
        auto v2 = modePair2.first;
        for(auto mode:v1) {
            int cnt = modePair1.second;
            // 如果在右子树中也有，update cnt
            auto it = find(v2.begin(), v2.end(), mode);
            if(it != v2.end()) cnt += modePair2.second;
            if(mode == val) cnt += 1;
            if(cnt == res.second) res.first.push_back(mode);
            else if(cnt > res.second) {
                res.second = cnt;
                res.first = vector<int>(1, mode);
            }
        }
        for(auto mode:v2) {
            if(find(v1.begin(), v1.end(), mode) != v1.end()) continue;
            int cnt = modePair2.second;
            if(cnt == val) ++cnt;
            if(cnt == res.second) res.first.push_back(mode);
            else if(cnt > res.second) {
                res.second = cnt;
                res.first = vector<int>(1, mode);
            }
        }
        if(find(v1.begin(), v1.end(), val) != v1.end() ||
           find(v2.begin(), v2.end(), val) != v2.end())
            return res;
        // 如果val在左右子树中都未处理过，则单独处理
        if(res.second == 1) res.first.push_back(val);
        else if(res.second == 0) res = make_pair(vector<int>(1, val), 1);
        return res;
    }
};
