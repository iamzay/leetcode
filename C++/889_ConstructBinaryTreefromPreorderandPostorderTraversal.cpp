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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty()) return NULL;
        if(pre.size() == 1) return new TreeNode(pre[0]);
        auto root = new TreeNode(pre[0]);
        auto leftBranchRootVal = pre[1];
        int i = 0;
        for(; i < post.size() && leftBranchRootVal != post[i]; ++i)
            ;
        auto leftBranchLen = i + 1;
        vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + leftBranchLen);
        vector<int> rightPre(pre.begin() + 1 + leftBranchLen, pre.end());
        vector<int> leftPost(post.begin(), post.begin() + leftBranchLen);
        vector<int> rightPost(post.begin() + leftBranchLen, post.end() - 1);
        root->left = constructFromPrePost(leftPre, leftPost);
        root->right = constructFromPrePost(rightPre, rightPost);
        return root;
    }
};

class Solution {
private:
    vector<int> preorder;
    vector<int> postorder;

    TreeNode* _constructFromPrePost(int preBegin, int postBegin, int len) {
        if(len == 0) return NULL;
        if(len == 1) return new TreeNode(preorder[preBegin]);
        auto root = new TreeNode(preorder[preBegin]);
        auto i = postBegin;
        auto leftBranchRootVal = preorder[preBegin + 1];
        for(; i < postBegin + len && postorder[i] != leftBranchRootVal; ++ i)
            ; 
        auto leftLen = i - postBegin + 1;
        auto rightLen = len - 1 - leftLen;
        root->left = _constructFromPrePost(preBegin + 1, postBegin, leftLen);
        root->right = _constructFromPrePost(preBegin + 1 + leftLen, postBegin + leftLen, rightLen);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        preorder = pre;
        postorder = post;
        return _constructFromPrePost(0, 0, pre.size());
    }
};