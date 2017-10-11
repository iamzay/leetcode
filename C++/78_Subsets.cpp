class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> res;
    for(int i=0;i<(1<<n);++i){
      vector<int> subset;
      for(int j=0;j<n;++j){
        if((i>>j)&1)
          subset.push_back(nums[j]);
      }
      res.push_back(subset);
    }
    return res;
  }
};

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> tmp;
    backtrace(nums,0,nums.size(),tmp);
    return res;
  }

private:
  void backtrace(vector<int>& nums,int i,int n,vector<int>& tmp){
    if(i>=n){
      res.push_back(tmp);
      return;
    }
    tmp.push_back(nums[i]);
    backtrace(nums,i+1,n,tmp);
    tmp.pop_back();
    backtrace(nums,i+1,n,tmp);
  }

  vector<vector<int>> res;
};
