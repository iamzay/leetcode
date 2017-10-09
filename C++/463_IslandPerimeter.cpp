class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int res=0;
    int n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
        if(grid[i][j]){
          if(isWater(i-1,j,n,m,grid)) ++res;
          if(isWater(i,j-1,n,m,grid)) ++res;
          if(isWater(i+1,j,n,m,grid)) ++res;
          if(isWater(i,j+1,n,m,grid)) ++res;
        }
      }
    return res;
  }

private:
  bool isWater(int i,int j,int n,int m,vector<vector<int>> &grid){
    return i<0||i>=n||j<0||j>=m||!grid[i][j];
  }
};
