class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;++i){
      if(!i||nums[i]!=nums[i-1]){
        int left=i+1,right=n-1;
        int sum=-nums[i];
        while(left<right){
          if(nums[left]+nums[right]==sum){
            vector<int> ans;
            ans.push_back(nums[i]);
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            res.push_back(ans);
            ++left,--right;
            while(left<right&&nums[left]==nums[left-1]) ++left;
          } else if(nums[left]+nums[right]<sum)
            ++left;
          else
            --right;
        }
      }
    }
    return res;
  }
};
