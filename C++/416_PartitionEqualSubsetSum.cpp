#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum=0;
    for_each(nums.begin(),nums.end(),[&sum](const int& n){sum+=n;});
    if(sum&1)
      return false;
    sum=sum/2;
    int n=nums.size();
    // d[i][j]表示第1~i个数是否可以构成和j
    vector<vector<bool>> d(n+1,vector<bool>(sum+1,false));
    d[0][0]=true;
    for(int j=1;j<=sum;++j)
      d[0][j]=false;

    for(int i=1;i<=n;++i)
      for(int j=0;j<=sum;++j){
        d[i][j]=d[i-1][j];
        if(j>=nums[i])
          d[i][j]=d[i][j]||d[i-1][j-nums[i]];
      }
    return d[n][sum];
  }
};
