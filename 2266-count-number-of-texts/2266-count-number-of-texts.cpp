class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        int mod = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            char ch = pressedKeys[i - 1];
            
            int maxPresses = (ch == '7' || ch == '9') ? 4 : 3;

            for (int k = 1; k <= maxPresses && i - k >= 0; ++k) {
                if (pressedKeys[i - k] == ch) {
                    dp[i] = (dp[i] + dp[i - k]) % mod;
                } else {
                    break;
                }
            }
        }

        return dp[n];
    }
};