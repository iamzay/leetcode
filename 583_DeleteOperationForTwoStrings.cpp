class Solution {
public:
  int minDistance(string word1, string word2) {
    int n1=word1.length(),n2=word2.length();
    if(!n1||!n2) return n1+n2;
    vector<vector<int>> d(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;++i)
      for(int j=0;j<=n2;++j){
        if(!i||!j) d[i][j]=0;
        else if(word1[i-1]==word2[j-1]) d[i][j]=1+d[i-1][j-1];
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
      }
    return n1+n2-2*d[n1][n2];
  }
};
