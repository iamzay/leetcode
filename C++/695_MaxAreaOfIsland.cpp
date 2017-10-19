class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res=0,n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
        if(grid[i][j]==1){
          int cnt=0;
          dfs(grid,i,j,cnt);
          res=max(res,cnt);
        }
      }
    return res;
  }

private:
  bool notVisited(vector<vector<int>>& grid,int row,int col){
    int n=grid.size(),m=grid[0].size();
    if(row<0||row>=n||col<0||col>=m) return false;
    return grid[row][col]==1;
  }
  void dfs(vector<vector<int>>& grid,int row,int col,int &cnt){
    grid[row][col]='*';
    ++cnt;
    vector<pair<int,int>> dirs{{0,1},{0,-1},{-1,0},{1,0}};
    for(auto p:dirs){
      int x=row+p.first,y=col+p.second;
      if(notVisited(grid,x,y)) dfs(grid,x,y,cnt);
    }
  }
};
