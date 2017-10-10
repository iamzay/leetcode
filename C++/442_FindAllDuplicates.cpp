class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    int n=nums.size();
    vector<int> res;
    for(int i=0;i<n;++i){
      int m=abs(nums[i])-1;
      if(nums[m]<0)
        res.push_back(m+1);
      else
        nums[m]=-nums[m];
    }
    return res;
  }
};
