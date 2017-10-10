class Solution {
public:
  int climbStairs(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int prev=1;  // i-2的走法总数
    int cur=1;  // i-1的走法总数
    for(int i=2;i<=n;++i){
      int tmp=cur;
      cur=prev+cur;
      prev=tmp;
    }
    return cur;
  }
};
