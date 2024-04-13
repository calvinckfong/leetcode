// 714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();

        int last[2] = {0, 0}; 
        int buy_profit, sell_profit;
        for (int i=n-1; i>=0; i--) 
        {
            buy_profit = -prices[i] + last[1];
            sell_profit = prices[i] - fee + last[0];
            // case bought=0, take the max of buy profit and hold profit
            last[0] = max(buy_profit, last[0]);
            // case bought=1, take the max of sell profit and hold profit
            last[1] = max(sell_profit, last[1]);
        }
        return last[0];
    }
};
