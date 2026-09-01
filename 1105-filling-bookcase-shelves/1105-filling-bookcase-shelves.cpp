class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); 
        dp[0] = 0; 

        for (int i = 1; i <= n; ++i) {
            int currwidth = 0;
            int currheight = 0;
            
            for (int j = i; j > 0; --j) {
                currwidth += books[j-1][0];
                if (currwidth > shelfWidth) break;
                
                currheight = max(currheight, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + currheight);
            }
        }
        return dp[n];
    }
};