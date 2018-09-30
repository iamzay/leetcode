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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }

private:
    TreeNode* _sortedArrayToBST(vector<int> &nums, int left, int right) {
        if(right <= left) return NULL;
        int mid = (left + right) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = _sortedArrayToBST(nums, left, mid);
        node->right = _sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
};