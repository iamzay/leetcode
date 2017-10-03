#include <vector>
#include <algorithm>

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    backtrace(candidates,res,target,tmp,0);
    return res;
  }

private:
  void backtrace(vector<int>& candidates,vector<vector<int>>& res,int target,vector<int>& tmp,int begin){
    if(!target){
      res.push_back(tmp);
      return;
    }
    int n=candidates.size();
    for(int i=begin;i<n&&candidates[i]<=target;++i){
      tmp.push_back(candidates[i]);
      backtrace(candidates,res,target-candidates[i],tmp,i);
      tmp.pop_back();
    }
  }
};
