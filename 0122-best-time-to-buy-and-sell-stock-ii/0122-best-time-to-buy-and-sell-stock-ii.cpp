class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalDays = prices.size();

        int yeshold = - prices[0];
        int yessold = 0;

        for ( int day = 1 ; day < totalDays ; ++ day ){
            int todaysold = max(yessold, yeshold + prices[day]);
            int todaybuy = max(yeshold, yessold - prices[day]);

            yeshold = todaybuy;
            yessold = todaysold;
        }

        return yessold;
    }
};