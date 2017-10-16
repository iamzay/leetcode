class Solution {
public:
  int numTrees(int n) {
    vector<int> d(n+1,0);
    d[1]=1,d[0]=1;
    for(int i=2;i<=n;++i)
      for(int j=1;j<=i;++j){
        d[i]+=d[j-1]*d[i-j];
      }
    return d[n];
  }
};
