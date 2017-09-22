#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left=0,right=nums.size()-1;
    while(left<right){
      int mid=left+(right-left)/2;
      if(nums[mid]>nums[right])
        left=mid+1;
      else if(nums[mid]<nums[right])
        right=mid;
      else {
        int tmp=mid;
        while(tmp>=0&&nums[tmp]<nums[right])
          ;
        if(tmp<0)
          left=mid+1;
        else
          right=mid;
      }
    }
    return nums[left];
  }
};

int main(){
  
}
