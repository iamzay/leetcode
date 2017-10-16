class Solution {
public:
  int uniquePaths(int m, int n) {
    // d[i][j]表示从(i,j)到(m-1,n-1)的方法数，要求的是d[0][0]
    vector<vector<int>> d(m,vector<int>(n,0));
    for(int i=0;i<n;++i)
      d[m-1][i]=1;
    for(int i=0;i<m;++i)
      d[i][n-1]=1;
    for(int j=n-2;j>=0;--j)
      for(int i=m-2;i>=0;--i)
        d[i][j]=d[i+1][j]+d[i][j+1];
    return d[0][0];
  }
};
