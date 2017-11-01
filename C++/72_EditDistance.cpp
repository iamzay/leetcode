class Solution {
public:
  int minDistance(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    // d[i][j]:将word1[0~i-1]变成word2[0~j-1]所需最少步数
    vector<vector<int>> d(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;++i)
      for(int j=0;j<=m;++j){
        if(!i) d[i][j]=j;
        else if(!j) d[i][j]=i;
        else if(word1[i-1]==word2[j-1]) d[i][j]=d[i-1][j-1];
        else d[i][j]=1+min(min(d[i-1][j-1],d[i][j-1]),d[i-1][j]);
      }
    return d[n][m];
  }
};
