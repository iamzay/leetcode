#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  bool isPosValid(pair<int,int> &pos,int n,int m){
    int x=pos.first,y=pos.second;
    if(x<0||x>=n||y<0||y>=m)
      return false;
    return true;
  }

  bool backtrace(vector<vector<char>>& board, string &word, int i,vector<vector<bool>> &visited,pair<int,int> cur,int m,int n){
    if(i>=word.length())
      return true;
    vector<pair<int,int>> dirs{{0,-1},{0,1},{1,0},{-1,0}};
    for(auto &dir:dirs){
      pair<int,int> next=make_pair(dir.first+cur.first,dir.second+cur.second);
      if(!isPosValid(next,n,m)||visited[next.first][next.second]||board[next.first][next.second]!=word[i])
        continue;
      visited[next.first][next.second]=true;
      if(backtrace(board,word,i+1,visited,next,m,n))
        return true;
      visited[next.first][next.second]=false;
    }
    return false;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    int n=board.size(),m=board[0].size();
    bool success=false;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
        if(board[i][j]==word[0]){
          visited[i][j]=true;
          if(backtrace(board,word,1,visited,make_pair(i,j),m,n)){
            success=true;
            break;
          }
          visited[i][j]=false;
        }
      }
    return success;
  }
};

class Solution1 {
private:
  bool _exist(vector<vector<char>> &board,string word,int i,int x,int y,int m,int n){
    if(i>=word.size())
      return true;
    if(x<0||y<0||x>=n||y>=m)
      return false;
    if(board[x][y]!=word[i])
      return false;
    board[x][y]='*';
    bool res=_exist(board,word,i+1,x+1,y,m,n)
      || _exist(board,word,i+1,x-1,y,m,n)
      || _exist(board,word,i+1,x,y+1,m,n)
      || _exist(board,word,i+1,x,y-1,m,n);
    board[x][y]=word[i];
    return res;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
        if(_exist(board,word,0,i,j,m,n))
          return true;
      }
    return false;
  }
};
