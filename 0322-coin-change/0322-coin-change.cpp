class Solution {
public:
    // A memoization table to store the minimum coins needed for a specific amount
    vector<int> memo;

    int solve(vector<int>& coins, int amount, int n) {
        // Base cases
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        
        if (memo[amount] != -2) return memo[amount];

        int min_coins = INT_MAX;

        for (int i = n - 1; i >= 0; --i) {
            int res = solve(coins, amount - coins[i], n);
            if (res != -1) {
                min_coins = min(min_coins, res + 1);
            }
        }

        memo[amount] = (min_coins == INT_MAX) ? -1 : min_coins;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.size() == 1 && coins[0] > amount) return -1;
        if (coins.size() == 1 && coins[0] < amount) {
            if (amount % coins[0] != 0) return -1;
            return amount / coins[0];
        }

        sort(coins.begin(), coins.end());
        int n = coins.size();

        memo.assign(amount + 1, -2);

        return solve(coins, amount, n);
    }
};