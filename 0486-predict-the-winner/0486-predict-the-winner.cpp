class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores the max score difference (Current Player - Opponent) 
        // for the subarray nums[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: Subarray of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill DP table for lengths from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                int pickLeft = nums[i] - dp[i + 1][j];
                int pickRight = nums[j] - dp[i][j - 1];
                
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        // If score difference >= 0, Player 1 wins/ties
        return dp[0][n - 1] >= 0;
    }
};