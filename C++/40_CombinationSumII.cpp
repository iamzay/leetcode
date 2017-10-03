#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    int n=candidates.size();
    // sum[i]为0~i-1的和
    vector<int> sum(n+1,0);
    for(int i=1;i<=candidates.size();++i)
      sum[i]=sum[i-1]+candidates[i-1];
    backtrace(candidates,res,target,tmp,0,sum);
    return res;
  }

private:
  void backtrace(vector<int>& candidates,vector<vector<int>>& res,int target,vector<int>& tmp,int begin,vector<int>& sum){
    if(!target){
      res.push_back(tmp);
      return;
    }
    int n=candidates.size();
    if(begin>=n)
      return;
    // 剪枝1:如果之后所有数相加都不能满足
    if(sum[n]-sum[begin]<target)
      return;
    int cnt=0,i=begin,value=candidates[i];
    while(i<n&&candidates[i]==value){
      ++cnt;
      ++i;
    }
    int end=begin+cnt;
    for(i=0;i<=cnt;++i){
      // 剪枝2:如果当前数超出了target
      if(target<i*value)
        return;
      for(int j=0;j<i;++j)
        tmp.push_back(value);
      backtrace(candidates,res,target-i*value,tmp,end,sum);
      for(int j=0;j<i;++j)
        tmp.pop_back();
    }
  }
};

class Solution1 {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    int n=candidates.size();
    // sum[i]为0~i-1的和
    vector<int> sum(n+1,0);
    for(int i=1;i<=candidates.size();++i)
      sum[i]=sum[i-1]+candidates[i-1];
    backtrace(candidates,res,target,tmp,0,sum);
    return res;
  }

private:
  void backtrace(vector<int>& candidates,vector<vector<int>>& res,int target,vector<int>& tmp,int begin,vector<int>& sum){
    if(!target){
      res.push_back(tmp);
      return;
    }
    int n=candidates.size();
    if(begin>=n)
      return;
    // 剪枝1:如果之后所有数相加都不能满足
    if(sum[n]-sum[begin]<target)
      return;
    for(int i=begin;i<n&&target>=candidates[i];++i){
      if(i&&candidates[i]==candidates[i-1]&&i>begin)
        continue;
      tmp.push_back(candidates[i]);
      backtrace(candidates,res,target-candidates[i],tmp,i+1,sum);
      tmp.pop_back();
    }
  }
};
