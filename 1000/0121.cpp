// 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for (int i=1; i<prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i]-min_price);
            min_price = min(min_price, prices[i]);
        }

        return max_profit;
    }
};
