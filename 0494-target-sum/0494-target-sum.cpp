class Solution {
public:
    int solve(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int total) {
        if (idx == nums.size()) {
            return sum == target;
        }
        if (dp[idx][sum + total] != -1) {
            return dp[idx][sum + total];
        }

        int res = solve(idx + 1, sum + nums[idx], nums, target, dp, total) + 
                  solve(idx + 1, sum - nums[idx], nums, target, dp, total);

        return dp[idx][sum + total] = res;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int s : nums) {
            total += s;
        }

        if (abs(target) > total) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        return solve(0, 0, nums, target, dp, total);
    }
};