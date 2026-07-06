class Solution {
public:
    vector<vector<int>> dp;
    vector<int> points;

    int maxCoin(int st, int end) {
        if (st > end) return 0;

        if (dp[st][end] != -1) return dp[st][end];

        int maxCoins = 0;
        
        for (int splitpoint = st; splitpoint <= end; splitpoint++) {
            int coins = points[st - 1] * points[splitpoint] * points[end + 1];
            int totalCoin = coins + maxCoin(st, splitpoint - 1) + maxCoin(splitpoint + 1, end);

            maxCoins = max(maxCoins, totalCoin);
        }
        
        return dp[st][end] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        points.push_back(1);
        for (int num : nums) {
            points.push_back(num);
        }

        points.push_back(1);
        dp.assign(n + 2, vector<int>(n + 2, -1));
        
        return maxCoin(1, n);
    }
};