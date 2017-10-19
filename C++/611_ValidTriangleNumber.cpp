class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int res=0,n=nums.size();
    for(int i=n-1;i>=2;--i){
      int r=i-1,l=0;
      while(l<r){
        if(nums[r]+nums[l]>nums[i]){
          res+=r-l;
          --r;
        } else ++l;
      }
    }
    return res;
  }
};
