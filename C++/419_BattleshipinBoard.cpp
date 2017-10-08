class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    int n=board.size(),m=board[0].size();
    int res=0;
    vector<pair<int,int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
        if(board[i][j]=='X'){
          int x=i,y=j;
          for(auto dir:dirs){
            if(isBattleship(x+dir.first,y+dir.second,n,m,board)){
              while(isBattleship(x,y,n,m,board)){
                board[x][y]='*';
                x+=dir.first;
                y+=dir.second;
              }
            }
          }
          ++res;
        }
      }
    return res;
  }

private:
  bool isBattleship(int i,int j,int n,int m,vector<vector<char>>& board){
    return !(i<0||i>=n||j<0||j>=m||board[i][j]!='X');
  }
};
