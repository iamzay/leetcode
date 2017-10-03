#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
      return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
      vector<int> curLevel;
      int n=q.size();
      while(n--){
        auto node=q.front();
        q.pop();
        curLevel.push_back(node->val);
        if(node->left)
          q.push(node->left);
        if(node->right)
          q.push(node->right);
      }
      res.push_back(curLevel);
    }
    return res;
  }
};

class Solution1 {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
      return res;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> curLevel;;
    while(!q.empty()){
      auto node=q.front();
      q.pop();
      if(node){
        curLevel.push_back(node->val);
        if(node->left)
          q.push(node->left);
        if(node->right)
          q.push(node->right);
      } else{
        res.push_back(curLevel);
        curLevel.resize(0);
        if(!q.empty())
          q.push(NULL);
      }
    }
    return res;
  }
};
