class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int hold = - prices[0];
        int free = 0 ;

        for ( int day = 1 ; day < n ; ++day ){
           int prehold = hold;
           int prefree = free;

           hold = max(prehold,prefree - prices[day]);
           free = max(prefree,prehold + prices[day] - fee);
        } 

        return free;
    }
};