class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 将m个元素往后移
    for(int i=m-1;i>=0;--i)
      nums1[i+n]=nums1[i];
    int cur=0,i=n,j=0;
    for(;;){
      if(i<n+m&&j<n){
        if(nums1[i]<nums2[j])
          nums1[cur++]=nums1[i++];
        else
          nums1[cur++]=nums2[j++];
      }
      else if(i<n+m)
        nums1[cur++]=nums1[i++];
      else if(j<n)
        nums1[cur++]=nums2[j++];
      else
        break;
    }
  }
};
