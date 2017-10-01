class Solution {
public:
  void sortColors(vector<int>& nums) {
    int n=nums.size();
    int i=0,j=n-1;
    auto begin=nums.begin();
    for(int k=0;k<=j;++k){
      while(nums[k]==2&&k<=j)
        iter_swap(begin+k,begin+j--);
      while(nums[k]==0&&k>=i)
        iter_swap(begin+k,begin+i++);
    }
  }
};
