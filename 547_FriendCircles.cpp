class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int cnt=0,n=M.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;++i){
      if(!visited[i]){
        ++cnt;
        dfs(M,visited,i);
      }
    }
    return cnt;
  }

private:
  void dfs(vector<vector<int>> &M,vector<bool> &visited,int cur){
    visited[cur]=true;
    for(int i=0;i<M.size();++i){
      if(M[i][cur]&&i!=cur&!visited[i])
        dfs(M,visited,i);
    }
  }
};

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int n=M.size();
    vector<int> heads(n,0);
    for(int i=0;i<n;++i)
      heads[i]=i;
    int cnt=n;
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j){
        if(M[i][j]){
          int i_head=find(heads,i);
          int j_head=find(heads,j);
          if(i_head!=j_head){
            heads[i_head]=j;
            --cnt;
          }
        }
      }
    return cnt;
  }

private:
  int find(vector<int> &heads,int i){
    return heads[i]==i?i:find(heads,heads[i]);
  }
};
