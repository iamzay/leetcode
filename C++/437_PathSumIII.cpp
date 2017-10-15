#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    _sum=sum;
    m[0]=1;
    PathSum(root,0);
    return ans;
  }
private:
  void PathSum(TreeNode* root,int preSum){
    if(!root) return;
    int target=root->val+preSum-_sum;
    if(m.find(target)!=m.end()&&m[target])
      ans+=m[target];
    int curSum=preSum+root->val;
    ++m[curSum];
    PathSum(root->left,curSum);
    PathSum(root->right,curSum);
    --m[curSum];
  }
  unordered_map<int,int> m;
  int _sum;
  int ans;
};

int main(){
  unordered_map<int,int> m;
  cout<<(++m[1])<<endl;
}
