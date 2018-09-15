#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        // 每行的最大值
        vector<int> rowMax(n,0);
        // 每列的最大值
        vector<int> columnMax(n,0);

        for (int row = 0; row < n; ++row)
            for (int col = 0; col < n; ++col) {
                rowMax[row] = max(rowMax[row], grid[row][col]);
                columnMax[col] = max(columnMax[col], grid[row][col]);
            }
        
        int res = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                res += min(rowMax[row], columnMax[col]) - grid[row][col];
            }
        }

        return res;
    }
};