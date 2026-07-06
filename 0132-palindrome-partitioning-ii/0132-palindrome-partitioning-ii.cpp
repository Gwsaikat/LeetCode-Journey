class Solution {
public:
    vector<int> dp;
    vector<vector<int>> isPal;

    bool checkPalindrome(const string& s, int i, int j) {
        if (i >= j) return true;
        if (isPal[i][j] != -1) return isPal[i][j];
        
        return isPal[i][j] = (s[i] == s[j] && checkPalindrome(s, i + 1, j - 1));
    }

    int solve(const string& s, int i) {
        if (i >= s.length()) return 0;

        if (checkPalindrome(s, i, s.length() - 1)) return 0;
        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;
        
        for (int j = i; j < s.length(); ++j) {
            if (checkPalindrome(s, i, j)) {
                int currentCuts = 1 + solve(s, j + 1);
                minCuts = min(minCuts, currentCuts);
            }
        }
        
        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.length();
        
        dp.assign(n, -1);
        isPal.assign(n, vector<int>(n, -1));

        return solve(s, 0);
    }
};