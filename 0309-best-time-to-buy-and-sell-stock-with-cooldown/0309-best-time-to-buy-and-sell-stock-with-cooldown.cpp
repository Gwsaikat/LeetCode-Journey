class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int yesterdayHolding = -prices[0];
        int yesterdaySold = 0;
        int yesterdayRest = 0;

        for ( int day = 1 ; day < n ; ++day ){
            int todayHolding = max(yesterdayHolding,yesterdayRest - prices[day]);
            int todaySold = yesterdayHolding + prices[day];
            int todayRest = max(yesterdaySold, yesterdayRest);

            yesterdayHolding = todayHolding;
            yesterdaySold = todaySold;
            yesterdayRest = todayRest;

        }

        return max(yesterdaySold,yesterdayRest);
    }
};