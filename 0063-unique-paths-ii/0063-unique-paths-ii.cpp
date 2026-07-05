class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> grid;

    int solve(int row, int col) {
        if (row < 0 || col < 0) return 0;
        if (grid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;
        
        if (dp[row][col] != -1) return dp[row][col];

        dp[row][col] = solve(row - 1, col) + solve(row, col - 1);
        
        return dp[row][col];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        dp.assign(row, vector<int>(col, -1));
        
        return solve(row - 1, col - 1);
    }
};