class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> rollingrow(c);
        
        rollingrow[0] = grid[0][0];
        
        for (int col = 1; col < c; ++col) {
            rollingrow[col] = rollingrow[col-1] + grid[0][col];
        }
        
        for (int row = 1; row < r; ++row) {
            rollingrow[0] += grid[row][0];
            
            for (int col = 1; col < c; ++col) {
                rollingrow[col] = grid[row][col] + min(rollingrow[col-1], rollingrow[col]);
            }
        }
        
        return rollingrow[c - 1];
    }
};